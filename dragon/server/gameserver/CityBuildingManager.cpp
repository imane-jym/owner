/*
 * CityBuildingManager.cpp
 *
 *  Created on: Apr 15, 2014
 *      Author: long
 */

#include "CityBuildingManager.h"
#include "share/CommonConfig.h"
#include "Log.h"
#include "Handler.h"
uint32 calculateCoin(uint32 coin,uint32 rate,time_t makeCoinTime, uint32 coinLimit){
	time_t now = time(NULL);
	coin += (now - makeCoinTime) * rate;
	if(coin > coinLimit ){
		coin = coinLimit;
	}
	return coin;
}

CityBuildingManager::CityBuildingManager() {
	//initial city building map contain grid position,size etc..
}

bool CityBuildingManager::buildingInstance() {
	//role create init city buildings data from config data
	return true;
}

bool CityBuildingManager::init() {
	// get city building data from database
	std::string data;
	uint32 userId = 0;
	CDBCtrl::GetBuildingData(userId,data);
	ByteBuffer buffer;
	buffer.append(data.c_str(),data.size());
	DeSeriliazeDB(buffer);//

	//calculate coin
	time_t now = time(NULL);
	for(std::map<uint32, BuildingData>::iterator it = buildingData.begin();it != buildingData.end(); it ++){
		STC_CONF_BUILDING* buildingConf = CConfBuilding::find(it->second.buildingIndex);
		if(it->second.status == 0){//building does not upgrade
			uint32 coin = (now - it->second.makeCoinTime) * buildingConf->resourceAddPerHour;
			if (coin > buildingConf->resourceLimit) {
				it->second.coin = buildingConf->resourceLimit;
			} else {
				it->second.coin = coin;
			}
		}else{//building upgrade
			if (now - it->second.upgradeTime > buildingConf->upgradeTime) {	//upgrade finished
				uint32 coin = it->second.coin + (now - it->second.upgradeTime - buildingConf->upgradeTime) * buildingConf->resourceAddPerHour;
				if (coin > buildingConf->resourceLimit) {
					it->second.coin = buildingConf->resourceLimit;
				} else {
					it->second.coin = coin;
				}
				it->second.status = 0;
			} else {//upgrade not finished
				it->second.status = 1;
			}
		}
	}

	return true;
}

void CityBuildingManager::saveData() {
	//save city building data to database
	ByteBuffer by;
	SeriliazeDB(by);
	std::string data;
	data.assign((const char *)by.contents(), by.size());

	CDBCtrl::SaveBuildingData(0,data);

}

void CityBuildingManager::ontimeXs(int internal) {
	if(internal == TIMER_1S){
		//check status
		time_t now = time(NULL);
		for(std::map<uint32, BuildingData>::iterator it = buildingData.begin();it != buildingData.end(); it ++){
			STC_CONF_BUILDING* buildingConf = CConfBuilding::find(it->second.buildingIndex);
			if (buildingConf == NULL) {
				IME_ERROR("build %u does not exist",it->second.buildingIndex);
				continue;
			}
			if( it->second.status == 1 && (now - it->second.upgradeTime) > buildingConf->upgradeTime){
				it->second.status = 0;
				it->second.makeCoinTime = time(NULL);
			}
		}
	}else if(internal == TIMER_3MIN){
		saveData();
	}
}

void CityBuildingManager::handlerUpgradeBuilding(uint32 buildingIndex,uint32 type) {
	//normal upgrade
	BuildingData* data = &(buildingData.find(buildingIndex)->second);
	if (data == NULL) {
		IME_ERROR("request building index not exist");
		return;
	}
	STC_CONF_BUILDING* buildingConf = CConfBuilding::find(data->buildingIndex);
	if (buildingConf == NULL) {
		return;
	}
	if(type == 0){
		// is full level
		if (buildingConf->nextIndex == 0) {
			//upgrade full level
			return;
		}
		// find next level building index
		STC_CONF_BUILDING* nextData = CConfBuilding::find(
				buildingConf->nextIndex);
		if (nextData == NULL) {
			return;
		}

		//扣除升级需要的资源数
		if(buildingConf->consumeType == COIN){
			// 扣除金币
			if(buildingConf->number > 500){
				//have no enough coin
				return;
			}
			//扣除

		}else if(buildingConf->consumeType == DIAMOND ){
			//扣除钻石
			if(buildingConf->number > 500){
				//have no enough diamond
				return;
			}
		}

		//upgrade
		BuildingData nextBuild;
		nextBuild.buildingIndex = nextData->buildingIndex;
		nextBuild.x = data->x;
		nextBuild.y = data->y;
		nextBuild.makeCoinTime = data->makeCoinTime;
		nextBuild.upgradeTime = time(NULL);
		nextBuild.coin = calculateCoin(nextBuild.coin,buildingConf->resourceAddPerHour,nextBuild.makeCoinTime,buildingConf->resourceLimit);
		//删除升级前的building
		buildingData.erase(buildingData.find(data->buildingIndex));
		buildingData.insert(std::make_pair(nextData->buildingIndex,nextBuild));
	}else if(type == 1){

		if(buildingConf->immediateFinishDollar > 300){
			// have no enough diamond
			return;
		}
		// minus diamond

		//reset status make coin status
		data->status = 0;

		//reset make coin time
		data->makeCoinTime = time(NULL);
	}
}

void CityBuildingManager::handlerGetGold(uint32 buildingIndex) {
	BuildingData* data = &(buildingData.find(buildingIndex)->second);
	if (data == NULL) {
		IME_ERROR("request building index not exist");
		return;
	}

	STC_CONF_BUILDING* buildingConf = CConfBuilding::find(data->buildingIndex);
	if (buildingConf == NULL) {
		return;
	}
	uint32 coin = calculateCoin(data->coin,buildingConf->resourceAddPerHour,data->makeCoinTime,buildingConf->resourceLimit);
	data->coin = 0;
	data->makeCoinTime = time(NULL);

	//add coin to role

	//role property notify

	//send response message

}

void CityBuildingManager::handlerCreateBuilding(uint32 buildingIndex, uint32 x, uint32 y) {
	BuildingData building;
	building.buildingIndex = buildingIndex;
	building.makeCoinTime = time(NULL);
	building.x = x;
	building.y = y;
	building.upgradeTime = time(NULL);
	building.coin = 0;
	building.status = 0;
	//judge position is or not use

	//create
	buildingData.insert(std::make_pair(building.buildingIndex,building));

	// response message

}

void CityBuildingManager::SeriliazeDB(ByteBuffer& by) {
	by << buildingData.size();
	for(std::map<uint32,BuildingData>::iterator it = buildingData.begin(); it != buildingData.end(); it++){
		by << it->second.buildingIndex;
		by << it->second.x;
		by << it->second.y;
		by << it->second.coin;
		by << it->second.makeCoinTime;
		by << it->second.status;
		by << it->second.upgradeTime;
	}
}

void CityBuildingManager::DeSeriliazeDB(ByteBuffer& by) {
	uint32 size;
	by >> size;
	for(uint32 i = 0; i < size; i++){
		BuildingData building;
		by >> building.buildingIndex;
		by >> building.makeCoinTime;
		by >> building.x;
		by >> building.y;
		by >> building.upgradeTime;
		by >> building.coin;
		by >> building.status;

		buildingData.insert(std::make_pair(building.buildingIndex,building));
	}

}

CityBuildingManager::~CityBuildingManager() {}

void CityBuildingManager::handlerBuildingDataPush() {

	for(std::map<uint32,BuildingData>::iterator it = buildingData.begin(); it != buildingData.end(); it++){
		//send all building data
	}
}
