#ifndef _CMD_DEFINE_H
#define _CMD_DEFINE_H

//命令定义规范
//奇数为 Client 发送到 Server 
//偶数为 Server 发送到 Client
#define CMD_MAKE_CLIENT(v)			(((v)<<1)|0x0001)
#define	CMD_MAKE_SERVER(v)			((v)<<1)
#define CMD_IS_CLIENT(v)			(((v)&0x0001)==0x0001)
#define CMD_IS_SERVER(v)			(((v)&0x0001)==0x0000)

//Client 发送到 Server的命令
#define CMD_CS_TEST					CMD_MAKE_CLIENT(0x0001) //测试用 echo{string发送字符串}
//#define CMD_CS_AUTH					CMD_MAKE_CLIENT(0x0002) //客户端请求认证{string account,string pwd,string version}
#define CMD_CS_GM_CMD			CMD_MAKE_CLIENT(0x0003) //GM命令{string}
//#define CMD_CS_LOGIN          CMD_MAKE_CLIENT(0x0004) //客户端登录 {std::string uid(不关心), uint32版本号 string name  string pwd uint16 channel, uint16 serverid}
//#define CMD_CS_FASTLOGIN      CMD_MAKE_CLIENT(0x0005) //客户端登快速登录 {std::string uid, uint32版本号 string name(不关心)  string pwd uint16 channel, uint16 serverid}
#define CMD_CS_OTHERLOGIN        CMD_MAKE_CLIENT(0x0006) //第三方客户端登录 {std::string uid(不关心), uint32版本号 string name  string pwd uint16 channel, uint16 serverid, uint8 flag, string token}
//#define CMD_CS_CHANGE_PWD        CMD_MAKE_CLIENT(0x0007) //修改密码 {std::string oldpwd, std::string newpwd}
#define CMD_CS_INIT_ROLE        CMD_MAKE_CLIENT(0x0008) //初始化角色信息 {std::string username}
#define CMD_CS_STR_DIRTY_CHECK_REQUEST                       CMD_MAKE_CLIENT(0x0009) //用户名字检测请求, 包含脏词和重名{strig str}

#define CMD_CS_WORLD_BROADCAST_REQUEST                       CMD_MAKE_CLIENT(0x000a) //好友聊天请求{uint8 choose(0:普通聊天, 1:使用小喇叭聊天, 详情查看ROLE_CHAT), string content, uint32 userid(私聊有意义)}
#define CMD_CS_HEARTBEAT                        CMD_MAKE_CLIENT(0x000b) //服务心跳包 {uint32 timestamp}
#define CMD_CS_STATICS_DATA                        CMD_MAKE_CLIENT(0x000c) //数据统计请求 {为了统计 std::string reg_device(首次登陆设备), std::string reg_device_type(首次登陆设备型号), std::string second_channel, std::string uid}
#define CMD_CS_EQUIP_OPT                        CMD_MAKE_CLIENT(0x000d) // 更换装备 {uint8 professsion pos(POS_PROFESSION 0-3), uint8 pos(POS_EQUIPMENT, 0-6), uint32 itemobjid}
#define CMD_CS_HERO_CHANGE                        CMD_MAKE_CLIENT(0x000e) // 更换英雄造型 {uint8 professsion pos(POS_PROFESSION 0-3), uint16_t avatarhair, uint16_t avatareye, uint16_t avatarnose, uint16_t avatarmouth}
#define CMD_CS_ITEM_COMBINE                        CMD_MAKE_CLIENT(0x000f) // 合成英雄装备 {uint32 index}
#define CMD_CS_TASK_COMBAT_PREVIEW                        CMD_MAKE_CLIENT(0x0010) // 关卡预览 {uint32 index}
#define CMD_CS_TASK_COMBAT                        CMD_MAKE_CLIENT(0x0011) // 关卡战斗 {uint32 index, uint8 result(0胜利 1:失败) 校检数据(暂时为空)}

