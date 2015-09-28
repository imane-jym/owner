#!/bin/bash
#set -x
if [ "root" != `whoami` ]; then
	echo "Error: 'root' Require"
	exit 1
fi
cat << here
1. redword 服务器svn地址 配表svn地址 例如:redword http://172.16.0.3/repository/f6_server/branches/hero-2.4.0-r1 http://172.16.0.3/repository/f6_art/branch/2.4.0
2. launch 服务器svn地址 配表svn地址 版本包名字 例如:launch http://172.16.0.3/repository/f6_server/branches/hero-2.4.0-r1 http://172.16.0.3/repository/f6_art/branch/2.4.0 yunding.2.4.0"     
here
echo "请输入你的命令"
read choose
cmd=`echo $choose | awk '{ print $1 }'`
param=`echo $choose | awk '{ print $2,$3,$4,$5,$6,$7}'`

case $cmd in
	"redword" )                                           
		./lock.sh lock.redword ./redword.sh $param
		;;
	"launch")
		lock=`basename \`echo $choose | awk '{ print $2}'\``
		./lock.sh lock.$lock ./server_launch.sh $param
		;;
	* )                                               
		echo "输入的命令非法 [imo]"                
		exit 1                                        
esac                                                  
