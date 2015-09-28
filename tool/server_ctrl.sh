#!/bin/bash
set -x

BIN_DIR="../bin/"

usage ()
{
cat <<End-of-message
----------------------------------------
welcome use card program launch script
server_ctrl [opt]
-h help
-s server setting program which you want to ctrl
-c command start|status|stop|restart
----------------------------------------
End-of-message
}

SERVER=""
CMD="status"

if [ $# -le 0 ]
then
	usage
	exit 0
else
	while getopts ":hs:c:" Option
	do
		#echo $Option
		#echo $OPTARG
		case $Option in
			h) 
				usage
				exit 0
				;;
			s)
				SERVER=$OPTARG
				;;
			c) 
				CMD=$OPTARG
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

echo $SERVER
echo $CMD

if [ $CMD != "status" -a $CMD != "start" -a $CMD != "stop" -a $CMD != "restart" ]
then
	echo "you set -c fail [start|status|stop|restart]"
	usage
	exit 0
fi

if [ $SERVER != "gameserver" -a $SERVER != "loginserver" ]
then
	echo "you must set -s option"
	usage
	exit 0
fi

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib
OLD_PWD=`pwd`

echo $SERVER
echo $CMD
case $CMD in
	"status")
		ps -ef | grep --color "./$SERVER "
		;;
	"start")
		cd $BIN_DIR$SERVER
		number=`ps -ef | grep "./$SERVER " | wc -l`    

		if [ $number -lt 2 ]                         
		then                                         
			./$SERVER -d                          
		else                                         
			echo "server have started $SERVER"
		fi                                           
		cd $OLD_PWD
		;;
	"stop")
		cd $BIN_DIR$SERVER
		while true                                   
		do                                           
			pkill -f "./$SERVER "                            
			number=`ps -ef | grep "./$SERVER " | wc -l`    

			if [ $number -lt 2 ]                         
			then                                         
				echo "you have stop $SERVER"
				break
			else                                         
				sleep 1                                  
			fi                                           
		done
		cd $OLD_PWD
		;;
	"restart")
		cd $BIN_DIR$SERVER
		while true                                   
		do                                           
			pkill -f "./$SERVER "                           
			number=`ps -ef | grep "./$SERVER " | wc -l`    

			if [ $number -lt 2 ]                         
			then                                         
				./$SERVER -d                          
				break                                    
			else                                         
				sleep 1                                  
			fi                                           
		done
		cd $OLD_PWD
		;;
	*)
		echo "$SERVER $CMD  [start|status|stop|restart]"
		exit 0
		;;
esac
