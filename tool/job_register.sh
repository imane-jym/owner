echo "starting ..."

ip="172.16.1.149"
name="imane"
pass="imane"
cd 
data_file_path=`pwd`
echo $data_file_path

usage ()
{
cat <<End-of-message
----------------------------------------
welcome use card program launch script
job_today [opt]
-h help
-i host ip
-u name
-p password
-f file path default path at local user root path(/home/imane/)
----------------------------------------
End-of-message
}

if [ $# -le 0 ]
then
	usage
	exit 0
else
	while getopts ":hi:u:p:f:" Option
	do
		#echo $Option
		#echo $OPTARG
		case $Option in
			h) 
				usage
				exit 0
				;;
			i)
				ip=$OPTARG
				;;
			u) 
				name=$OPTARG
				;;
			p) 
				pass=$OPTARG
				;;
			f) 
				data_file_path=$OPTARG
				;;
			\?) 
				echo "$OPTARG is unvalid"
				usage
				exit 0
				;;	
			:)
				echo "$OPTARG miss para"
				exit 0
				;;
		esac
	done
fi

echo "角色ID,角色名,账号,平台,VIP等级,VIP经验,引导进度,角色等级,金币,钻石,推图进度,行动力,能量,师傅等级,弟子1等级,弟子2等级,弟子3等级,弟子4等级,弟子5等级,弟子6等级,战斗力,登录次数,在线时长" > $data_file_path/data_`date +%Y-%m-%d_%H-%M-%S`.csv

mysql -h $ip -u $name -p$pass -D card_operate -N -e "select CONCAT_WS(',',a.role_id,a.name,b.passport, b.platform,a.vip_level,vip_exp,a.progress,a.level,a.gold,a.diamond,a.cur_stage,a.stamina,a.energy,a.card_level,a.ability,e.times,e.duration) from player_info a left join(re_passport_player c left join passport_info b on c.passport_id = b.passport_id) on (a.role_id = c.role_id) left join (select count(a.role_id) as "times", sum(a.logout_time - a.login_time) as "duration",a.role_id from role_login_info a where a.login_time <> 0 and a.logout_time <> 0 and unix_timestamp( concat(curdate(),' 00:00:00'))  -86400 < a.login_time and unix_timestamp( concat(curdate(),' 23:59:59')) - 86400 > a.login_time and unix_timestamp( concat(curdate(),' 00:00:00')) - 86400 < a.logout_time and unix_timestamp( concat(curdate(),' 23:59:59')) - 86400 > a.logout_time and a.logout_time > a.login_time group by a.role_id) e on (a.role_id = e.role_id) where unix_timestamp( concat(curdate(),' 00:00:00')) - 86400 < b.create_time and unix_timestamp( concat(curdate(),' 23:59:59')) - 86400 > b.create_time order by a.role_id asc;" >> $data_file_path/data_`date +%Y-%m-%d_%H-%M-%S`.csv
