#!/bin/bash
echo "roleid=$1"
echo "Date_start=$2"
echo "Date_end=$3"
echo "server_id=$4"
echo "index=$5"
echo "#param1=$6"
echo "#param2=$7"

index=$5
server_id=$4
param1=$6
param2=$7



path=""
heros="hero hero2 hero3 hero4 hero5 hero6 hero7 hero8 hero9"
for hero in $heros
do
	if grep "server_id=$server_id" "/data/$hero/build/gameserver/gameserver.ini"
	then
		path="/data/$hero/build/gameserver/log"
		echo "find:$hero"
		break
	fi
done
echo "path=$path"

#if grep "server_id=$server_id" $filepath
#then
#    path=$rootpath/log/$2/*
#elif grep "server_id=$server_id" $filepath2
#then
#   path=$rootpath2/log/$2/*
#elif grep "server_id=$server_id" $filepath3
#then
#   path=$rootpath3/log/$2/*
#fi


st_time=$2
ed_time=$3
echo st_time=$st_time
echo ed_time=$ed_time
# time range is [st_time, ed_time], so let ed_time = ed_time + 1day
tmp_sec=$[`date -d"$ed_time" +%s` + 60 * 60 * 24]
ed_time=`date -d"@$tmp_sec" +%D`

tmp_sec=$[`date -d"$st_time" +%s`]
st_time=`date -d"@$tmp_sec" +%D`
#find log file in specific time range ( with modification time ), then sort by time as well 
#find . -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep ",4,"


#	1.SellItem         (卖出物品)
#	2.UseItem    	   (使用物品)
#	3.Delete Hero	   (英雄消耗)
#	4.Delete Equip     (装备消耗）
#	5.DoLotteryWheel   (幸运转盘)	
#	6.NiuDanNew        (召唤)
#	7.SpendResource    (资源消耗：金钱90001 钻石90003等）
#	8.GetResource      (获取资源)
#	9.BuyFund          (购买基金)
#	10.GetFundReward   (基金奖励）
#	11.GetMailReward   (邮件领取奖励)	
#	12.GetFanLiReward  (领取充值返利)
#	13.Accept Quest    (接受试炼任务)
#	14.BuyCommodity    (购买商品)
#	15.ChargeOrSpendActivity (充值活动)
#	16.CombineItem     (合成物品)
#	17.ComposeHero     (英雄融合)	
#	18.DoExchange      (兑换)
#	19.Get Quest Reward(获取任务奖励)
#	20.Remove Item
echo =====================================================================================================================================
case $index in
1) echo "1.Sell Item:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Sell Item.*$param1.*$param2"	
	#grep "$1.*Sell Item.*$param1.*$param2" $path
	;;
2) echo "2.UseItem:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*UseItem.*$param1.*$param2"
	;;
3) echo "3.Delete Hero"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Delete Hero.*$param1.*$param2"
	;;
4) echo "4.Delete Equip"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Delete Equip.*$param1.*$param2"
	;;
5) echo "5.DoLotteryWheel"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*DoLotteryWheel.*$param1.*$param2"
	;;
6) echo "6.NiuDanNew"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*NiuDanNew.*$param1.*$param2" -B2
	;;
7) echo "7.SpendResource"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*SpendResource.*resType=$param1.*$param2"
	;;
8) echo "8.GetResource"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*GetResource.*resType=$param1.*$param2"
	;;
9) echo "9.BuyFund"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*BuyFund.*$param1.*$param2"
	;;
10) echo "10.GetFundReward"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*GetFundReward.*$param1.*$param2" -A3
	;;
11) echo "11.GetMailReward"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*GetMailReward.*$param1.*$param2"
	;;
12) echo "12.GetFanLiReward"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*GetFanLiReward.*$param1.*$param2" -A3
	;;
13) echo "13.Accept Quest"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Accept Quest.*$param1.*$param2"
	;;
14) echo "14.BuyCommodity"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*BuyCommodity.*$param1.*$param2"
	;;
15) echo "15.ChargeOrSpendActivity"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*ChargeOrSpendActivity.*$param1.*$param2"
	;;
16) echo "16.CombineItem"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*CombineItem.*$param1.*$param2"
	;;
17) echo "17.ComposeHero"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*ComposeHero.*$param1.*$param2"
	;;
18) echo "18.DoExchange"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*DoExchange.*$param1.*$param2"
	;;
19) echo "19.Get Quest Reward"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Get Quest Reward.*$param1.*$param2"
	;;
20) echo "20.Remove Item:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*RemoveItem.*$param1.*$param2" -B2	
	;;
21) echo "20.Add Item:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*AddItem.*$param1.*$param2" -B2	
	;;
22) echo "22.Collect:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Collect.*$param1.*$param2"	
	;;
23) echo "23.VIP成就:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*HandlerClickActPackage.*$param1.*$param2" -A3
	;;
24) echo "24.全服聊天记录:"
	find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "HandlerSendChatMsg.*$param1.*$param2"
	;;
25) echo "4.Delete Jewel"
        find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*Delete Jewel.*$param1.*$param2"
        ;;
999) echo "999.Custom"
        find $path -type f -newermt $st_time -a ! -newermt $ed_time -print | xargs ls -tr | xargs cat | grep "$1.*$param1.*" $param2
        ;;

esac