//////////////////////////////////////////////////////////////////////////
//Server 发送到 Client的命令
#define CMD_SC_TEST					CMD_MAKE_SERVER(0x0001) //测试用 echo 服务器返回{string返回字符串;}
#define CMD_SC_AUTH_RESULT			CMD_MAKE_SERVER(0x0002) //服务器认证返回信息{uint16返回结果;}0认证通过，其他失败。应该包括多种失败信息，详细见EnumDefine 注意一个错误码 ERRNO_MSG_AUTH_TOKEN 该错误表面, 该token 失效,需要重新登录发送token字段为字符串
#define CMD_SC_ERROR_MSG			CMD_MAKE_SERVER(0x0003) //uint16 ErrorMsgNum
#define CMD_SC_ROLE_PROPERTY		CMD_MAKE_SERVER(0x0005) //角色属性更新{
//uint32 角色ID
//string 账号ID
//string 角色名
//uint16 角色等级
//uint32 exp
//uint32 vip lv
//uint32 vip 总exp
//uint64 dollar
//uint64 coin
//uint32 Energy 
//uint8 状态
//uint32 任务位置
//string 登录识别token
//uint32 下一点精力回复时间计时
//uint32 全部精力回复计时
//uint32 explimit
//}
#define CMD_SC_ERROR_STR			CMD_MAKE_SERVER(0x0006)	//错误字符串信息 {string strMsg}
#define CMD_SC_MSG_STR			CMD_MAKE_SERVER(0x0007)	//字符串信息GM test命令等 {string strMsg}
#define CMD_SC_CHANGE_PWD_RESULT        CMD_MAKE_SERVER(0x0008) //修改密码 {uint16 status}
#define CMD_SC_INIT_ROLE_RESULT        CMD_MAKE_SERVER(0x0009) //初始化角色信息回包 {uint16 status}
#define CMD_SC_STR_DIRTY_CHECK_RESULT                       CMD_MAKE_SERVER(0x000a) //脏词检测请求{uint16 status}
#define CMD_SC_GLOBAL_INFO                       CMD_MAKE_SERVER(0x000b) //全局信息{}
#define CMD_SC_BROAD_CAST		CMD_MAKE_SERVER(0x000c) //{
// uint16 type, 
// SYS_BROAD_DIY: string content
#define CMD_SC_WORLD_BROADCAST_RESULT                       CMD_MAKE_SERVER(0x000d) //好友聊天请求{uint16 status}
#define CMD_SC_WORLD_BROADCAST_INFO                      CMD_MAKE_SERVER(0x000e) //聊天相关信息推送{uint8 choose, uint32 userid(0:系统), string username, string content, uint16 viplv}
#define CMD_SC_HEARTBEAT                        CMD_MAKE_SERVER(0x000f) //服务心跳包 {uint32 timestamp}
#define CMD_SC_ANNOUNCEMENT_INFO                       CMD_MAKE_SERVER(0x0010) //公告信息拉取{uint16 number [string str1,...]} 
#define CMD_SC_CLOSE_CONNECT                        CMD_MAKE_SERVER(0x0011) //服务要断开连接 {}
#define CMD_SC_ROLE_ITEM_PACKET_INFO		CMD_MAKE_SERVER(0x0012) 
/*角色道具背包数据拉取
{
    uint32 number 总道具数量
    [
        {
			uint32 objid,
			uint32 number
			uint16 type,
			uint32 index,
			ITEM_WEAPON, ITEM_ARMOR, ITEM_SHOE, ITEM_HEAD, ITEM_WING, ITEM_CLOAK
			{// 
				//uint16 进阶等级
				//uint16 星级
				//uint16 使用等级
				//uint16 职业限制
				//uint32 attack,
				//uint32 攻击成长率
				//uint32 defence,
				//uint32 防御成长率
				//uint32 strength 
				//uint32 体力成长率
				//uint32 生命恢复
				//uint32 生命恢复成长率
				//uint32 能量恢复
				//uint32 能量恢复成长率
				//uint32 攻击速度
				//uint32 攻击耗时
				//uint32 闪避
				//uint32 暴击率
				//uint32 暴击值
				//uint32 命中
				//uint32 吸血
			}
			ITEM_CONSUME, ITEM_COMBINE
			{// 当前为空
			}
        }
        ...
    ]
}
*/
#define CMD_SC_ROLE_ITEM_PACKET_CHANGE		CMD_MAKE_SERVER(0x0013) 
/*
角色道具背包更新
{
    uint32 number //操作数量
    [
        {
            uint8 cmd   //操作命令， 0：添加 1：删除
            0 添加
            {
				uint32 objid,
				uint32 number
				uint16 type,
				uint32 index,
				和CMD_SC_ROLE_ITEM_PACKET_INFO一样 分类型数据结构
            }
            1 删除
			{
            	uint32 objid
				uint32 number
			}
        }
        ....
    ]
}
*/
#define CMD_SC_PRODUCT_GET_INFO					CMD_MAKE_SERVER(0x0014) 
// {type uint16, 
//PRODUCT_GET: 
//uint32 number, [{uint32 type, uint32 para1, uint32 para2(参考E_EFFECT)} ... ]}
//COMBAT_RESULT:
//uint8 result(0:胜利 1:失败)
//uint32 number, [{uint8 pos, uint16 lv, uint32 exp, uint32 explimit, uint16 newlv, uint32 newexp, uint32 newexplimit} ... ]
//uint32 coin;
//uint32 RoleExp;
//uint32 heroexp;
//uint16 lv;
//uint32 exp;
//uint16 newlv;
//uint32 newexp;
#define CMD_SC_EQUIP_OPT_RESULT                        CMD_MAKE_SERVER(0x0015) // 更换装备和技能结果 {uint16 status}
#define CMD_SC_EQUIP_INFO                        CMD_MAKE_SERVER(0x0016) // 装备属性 {uint32 number 
//[{uint8 pos_profession, 
//uint32 number(数量小于等于POS_EQUIP_MAX)
// [uint32 objid ... ](0表示无装备),
// uint32 attack_self,
// uint32 defence_self,
// uint32 strength_self
// uint32 heal_self,
// uint32 power_self,
// uint32 attackspeed_self,
// uint32 attacktime_self,
// uint32 dodge_self,
// uint32 crit_self,
// uint32 critpower_self,
// uint32 hit_self,
// uint32 suckblood_self
//
// uint32 attack_equip,
// uint32 defence_equip,
// uint32 strength_equip
// uint32 heal_equip,
// uint32 power_equip,
// uint32 attackspeed_equip,
// uint32 attacktime_equip,
// uint32 dodge_equip,
// uint32 crit_equip,
// uint32 critpower_equip,
// uint32 hit_equip,
// uint32 suckblood_equip
// uint32 战力
// } ... ]
// uint32 总战力}
#define CMD_SC_HERO_INFO                        CMD_MAKE_SERVER(0x0017) // 英雄属性 {uint32 number 
//[{uint8 pos_profession, 
//
//uint32 objid (作为唯一标示一个英雄用)
//uint32 index 角色index
//uint16 头发部件
//uint16 眼睛部件
//uint16 鼻子部件
//uint16 嘴巴部件
//uint32 exp
//uint16 level
//
//uint16 战斗位置
//uint16 职业
//uint32 exp成长率
//uint16 等级上限
// uint32 attack,
// uint32 攻击成长率
// uint32 defence,
// uint32 防御成长率
// uint32 strength 
// uint32 体力成长率
// uint32 生命恢复
// uint32 生命恢复成长率
// uint32 能量恢复
// uint32 能量恢复成长率
// uint32 攻击速度
// uint32 攻击耗时
// uint32 闪避
// uint32 暴击率
// uint32 暴击值
// uint32 命中
// uint32 吸血
// uint32 normalskill
// uint32 explimit
// } ... ]}
#define CMD_SC_HERO_CHANGE_RESULT                        CMD_MAKE_SERVER(0x0019) // 更换装备结果 {uint16 status}
#define CMD_SC_ITEM_COMBINE_RESULT                        CMD_MAKE_SERVER(0x001a) // 合成英雄装备结果 {uint16 status, uint32 index}
#define CMD_SC_TASK_COMBAT_PREVIEW_RESULT                        CMD_MAKE_SERVER(0x001b) // 关卡预览 {uint16 status, 
// uint32 index
// uint32 number
// [{uint32 index(道具index), uint32 number} ... ] 关卡首次掉落
// uint32 coin 每个怪掉落金钱 
// uint32 totalcoin 总金钱 (有可能配的不可以整除 总金额会比算出来多一点 最后一次结算以这个为准)
// uint32 npc number
// {
// 		uint16 批次号;
// 		uint32 npc objid;
// 		uint32 npc index;	
// 		uint16 位置;
// 		uint16 lv;
// 		uint32 attack;
// 		uint32 defence;
// 		uint32 health;
// 		uint32 index; 掉落道具ID (0 表示没有掉落)
// 		uint32 number; 掉落数量
// 		uint32 普通攻击 index
// }
// }
// status: ERRNO_MSG_NOT_ENOUGH_ENERGY
// {
// uint16 status
// uint32 下一点回复时间
// uint32 全部回复时间
// }
#define CMD_SC_TASK_COMBAT_RESULT                        CMD_MAKE_SERVER(0x001c) // 关卡战斗 {uint16 status, uint8 result}
// status: ERRNO_MSG_NOT_ENOUGH_ENERGY // 正常情况下 先发preview(preview会判断这个错误) 再发这个 不可能发生这种错误码的 可以忽略这个
// {
// uint16 status
// uint32 下一点回复时间
// uint32 全部回复时间
// }
#define CMD_SC_TASK_INFO                        CMD_MAKE_SERVER(0x001d) // 关卡数据 {uint32 number [{uint32 index, uint16 number, uint32 CD} ... ]}

