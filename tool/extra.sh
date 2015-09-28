#!/bin/bash

for i in `cat final_result.log`
do
	grep $i bbb.log > /dev/null
	#echo $?
	if [ $? != 0 ]
	then
		echo $i
	fi	
done
