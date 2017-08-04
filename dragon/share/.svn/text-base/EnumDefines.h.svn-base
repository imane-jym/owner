#ifndef _ENUM_DEFINES_H
#define _ENUM_DEFINES_H

//各种enum值的定义
#define INNER_VERSION 8

#define RESOURCE_DOWNLOAD_NAME "res"
#define AD_DOWNLOAD_NAME "ad"
#define EXTRA_RESOURCE_DOWNLOAD_NAME "resextra"

#define PLAYER_INIT_ID 10001
#define ROBOT_INIT_ID 1000

#define IS_ROBORT(userid) ((userid >> 8) < PLAYER_INIT_ID && (userid >> 8) > ROBOT_INIT_ID)

#define CHANNEL_MIN 750
#define CHANNEL_MAX 800

#define CHANNEL_MIN2 10001
#define CHANNEL_MAX2 20000

#define CHANNEL_MIN3 40001
#define CHANNEL_MAX3 50000

#define IS_LIMIT_LOGIN(status) (status & 0x1)
#define SET_YES_LIMIT_LOGIN(status) (status | 0x1)
#define SET_NO_LIMIT_LOGIN(status) (status & 0xfe)

#define IS_GM(status) (status & 0x2)
#define SET_YES_GM(status) (status | 0x2)
#define SET_NO_GM(status) (status & 0xfd)

#define E_MAX_USERNAME_PWD_LEN        64         //用户名和密码的最大长度

#define FIRST_HERO 1
#define SECOND_HERO 2
#define THIRD_HERO 3
#define FORTH_HERO 4

//登陆反馈信息
typedef enum _E_ERRNO_AUTH
{
}E_ERRNO_AUTH;

enum
{
	E_AREA_STATUS_STOP		,//维护
	E_AREA_STATUS_GOOD = 1	,//良好
	E_AREA_STATUS_BUSY		,//拥挤
	E_AREA_STATUS_FULL		,//火爆
};

enum
{
	CURRENCY_CNY = 99001,
	CURRENCY_USD = 99002,
	CURRENCY_TWD = 99003,
	CURRENCY_HKD = 99004
};

enum
{
	DB_GLOBAL_NOTICE = 1,
	DB_GLOBAL_CHAT = 2,
	DB_GLOBAL_WHITE_LIST = 3,
	DB_GLOBAL_SERVER_OPERATIONS = 99,
};

enum E_PROPERTY_RESOURCE
{
	RES_COIN = 1,
	RES_DOLLAR = 2,
	RES_VIP_EXP = 3,
	RES_ROLE_EXP = 4,
	RES_HERO_EXP = 5,
};

enum
{
	SYS_BROAD_DIY
};

typedef enum ROLE_CHAT
{
	NORMAL_WORLD_CHAT = 0,
	TRUMPET_WORLD_CHAT = 1,
	SYS_CHAT = 2,
	PRIVATE_CHAT = 3,
	GROUP_CHAT = 4,
}ROLE_CHAT;

// 资源物品变更来源
enum
{
	SOURCE_GM,
	SOURCE_COMBINE,
	SOURCE_TASK,
};

//钻石消费类别Id
typedef enum _E_DOLLAR_CHANGE {       
	E_DC_CHARGE,                                
	E_DC_GM_GIVE,                                    
	E_DC_GIVE,                                  
	E_DC_STORE,                                 
	E_DC_GM_DEL,
}E_DOLLAR_CHANGE;

enum E_OBJ/* game product type(用于发送物品 资源) */
{
	PROPERTY = 1,                               /* type, para1 index(E_PROPERTY_RESOURCE) para2 number*/
	ITEM,                                       /* type, para1 index para2 number */
};

enum E_EFFECT/* game product type(用于客户端做表现) */
{
	EFFECT_PROPERTY = 1,                        /* type, para1 index(E_PROPERTY_RESOURCE) para2 number*/
	EFFECT_ITEM,                                /* type, para1 index, para2 number */
};

enum
{
	PRODUCT_GET = 1,
	COMBAT_RESULT,
};

#define INIT_VIP_LEVEL 0

enum POS_EQUIPMENT
{
	POS_EQUIP_HEAD = 0,
	POS_EQUIP_ARMOR = 1,
	POS_EQUIP_SHOE = 2,
	POS_EQUIP_WEAPON = 3,
	POS_EQUIP_CLOAK = 4,
	POS_EQUIP_WING = 5,
	POS_EQUIP_SKILL = 6,
	POS_EQUIP_MAX
};

enum POS_PROFESSION
{
	POS_PRO_SOLDIER = 0,
	POS_PRO_ARCHER = 1,
	POS_PRO_MASTER = 2,
	POS_PRO_POET = 3,
	POS_PRO_MAX
};

enum ITEM_TYPE
{
	ITEM_NONE,
	ITEM_CONSUME,
	ITEM_COMBINE,
	ITEM_WEAPON,
	ITEM_ARMOR,
	ITEM_SHOE,
	ITEM_HEAD,
	ITEM_WING,
	ITEM_CLOAK
};

#define GET_UPGRADE_COMBINE_ID(lv, index) index * 10000 + lv

enum TASK_TYPE
{
	MAIN_TASK = 1,
	BRANCH_TASK = 2
};

#endif
