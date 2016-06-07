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
		src_address='jiangyiming@172.16.105.4:/var/www/config'
		serverlist="
		210.59.246.48	jiangyiming yim@821.me	/data/threed 1\n
		210.59.246.49	jiangyiming yim@821.me	/data/threed 2\n
		210.59.246.48	jiangyiming yim@821.me	/data/threed2 3\n
		210.59.246.49	jiangyiming yim@821.me	/data/threed2	4\n
		210.59.246.48	jiangyiming yim@821.me	/data/threed3	5\n
		210.59.246.49	jiangyiming yim@821.me	/data/threed3	6\n
		210.59.246.48	jiangyiming yim@821.me	/data/threed4	7\n
		210.59.246.49	jiangyiming yim@821.me	/data/threed4	8\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed 10001\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed2 10002\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed3 10003\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed4 10004\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed5 10005\n
		210.59.246.47	jiangyiming yim@821.me	/data/threed6 10006\n
		"
                address="jiangyiming@210.59.246.45:/var/www/config"
                password="yim@821.me"
		db_server_address="jiangyiming@210.59.246.45"
		db_server_password="yim@821.me"
		db_host="172.16.105.3"
		db_user="threed_db"
		db_pwd="123456"
		db_name="threed_login"
		;;
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
		119.29.162.33  	jiangyiming yim@821.me  /data/threed4 41\n	
		119.29.164.41  	jiangyiming yim@821.me  /data/threed4 42\n	
		119.29.96.98   	jiangyiming yim@821.me  /data/threed4 43\n	
		119.29.164.58  	jiangyiming yim@821.me  /data/threed4 44\n
		119.29.62.54  	jiangyiming yim@821.me  /data/threed 45\n
		119.29.148.82  	jiangyiming yim@821.me  /data/threed 46\n
		119.29.62.54  	jiangyiming yim@821.me  /data/threed2 47\n
		119.29.148.82  	jiangyiming yim@821.me  /data/threed2 48\n
		119.29.62.54  	jiangyiming yim@821.me  /data/threed3 49\n
		119.29.148.82  	jiangyiming yim@821.me  /data/threed3 50\n
		119.29.62.54  	jiangyiming yim@821.me  /data/threed4 51\n
		119.29.148.82  	jiangyiming yim@821.me  /data/threed4 52\n
		119.29.146.41  	jiangyiming yim@821.me  /data/threed 53\n
		119.29.146.41  	jiangyiming yim@821.me  /data/threed2 54\n
		119.29.146.41  	jiangyiming yim@821.me  /data/threed3 55\n
		119.29.146.41  	jiangyiming yim@821.me  /data/threed4 56\n
		119.29.17.171  	jiangyiming yim@821.me  /data/threed 57\n
		119.29.84.244  	jiangyiming yim@821.me  /data/threed 58\n
		119.29.138.244  jiangyiming yim@821.me  /data/threed 59\n
		119.29.17.171   jiangyiming yim@821.me  /data/threed2 60\n
		119.29.84.244   jiangyiming yim@821.me  /data/threed2 61\n
		119.29.138.244  jiangyiming yim@821.me  /data/threed2 62\n
		119.29.17.171   jiangyiming yim@821.me  /data/threed3 63\n
		119.29.84.244   jiangyiming yim@821.me  /data/threed3 64\n
		119.29.138.244  jiangyiming yim@821.me  /data/threed3 65\n
		119.29.17.171   jiangyiming yim@821.me  /data/threed4 66\n
		119.29.84.244   jiangyiming yim@821.me  /data/threed4 67\n
		119.29.138.244  jiangyiming yim@821.me  /data/threed4 68\n
		119.29.160.108  jiangyiming yim@821.me  /data/threed  69\n
		119.29.11.70    jiangyiming yim@821.me  /data/threed  70\n
		119.29.160.134  jiangyiming yim@821.me  /data/threed  71\n
		119.29.160.161  jiangyiming yim@821.me  /data/threed  72\n
		119.29.160.108  jiangyiming yim@821.me  /data/threed2 73\n
		119.29.11.70    jiangyiming yim@821.me  /data/threed2 74\n
		119.29.160.134  jiangyiming yim@821.me  /data/threed2 75\n
		119.29.160.161  jiangyiming yim@821.me  /data/threed2 76\n
		119.29.160.108  jiangyiming yim@821.me  /data/threed3 77\n
		119.29.11.70    jiangyiming yim@821.me  /data/threed3 78\n
		119.29.160.134  jiangyiming yim@821.me  /data/threed3 79\n
		119.29.160.161  jiangyiming yim@821.me  /data/threed3 80\n
		119.29.160.108  jiangyiming yim@821.me  /data/threed4 81\n
		119.29.11.70    jiangyiming yim@821.me  /data/threed4 82\n
		119.29.160.134  jiangyiming yim@821.me  /data/threed4 83\n
		119.29.160.161  jiangyiming yim@821.me  /data/threed4 84\n
		119.29.120.222  jiangyiming yim@821.me  /data/threed 85\n
		119.29.104.140  jiangyiming yim@821.me  /data/threed 86\n
		119.29.120.222  jiangyiming yim@821.me  /data/threed2 87\n
		119.29.104.140  jiangyiming yim@821.me  /data/threed2 88\n
		119.29.120.222  jiangyiming yim@821.me  /data/threed3 89\n
		119.29.104.140  jiangyiming yim@821.me  /data/threed3 90\n
		119.29.120.222  jiangyiming yim@821.me  /data/threed4 91\n
		119.29.104.140  jiangyiming yim@821.me  /data/threed4 92\n
		119.29.61.185	jiangyiming yim@821.me  /data/threed 93\n
		119.29.93.233	jiangyiming yim@821.me  /data/threed 94\n
		119.29.61.185	jiangyiming yim@821.me  /data/threed2 95\n
		119.29.93.233	jiangyiming yim@821.me  /data/threed2 96\n
		119.29.61.185	jiangyiming yim@821.me  /data/threed3 97\n
		119.29.93.233	jiangyiming yim@821.me  /data/threed3 98\n
		119.29.61.185	jiangyiming yim@821.me  /data/threed4 99\n
		119.29.93.233	jiangyiming yim@821.me  /data/threed4 100\n
		119.29.180.191	jiangyiming yim@821.me  /data/threed 101\n
		119.29.180.118	jiangyiming yim@821.me  /data/threed 102\n
		119.29.180.191	jiangyiming yim@821.me  /data/threed2 103\n
		119.29.180.118	jiangyiming yim@821.me  /data/threed2 104\n
		119.29.180.191	jiangyiming yim@821.me  /data/threed3 105\n
		119.29.180.118	jiangyiming yim@821.me  /data/threed3 106\n
		119.29.180.191	jiangyiming yim@821.me  /data/threed4 107\n
		119.29.180.118	jiangyiming yim@821.me  /data/threed4 108\n
		119.29.187.83	jiangyiming yim@821.me	/data/threed	109\n
		119.29.193.193	jiangyiming yim@821.me	/data/threed	110\n
		119.29.187.83	jiangyiming yim@821.me	/data/threed2	111\n
		119.29.193.193	jiangyiming yim@821.me	/data/threed2	112\n
		119.29.187.83	jiangyiming yim@821.me	/data/threed3	113\n
		119.29.193.193	jiangyiming yim@821.me	/data/threed3	114\n
		119.29.187.83	jiangyiming yim@821.me	/data/threed4	115\n
		119.29.193.193	jiangyiming yim@821.me	/data/threed4	116\n
		119.29.27.52	jiangyiming yim@821.me	/data/threed	117\n
		119.29.156.112	jiangyiming yim@821.me	/data/threed	118\n
		119.29.24.216	jiangyiming yim@821.me	/data/threed	119\n
		119.29.77.173	jiangyiming yim@821.me	/data/threed	120\n
		119.29.27.52	jiangyiming yim@821.me	/data/threed2	121\n
		119.29.156.112	jiangyiming yim@821.me	/data/threed2	122\n
		119.29.24.216	jiangyiming yim@821.me	/data/threed2	123\n
		119.29.77.173	jiangyiming yim@821.me	/data/threed2	124\n
		119.29.27.52	jiangyiming yim@821.me	/data/threed3	125\n
		119.29.156.112	jiangyiming yim@821.me	/data/threed3	126\n
		119.29.24.216	jiangyiming yim@821.me	/data/threed3	127\n
		119.29.77.173	jiangyiming yim@821.me	/data/threed3	128\n
		119.29.27.52	jiangyiming yim@821.me	/data/threed4	129\n
		119.29.156.112	jiangyiming yim@821.me	/data/threed4	130\n
		119.29.24.216	jiangyiming yim@821.me	/data/threed4	131\n
		119.29.77.173	jiangyiming yim@821.me	/data/threed4	132\n
		119.29.241.111	jiangyiming yim@821.me	/data/threed	1001\n
		119.29.243.135	jiangyiming yim@821.me	/data/threed	1002\n
		119.29.241.111	jiangyiming yim@821.me	/data/threed2	1003\n
		119.29.243.135	jiangyiming yim@821.me	/data/threed2	1004\n
		119.29.241.111	jiangyiming yim@821.me	/data/threed3	1005\n
		119.29.243.135	jiangyiming yim@821.me	/data/threed3	1006\n
		119.29.241.111	jiangyiming yim@821.me	/data/threed4	1007\n
		119.29.243.135	jiangyiming yim@821.me	/data/threed4	1008\n
		119.29.248.178	jiangyiming yim@821.me	/data/threed	1009\n
		119.29.248.178	jiangyiming yim@821.me	/data/threed2	1010\n
		119.29.248.178	jiangyiming yim@821.me	/data/threed3	1011\n
		119.29.248.178	jiangyiming yim@821.me	/data/threed4	1012\n
		119.29.242.81	jiangyiming yim@821.me	/data/threed	2001\n
		119.29.241.182	jiangyiming yim@821.me	/data/threed	2002\n
		119.29.242.81	jiangyiming yim@821.me	/data/threed2	2003\n
		119.29.241.182	jiangyiming yim@821.me	/data/threed2	2004\n
		119.29.242.81	jiangyiming yim@821.me	/data/threed3	2005\n
		119.29.241.182	jiangyiming yim@821.me	/data/threed3	2006\n
		119.29.242.81	jiangyiming yim@821.me	/data/threed4	2007\n
		119.29.241.182	jiangyiming yim@821.me	/data/threed4	2008\n
		119.29.162.249	jiangyiming yim@821.me	/data/threed 7001\n
		119.29.159.65	jiangyiming yim@821.me	/data/threed 7002\n
		119.29.162.249	jiangyiming yim@821.me	/data/threed2 7003\n
		119.29.159.65	jiangyiming yim@821.me	/data/threed2 7004\n
		119.29.162.249	jiangyiming yim@821.me	/data/threed3 7005\n
		119.29.159.65	jiangyiming yim@821.me	/data/threed3 7006\n
		119.29.162.249	jiangyiming yim@821.me	/data/threed4 7007\n
		119.29.159.65	jiangyiming yim@821.me	/data/threed4 7008\n
		119.29.86.65  	jiangyiming yim@821.me  /data/threed 8001\n
		119.29.140.173	jiangyiming yim@821.me  /data/threed 8002\n
		119.29.86.65  	jiangyiming yim@821.me  /data/threed2 8003\n
		119.29.140.173	jiangyiming yim@821.me  /data/threed2 8004\n
		119.29.86.65  	jiangyiming yim@821.me  /data/threed3 8005\n
		119.29.140.173	jiangyiming yim@821.me  /data/threed3 8006\n
		119.29.86.65  	jiangyiming yim@821.me  /data/threed4 8007\n
		119.29.140.173	jiangyiming yim@821.me  /data/threed4 8008\n
		119.29.76.118 	jiangyiming yim@821.me	/data/threed 8009\n
		119.29.57.174 	jiangyiming yim@821.me	/data/threed 8010\n
		119.29.76.118 	jiangyiming yim@821.me	/data/threed2 8011\n
		119.29.57.174 	jiangyiming yim@821.me	/data/threed2 8012\n
		119.29.76.118 	jiangyiming yim@821.me	/data/threed3 8013\n
		119.29.57.174 	jiangyiming yim@821.me	/data/threed3 8014\n
		119.29.76.118 	jiangyiming yim@821.me	/data/threed4 8015\n
		119.29.57.174 	jiangyiming yim@821.me	/data/threed4 8016\n
		119.29.111.38   jiangyiming yim@821.me  /data/threed  9001\n
		119.29.111.38   jiangyiming yim@821.me  /data/threed2 9002\n
		119.29.111.38   jiangyiming yim@821.me  /data/threed3 9003\n
		119.29.111.38   jiangyiming yim@821.me  /data/threed4 9004\n
		119.29.108.133	jiangyiming yim@821.me  /data/threed 9005\n
		119.29.108.133	jiangyiming yim@821.me  /data/threed2 9006\n
		119.29.108.133	jiangyiming yim@821.me  /data/threed3 9007\n
		119.29.108.133	jiangyiming yim@821.me  /data/threed4 9008\n
		119.29.181.143	jiangyiming yim@821.me  /data/threed 9009\n
		119.29.134.215	jiangyiming yim@821.me  /data/threed 9010\n
		119.29.181.143	jiangyiming yim@821.me  /data/threed2 9011\n
		119.29.134.215	jiangyiming yim@821.me  /data/threed2 9012\n
		119.29.181.143	jiangyiming yim@821.me  /data/threed3 9013\n
		119.29.134.215	jiangyiming yim@821.me  /data/threed3 9014\n
		119.29.181.143	jiangyiming yim@821.me  /data/threed4 9015\n
		119.29.134.215	jiangyiming yim@821.me  /data/threed4 9016\n
		119.29.196.159	jiangyiming yim@821.me  /data/threed 9017\n
		119.29.195.147	jiangyiming yim@821.me  /data/threed 9018\n
		119.29.196.159	jiangyiming yim@821.me  /data/threed2 9019\n
		119.29.195.147	jiangyiming yim@821.me  /data/threed2 9020\n
		119.29.196.159	jiangyiming yim@821.me  /data/threed3 9021\n
		119.29.195.147	jiangyiming yim@821.me  /data/threed3 9022\n
		119.29.196.159	jiangyiming yim@821.me  /data/threed4 9023\n
		119.29.195.147	jiangyiming yim@821.me  /data/threed4 9024\n
		119.29.108.133  jiangyiming yim@821.me  /data/threed5 9801\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed 10001\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed2 10002\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed3 10003\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed4 10004\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed5 10005\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed6 10006\n
		119.29.86.71	jiangyiming yim@821.me	/data/threed7 10007\n
		119.29.92.244	jiangyiming yim@821.me	/data/threed 3001\n
		119.29.205.110	jiangyiming yim@821.me	/data/threed 3002\n
		119.29.92.244	jiangyiming yim@821.me	/data/threed 3003\n
		119.29.205.110	jiangyiming yim@821.me	/data/threed 3004\n
		119.29.92.244	jiangyiming yim@821.me	/data/threed 3005\n
		119.29.205.110	jiangyiming yim@821.me	/data/threed 3006\n
		119.29.92.244	jiangyiming yim@821.me	/data/threed 3007\n
		119.29.205.110	jiangyiming yim@821.me	/data/threed 3008
		"
                address="jiangyiming@119.29.86.114:/var/www/config"
                password="yim@821.me"
		db_server_address="jiangyiming@119.29.86.71"
		db_server_password="yim@821.me"
		db_host="10.104.145.37"
		db_user="threed_db"
		db_pwd="123456"
		db_name="threed_login"
		;;
	"bm_choose" )
		src_address='jiangyiming@107.150.99.112:/var/www/config'
		serverlist="
		107.150.99.112	jiangyiming yim@821.me	/data/threed_255 255
		"
                address="jiangyiming@107.150.99.112:/var/www/config"
                password="yim@821.me"
		db_server_address="jiangyiming@107.150.99.112"
		db_server_password="yim@821.me"
		db_host="10.11.19.205"
		db_user="threed_db"
		db_pwd="123456"
		db_name="threed_login"
		;;
	"xm_choose" )
		src_address='jiangyiming@10.14.2.7:/var/www/config'
		serverlist="
		52.77.126.15	jiangyiming yim@821.me	/data/threed_255 255
		"
                address="jiangyiming@54.254.245.24:/var/www/config"
                password="yim@821.me"
		db_server_address="jiangyiming@54.254.245.24"
		db_server_password="yim@821.me"
		db_host="10.14.2.11"
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
	server_id=`echo $line | awk '{print $5}'`
	isChoose $server_id
	if [ $? -ne 1 ]
	then
	continue
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
	#exit 1
else
	echo "===== $server_id $host_ip $dest_file success ====="
	already_server=$already_server" "$server_id
fi
#already_server=$already_server" "$server_id
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
