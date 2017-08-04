/*
 * CityBuildingManager.h
 *
 *  Created on: Apr 15, 2014
 *      Author: long
 */

#ifndef CITYBUILDINGMANAGER_H_
#define CITYBUILDINGMANAGER_H_

#include <map>

uint32 calculateCoin(uint32 coin,uint32 rate,time_t makeCoinTime, uint32 coinLimit);

class CityBuildingManager {
public:
	typedef struct _BuildingData{
		uint32 buildingIndex;
		uint32 x;
		uint32 y;
		uint32 makeCoinTime;//product coins start time
		uint32 upgradeTime;//upgrade start time
		uint32 status;//1:upgrading status 0:product coin status
		uint32 coin;//record product coins
	}BuildingData;

	enum ResourceType{
		COIN,
		DIAMOND,
	};

	CityBuildingManager();
	//role first create call it
	bool buildingInstance();
	// role login call
	bool init();
	void saveData();
	void ontimeXs(int internal);
	void SeriliazeDB(ByteBuffer &by);
	void DeSeriliazeDB(ByteBuffer &by);


	//request CMD_CS_UPGRADE_BUILDING {uint32 buildingIndex,uint32 type(0:normal upgrade,1:immediate upgrade)}
	//response CMD_SC_UPGRADE_BUILDING_RESULT {uint8 status(0:success,other:errorCode),uint32 buildingIndex,uint32 upgradeTime}
	void handlerUpgradeBuilding(uint32 buildingIndex,uint32 type);

	//CMD_CS_GET_RESOURCE {uint32 buildingIndex, uint32 type(0:coin)}
	//CMD_SC_GET_RESOURCE_RESULT {uint8 status(0:success,other:errorCode),uint32 buildingIndex}
	void handlerGetGold(uint32 buildingIndex);

	//request CMD_CS_CREATE_BUILDING {uint32 buildingIndex,uint32 x,uint32 y}
	//response CMD_SC_CREATE_BUILDING_RESULT {uint8 status(0:success,other:errorCode),uint32 buildingIndex}
	void handlerCreateBuilding(uint32 buildingIndex, uint32 x, uint32 y);

	// building data push
	//CMD_CS_BUILDING_INFO {uint32 userId}
	//CMD_SC_BUILDING_INFO_RESULT {uint32 number [uint32 buildingIndex, uint32 x, uint32 y, uint32 makeCoinTime,uint32 status,uint32 coin
	//,uint32 rate,uint32 coinLimit,uint32 upgradeTime,uint32 upgradeNeedTime ...]}
	void handlerBuildingDataPush();

	virtual ~CityBuildingManager();

private:
	//buildings map
	std::map<uint32, BuildingData> buildingData;


};

#endif /* CITYBUILDINGMANAGER_H_ */
