#!/bin/bash
#set -x

user=root
psd=mysql@ime
db=hero_login
loginserver=61.153.99.130
ver=2.4.0

echo "input version:(2.4.0)"
read ver

echo "input start date:(2013-01-01)"
read Date_start

echo "input end date:(2013-01-01)"
read Date_end

echo "====================================================
	1.Sell Item        (卖出物品)
	2.Use Item    	   (使用物品)
        3.Delete Hero	   (英雄消耗)
        4.Delete Euip      (装备消耗）
	5.DoLotteryWheel   (幸运转盘)
	6.NiuDanNew        (召唤)
	7.SpendResource    (资源消耗：金钱90001 钻石90003等）
	8.GetResource      (获取资源)
	9.BuyFund          (购买基金)
	10.GetFundReward   (基金奖励)
        11.GetMailReward   (邮件领取奖励)	
	12.GetFanLiReward  (领取充值返利)
        13.Accept Quest    (接受试炼任务)
	14.BuyCommodity    (购买商品)
	15.ChargeOrSpendActivity (充值活动)
        16.CombineItem     (合成物品)
	17.ComposeHero     (英雄融合)	
	18.DoExchange      (兑换活动)
	19.Get Quest Reward(获取任务奖励)
	20.Remove Item     (物品消耗)
	21.AddItem         (增加物品)
	22.Collect         (征收)
	23.VIP成就(英雄冲锋 一骑当先...)
	24.全服聊天记录
	25.Delete Jewel    (首饰消耗）
	999. custome	   (自定义字符串)
====================================================
"
echo "input the NO. which you want to do:  (1) (1 20001). Special 999 (custom_string para2) para2:可以为空或者 (-A -B -C) 后面跟数字表达 向下 向上 向上向下 多少行"
read index

mysql -u$user -p$psd $db -N -e "select concat(ip,',',server_id) from gameserver_info where version='$ver'" > serverlist
#echo "$server_ip"

#str='g10.imobile-ent.com,11'
#str='60.191.205.37,126'
#str='g13.imobile-ent.com,160'
rm -f all_data
for i in `cat serverlist` #$str
do
	server_ip=`echo $i | cut -d ',' -f 1`
	server_id=`echo $i | cut -d ',' -f 2`
echo "server is ip $server_ip, id $server_id" | tee -a all_data
roleId='.'
#Date_start=2014-07-18
#Date_end=2014-07-19
#server_id=11
#index="21 30115 .00"

usr=wuqi
cmd="~/grep.sh $roleId $Date_start $Date_end $server_id $index"
pwd=ime@kefu
expect -c "set timeout -1
        spawn scp -q -o StrictHostKeyChecking=no ./grep.sh $usr@$server_ip:~/;
        expect { 
			*assword:* {
				send -- $pwd\r;
				expect {
					*denied* {exit 2;}
					eof
				}
			}
			eof {exit 1;}
		}
" | tee -a all_data
expect -c "set timeout -1
        spawn ssh -o StrictHostKeyChecking=no $usr@$server_ip \"$cmd\";
        expect { 
			*assword:* {
				send -- $pwd\r;
				expect {
					*denied* {exit 2;}
					eof
				}
			}
			eof {exit 1;}
		}
" | tee -a all_data
echo "=====================================================" | tee -a all_data
done
