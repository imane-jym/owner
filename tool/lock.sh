#!/bin/bash
#set -x

lock_file=$1
{
flock -e -w 10 200
if [ $? -ne 0 ]; then
	echo "其他用户正在处理"
	exit 1
fi
shift 1
$@
} 200<>/tmp/$lock_file
