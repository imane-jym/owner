#/bin/bash
#set -x
SERVER="gameserver"

kill `cat .pid` 

while true
do
number=`ps -f \`cat .pid\` | wc -l `

if [ $number -lt 2 ]
then
	break
else
	sleep 1
fi	
done

./$SERVER -d