//////////////////////////////////////////////////////////////////////////
//命令定义规范
//奇数为 Client 发送到 Server 
//偶数为 Server 发送到 Client
//Client 发送到 LoginServer
#define CMD_LOGIN_CS_TEST           CMD_MAKE_CLIENT(0x0001) //测试用 echo{string发送字符串}
#define CMD_LOGIN_CS_SERVER_LIST         CMD_MAKE_CLIENT(0x0002) //客户端91获取服务器列表{uint8 flag, 1:GM版拉取会获取，禁止登录的服务器, 0:正常拉取}
//#define CMD_LOGIN_CS_PATCH_URL         CMD_MAKE_CLIENT(0x0003) //客户端获取下载地址{uint32 version}
#define CMD_LOGIN_CS_REG            CMD_MAKE_CLIENT(0x0004) //客户端注册 {std::string account, uint16 channel,string pwd, string mail}       
#define CMD_LOGIN_CS_LOGIN          CMD_MAKE_CLIENT(0x0005) //客户端登录 {std::string uid(不关心), uint32版本号 string name  string pwd uint16 channel}
#define CMD_LOGIN_CS_FASTLOGIN      CMD_MAKE_CLIENT(0x0006) //客户端登快速登录 {std::string uid, uint32版本号 string name(不关心)  string pwd uint16 channel}
#define CMD_LOGIN_CS_OTHERLOGIN        CMD_MAKE_CLIENT(0x0007) //第三方客户端登录 {std::string uid(统计用), uint32版本号 string name  string pwd uint16 channel, (为了统计string mail, string token, std::string reg_device(首次登陆设备), std::string reg_device_type(首次登陆设备型号), std::string second_channel, uint16 area_id, uint8 flag}
#define CMD_LOGIN_CS_VERSION_NEED        CMD_MAKE_CLIENT(0x0008) //要求最低版本 {}
#define CMD_LOGIN_CS_AD        CMD_MAKE_CLIENT(0x0009) //要求最低版本 {uint32 version}
#define CMD_LOGIN_CS_SERVER_LIST2         CMD_MAKE_CLIENT(0x0010) //客户端91获取服务器列表{uint8 flag, 1:GM版拉取会获取，禁止登录的服务器, 0:正常拉取}

