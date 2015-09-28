#!/bin/bash
#set -x
if [ $# -ne 2 ]; then                                
	echo "命令格式错误 $0 服务器svn地址 配表svn地址"       
	echo "例如: $0 http://172.16.0.3/repository/f6_server/branches/hero-2.4.0-r1 http://172.16.0.3/repository/f6_art/branch/2.4.0"
	exit 1                                           
fi                                                   

original_path=`pwd`
server_version=$1
csv_config=$2
svn_username=imane
svn_passwd=imane
tmp_file=tmp_`date +%Y%m%d-%H%M%S`_pid$$

main_path=`basename $server_version`
echo "现在检查服务器工作目录"
if [ ! -d $main_path ]
then
	echo "现在开始创建服务器工作目录"
	svn co --non-interactive --username=$svn_username --password=$svn_passwd $server_version 
	if [ $? -ne 0 ]
	then
		echo "创建svn工作目录失败，请联系服务器研发工程师"
		exit 1
	fi
fi

cd $main_path
echo "现在开始检查CSV工作目录"
if [ ! -d data/config ]
then
	echo "现在开始创建CSV工作目录"
	mkdir -p data
	svn co --non-interactive --username=$svn_username --password=$svn_passwd $csv_config/data/config data/config
	if [ $? -ne 0 ]
	then
		echo "创建CSV工作目录失败，请联系服务器研发工程师"
		exit 1
	fi
fi

echo "现在更新服务器代码"
svn up --non-interactive --username=$svn_username --password=$svn_passwd | tee /tmp/$tmp_file
if [ $? -ne 0 ]
then
	echo "更新svn失败，请联系服务器研发工程师"
	exit 1
fi
if grep 'Text conflicts' /tmp/$tmp_file #2> /dev/null
then
	echo "更新svn冲突, 请联系服务器研发工程师"
	exit 1
fi

is_add=0
if grep '^A ' /tmp/$tmp_file #2> /dev/null
then
	is_add=1
fi

echo "现在开始切换CSV"
svn sw --non-interactive --username=$svn_username --password=$svn_passwd $csv_config/data/config data/config | tee /tmp/$tmp_file
if [ $? -ne 0 ]
then
	echo "切换svn失败，请联系服务器研发工程师"
	exit 1
fi
if grep /tmp/$tmp_file 'Text conflicts' 2> /dev/null
then
	echo "切换svn冲突, 请联系服务器研发工程师"
	exit 1
fi

echo "检查是否要重置MAKEFILE"
if [ ! -f "build/redwordtool/Makefile" ]
then
	echo "重置MAKEFIE文件"
	cd build/
	cmake ../ 
	if [ $? -ne 0 ]
	then
		echo "重置MAKEFILE失败，请联系服务器研发工程师"
		exit 1
	fi
	cd ../
fi

echo "现在开始检查编译链接目录"
echo "现在开始编译链接"
make -C build/redwordtool/
if [ $? -ne 0 ]
then
	echo "编译链接失败，请联系服务器研发工程师"
	exit 1
fi

./build/redwordtool/Redword ./ data/config/
cd $original_path
