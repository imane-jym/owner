/*
 * GmCmdPro.h
 *
 *  Created on: 2011-6-23
 *      Author: yq
 */

#ifndef GMCMDPRO_H_
#define GMCMDPRO_H_

#include <string>
#include <vector>
#include <map>


class CRole;

class CGmCmdPro
{
public:
	typedef void (*FUNC_GM_CMD) (CRole *pRole, const std::vector<std::string> & vecPara);
	typedef std::map<std::string, FUNC_GM_CMD> MAP_FUNC_GM_CMD;

	static void Init();
	static void PraseCmd(CRole *pRole, const std::string & strContent);
	//////////////////////////////////////////////
	static void Test(CRole *pRole, const std::vector<std::string> & vecPara);
	static void Level(CRole *pRole, const std::vector<std::string> &vecPara);
	static void AddExp(CRole *pRole, const std::vector<std::string> &vecPara);
	static void AddEnergy(CRole *pRole, const std::vector<std::string> &vecPara);
	static void AddCoin(CRole *pRole, const std::vector<std::string> &vecPara);
	static void AddDollar(CRole *pRole, const std::vector<std::string> &vecPara);
	static void VipLvUp(CRole *pRole, const std::vector<std::string> &vecPara);
	static void AddVipexp(CRole *pRole, const std::vector<std::string> &vecPara);
	static void Charge(CRole *pCRole, const std::vector<std::string> &vecPara);
	static void LimitRole(CRole *pRole, const std::vector<std::string> &vecPara);
	static void Hero(CRole *pRole, const std::vector<std::string> &vecPara);

private:
	CGmCmdPro();
	~CGmCmdPro();

	static MAP_FUNC_GM_CMD m_mapGmFuncs;
};

#endif /* GMCMDPRO_H_ */
