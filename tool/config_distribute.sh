#!/bin/bash
#set -x
if [ $# -lt 2 ]; then                                
	echo "命令格式错误 $0 资源svn地址 发布目的地 [可选 服务器ID:1,2,3,4-10]"       
	echo "例如: $0 http://172.16.0.2/svn/3d_client/trunk/client/BuildRes imo"
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
server_version=$1
svn_username=imane
svn_passwd=imane
tmp_file=tmp_`date +%Y%m%d-%H%M%S`_pid$$

main_path=`basename $server_version`
main_path=`echo $server_version | awk -F/ '{ print $(NF-1)"_"$(NF)}'`
echo "现在检查资源工作目录"
if [ ! -d $main_path ]
then
        echo "现在开始创建服务器工作目录"
        svn co --non-interactive --username=$svn_username --password=$svn_passwd $server_version 
        if [ $? -ne 0 ]
        then
                echo "创建svn工作目录失败，请联系服务器研发工程师"
                exit 1
        fi
else
	echo "现在开始切换CSV目录"
	svn sw --non-interactive --username=$svn_username --password=$svn_passwd $server_version $main_path 
	if [ $? -ne 0 ]
	then
	echo "创建svn工作目录失败，请联系服务器研发工程师"
	exit 1
	fi
fi


cd $main_path
echo "现在更新资源工作目录"
svn up --non-interactive --username=$svn_username --password=$svn_passwd | tee /tmp/$tmp_file
if [ $? -ne 0 ]
then
	echo "更新svn失败，请联系服务器研发工程师"
	exit 1
fi
if grep /tmp/$tmp_file 'Text conflicts'
then
	echo "更新svn冲突, 请联系服务器研发工程师"
	exit 1
fi

name=`svn info | grep -E 'Last Changed Rev|最后修改的版本' | cut -d: -f 2 | cut -c 2-`
cd ../
if [ -e $name ]; then
	rm -rf $name
fi

address=''
password=''
case $2 in
	"inner" )
		address="ime@172.16.0.89:/home/ime/packet"
		password="ime@server";;
    "xd_choose" )
		src_address='jiangyiming@10.0.0.1:/var/www/config'
		serverlist="
		127.0.0.1	jiangyiming 123456	/data/threed 1\n
		127.0.0.1	jiangyiming 123456	/data/threed 2\n
		"
        address="jiangyiming@10.0.0.1:/var/www/config"
        password="123456";;
	* )
		echo "zone para must be [imo, inner, outer, xd_imo, xd_test]"
		exit 1
esac

mkdir $name
cp $main_path/* $name
cd $name
find . -name .svn -exec rm -rf {} \; >& /dev/null
cd ../

#upload config
expect -c "
set timeout -1
spawn scp -r -o StrictHostKeyChecking=no $name $address
expect *assword*
send $password\n
expect eof
"

echo -e $serverlist | while read line
do
	server_id=''
	if [ z$2 = z"xd_choose" ]
	then
		server_id=`echo $line | awk '{print $5}'`
		isChoose $server_id
		if [ $? -ne 1 ]
		then
			continue
		fi
		echo $server_id	
	fi	
	host_ip=`echo $line | awk '{print $1}'`
	username=`echo $line | awk '{print $2}'`
	passwd=`echo $line | awk '{print $3}'`
	dest_file=`echo $line | awk '{print $4}'`

expect -c "
set timeout 30
spawn ssh -o StrictHostKeyChecking=no $username@$host_ip
expect *assword*
send $passwd\n
expect *$\*
send \"scp -r -o StrictHostKeyChecking=no $src_address/$name/* $dest_file/config/ &> /dev/null\n\"
expect *assword*
send $password\n
expect *$\*
send exit\n
expect eof
"
if [ $? -ne 0 ]
then
	echo "===== $server_id $host_ip $dest_file fail ====="
	exit 1
else
	echo "===== $server_id $host_ip $dest_file success ====="
fi
done 

cd $original_path
