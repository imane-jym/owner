#!/bin/bash
#set -x
if [ $# -ne 2 ]; then                                
	echo "命令格式错误 $0 资源svn地址 发布目的地"       
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
if [ a$name = "a" ]
then
	echo "svn info get version fail"
	exit 1
fi
cd ../
if [ -e $name ]; then
	rm -rf $name
fi

address=''
password=''
case $2 in
	"imo" )
		src_address='jiangyiming@10.10.66.74:/var/www/config'
		serverlist="
		123.59.67.237	jiangyiming yim@821.me	/data/3d\n
		123.59.67.237	jiangyiming yim@821.me	/data/3d_360_1.2.0
		"
		address="jiangyiming@123.59.67.237:/var/www/config"
		password="yim@821.me";;
	"inner" )
		address="ime@172.16.0.89:/home/ime/packet"
		password="ime@server";;
	"outer" )
		address="jiangyiming@203.12.203.22:/home/jiangyiming/update"
		password="yim@821.me";;
        "xd_imo" )
		src_address='jiangyiming@10.104.145.43:/var/www/config'
		serverlist="
		119.29.86.52	jiangyiming yim@821.me	/data/threed 1\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed 2\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed 3\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed 4\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed 5\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed2 6\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed2 7\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed2 8\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed2 9\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed2 10\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed3 11\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed3 12\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed3 13\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed3 14\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed3 15\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed4 16\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed4 17\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed4 18\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed4 19\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed4 20\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed 21\n
		119.29.68.79    jiangyiming yim@821.me  /data/threed 22\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed2 23\n
		119.29.68.79    jiangyiming yim@821.me  /data/threed2 24\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed3 25\n
		119.29.68.79  	jiangyiming yim@821.me  /data/threed3 26\n
		119.29.158.155 	jiangyiming yim@821.me  /data/threed4 27\n
		119.29.68.79   	jiangyiming yim@821.me  /data/threed4 28\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed 29\n
		119.29.164.41  	jiangyiming yim@821.me  /data/threed 30\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed 31\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed 32\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed2 33\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed2 34\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed2 35\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed2 36\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed3 37\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed3 38\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed3 39\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed3 40\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed4 41\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed4 42\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed4 43\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed4 44
		"
                address="jiangyiming@119.29.86.114:/var/www/config"
                password="yim@821.me";;
	"xd_test" )
		src_address='jiangyiming@10.104.145.43:/var/www/config'
		serverlist="
		119.29.86.71	jiangyiming yim@821.me	/data/threed
		"
                address="jiangyiming@119.29.86.114:/var/www/config"
                password="yim@821.me";;
	"xd_shenhe" )
		src_address='jiangyiming@10.104.145.43:/var/www/config'
		serverlist="
		119.29.86.71	jiangyiming yim@821.me	/data/threed2
		"
                address="jiangyiming@119.29.86.114:/var/www/config"
                password="yim@821.me";;
	"zhw_test" )
		src_address='jiangyiming@172.16.105.4:/var/www/config'
		serverlist="
		210.59.246.47	jiangyiming yim@821.me	/data/threed3
		"
                address="jiangyiming@210.59.246.45:/var/www/config"
                password="yim@821.me";;
	"zhw_check" )
		src_address='jiangyiming@172.16.105.4:/var/www/config'
		serverlist="
		210.59.246.47	jiangyiming yim@821.me	/data/threed2
		"
                address="jiangyiming@210.59.246.45:/var/www/config"
                password="yim@821.me";;
        "xd_choose" )
		src_address='jiangyiming@10.104.145.43:/var/www/config'
		serverlist="
		119.29.86.52	jiangyiming yim@821.me	/data/threed 1\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed 2\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed 3\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed 4\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed 5\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed2 6\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed2 7\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed2 8\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed2 9\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed2 10\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed3 11\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed3 12\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed3 13\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed3 14\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed3 15\n
		119.29.86.52	jiangyiming yim@821.me	/data/threed4 16\n
		119.29.87.169	jiangyiming yim@821.me	/data/threed4 17\n
		119.29.87.126	jiangyiming yim@821.me	/data/threed4 18\n
		119.29.83.171	jiangyiming yim@821.me	/data/threed4 19\n
		119.29.52.78	jiangyiming yim@821.me	/data/threed4 20\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed 21\n
		119.29.68.79    jiangyiming yim@821.me  /data/threed 22\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed2 23\n
		119.29.68.79    jiangyiming yim@821.me  /data/threed2 24\n
		119.29.158.155  jiangyiming yim@821.me  /data/threed3 25\n
		119.29.68.79  	jiangyiming yim@821.me  /data/threed3 26\n
		119.29.158.155 	jiangyiming yim@821.me  /data/threed4 27\n
		119.29.68.79   	jiangyiming yim@821.me  /data/threed4 28\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed 29\n
		119.29.164.41  	jiangyiming yim@821.me  /data/threed 30\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed 31\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed 32\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed2 33\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed2 34\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed2 35\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed2 36\n	
		119.29.162.33  	jiangyiming yim@821.me  /data/threed3 37\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed3 38\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed3 39\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed3 40\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed4 41\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed4 42\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed4 43\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed4 44
		"
                address="jiangyiming@119.29.86.114:/var/www/config"
                password="yim@821.me";;
	"zhw_choose" )
		src_address='jiangyiming@172.16.105.4:/var/www/config'
		serverlist="
		210.59.246.47	jiangyiming yim@821.me	/data/threed 10001\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed2 10002\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed3 10003
		"
                address="jiangyiming@210.59.246.45:/var/www/config"
                password="yim@821.me";;
	"bm_choose" )
		src_address='jiangyiming@107.150.99.112:/var/www/config'
		serverlist="
		107.150.99.112	jiangyiming yim@821.me	/data/threed_255 255\n
		"
                address="jiangyiming@107.150.99.112:/var/www/config"
                password="yim@821.me";;
	"xm_choose" )
		src_address='jiangyiming@10.14.2.7:/var/www/config'
		serverlist="
		52.77.126.15	jiangyiming yim@821.me	/data/threed_255 255
		"
                address="jiangyiming@54.254.245.24:/var/www/config"
                password="yim@821.me";;
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
expect <<EOF
set timeout -1
spawn scp -r -o StrictHostKeyChecking=no $name $address
expect *assword*
send $password\n
expect eof
catch wait ret
exit [lindex \$ret 3]
EOF

if [ $? -ne 0 ]
then
        echo "===== launch $name operation fail ====="
        exit 1
else
        echo "===== launch $name operation success ====="
fi

cd $original_path
