#!/bin/bash
#set -x
if [ $# -ne 3 ]; then                                
	echo "命令格式错误 $0 资源svn版本 发布目的地 服务器ID:1,2,3,4-10"       
	echo "例如: $0 23462 imo 1,2-3,4"
	exit 1                                           
fi                                                   

choose_server=$3
choose_server=${choose_server//,/ }
function isChoose()
{
    #for i in $choose_server
    #do
    #    if [ z$1 = z$i ]
    #    then
    #        return 1
    #    fi
    #done
    #return 0

    for i in $choose_server
    do
        start_number=`echo $i | cut -d- -f 1`
        end_number=`echo $i | cut -d- -f 2`
        for ((j=$start_number;j<=$end_number;j++))
        do
            if [ z$1 = z$j ]
            then
                return 1
            fi
        done
    done
    return 0
}

original_path=`pwd`
name=$1
address=''
password=''
case $2 in
	"zhw_choose" )
		src_address='jiangyiming@127.0.0.1:/var/www/config'
		serverlist="
		127.0.0.1	jiangyiming password	/data/threed 10001\n
		127.0.0.1	jiangyiming password	/data/threed2 10002\n
		127.0.0.1	jiangyiming password	/data/threed3 10003
		"
                address="jiangyiming@127.0.0.1:/var/www/config"
                password="password"
		db_server_address="jiangyiming@127.0.0.1"
		db_server_password="password"
		db_host="172.16.105.3"
		db_user="threed_db"
		db_pwd="123456"
		db_name="threed_login"
		;;
	* )
		echo "zone para must be [imo, inner, outer, xd_imo, xd_test]"
		exit 1
esac

already_server=''
#for line in `echo -e $serverlist`
echo -e $serverlist > temp
while read line
do
	server_id=''
	if [ z$2 = z"xd_choose" -o z$2 = z"zhw_choose" ]
	then
		server_id=`echo $line | awk '{print $5}'`
		isChoose $server_id
		if [ $? -ne 1 ]
		then
			continue
		fi
	fi	
	host_ip=`echo $line | awk '{print $1}'`
	username=`echo $line | awk '{print $2}'`
	passwd=`echo $line | awk '{print $3}'`
	dest_file=`echo $line | awk '{print $4}'`

expect <<EOF
set timeout 300
spawn ssh -o StrictHostKeyChecking=no $username@$host_ip
expect *assword*
send $passwd\n
expect *$\*
send "scp -r -o StrictHostKeyChecking=no $src_address/$name/* $dest_file/config/ &> /dev/null \n"
expect *assword*
send $password\n
expect *$\*
send "exit \$?\n"
expect eof
catch wait ret
exit [lindex \$ret 3]
EOF

if [ $? -ne 0 ]
then
	echo "===== $server_id $host_ip $dest_file fail ====="
	exit 1
else
	echo "===== $server_id $host_ip $dest_file success ====="
fi
already_server=$already_server" "$server_id
done < temp
echo $already_server

#insert reload csv for program
sql_str=''
for i in $already_server
do
	sql_str=$sql_str",('reload_label','$name',1,$i,unix_timestamp(),'operation')"
done
sql_str=`echo $sql_str | cut -c 2-`
expect <<EOF
set timeout 300
spawn ssh -o StrictHostKeyChecking=no $db_server_address
expect *assword*
send $db_server_password\n
expect *$\*
send "mysql -h$db_host -u$db_user -p$db_pwd $db_name -e \"insert into gm_cmd(opr,params,target_type,target_id,create_time,author) values $sql_str\"\n"
expect *$\*
send "exit \$?\n"
expect eof
catch wait ret
exit [lindex \$ret 3]
EOF

if [ $? -ne 0 ]
then
	echo "===== mysql operation fail ====="
	exit 1
else
	echo "===== mysql operation success ====="
fi

cd $original_path