//////////////////////////////////////////////////////
//LoginServer 发送到 Client的命令
#define CMD_LOGIN_SC_TEST                   CMD_MAKE_SERVER(0x1001) //测试用 echo 服务器返回{string返回字符串;}                    
#define CMD_LOGIN_SC_SERVER_LIST        CMD_MAKE_SERVER(0x1002)     //服务器列表{uint16 number [{uint8 IsAlive, uint16 服务器ID， string ip, uint32 port, uint32 version, uint8 status(E_AREA_STATUS_STOP ...), uint8 是否是新服, string servername, string domain}...], string 登录通知} 
//#define CMD_LOGIN_SC_PATCH_URL                  CMD_MAKE_SERVER(0x1003) //服务器返回{uint32 version, string返回patch url字符串, string 广告一类的url字符串, string 增量url字符串}
#define CMD_LOGIN_SC_REGRESULT              CMD_MAKE_SERVER(0x1004) //注册返回 uint16 结果 string name string pwd                   
#define CMD_LOGIN_SC_LOGINRESULT            CMD_MAKE_SERVER(0x1005) //登录返回 uint16 结果                       
#define CMD_LOGIN_SC_FASTRESULT            CMD_MAKE_SERVER(0x1006) //登录返回 uint16 结果                       
#define CMD_LOGIN_SC_OTHERRESULT            CMD_MAKE_SERVER(0x1007) //登录返回 uint16 结果                       
#define CMD_LOGIN_SC_VERSION_NEED_RESULT            CMD_MAKE_SERVER(0x1008) // 版本检测结果{uint32 version (要求最低版本)}                      
#define CMD_LOGIN_SC_AD_RESULT            CMD_MAKE_SERVER(0x1009) // 公告结果{uint32 number [string desc ... ]}                      
#define CMD_LOGIN_SC_SERVER_LISTV2        CMD_MAKE_SERVER(0x100a)     //服务器列表{uint16 number [{uint8 IsAlive, uint16 服务器ID， string ip, uint32 port, uint32 version, uint8 status(E_AREA_STATUS_STOP ...), uint8 是否是新服, string servername, string domain, string patch url}...], string 登录通知} 
#endif
