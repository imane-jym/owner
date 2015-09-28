#!/bin/bash
set -x

BASE_DIR="../"
LIB_DIR="lib/"
GAME_SERVER="gameserver"
BUILD_DIR="build/"
CONFIG="../../Resource/Config"
LOGIN_SERVER="loginserver"
PLATFORM="ubuntu-12.04"
VERSION="1.5.1.0"
SVN_VERSION=`svnversion`
RES_HOST="ubuntu@42.62.50.7:/data/card_files"
RES_DOWNLOAD="/var/www/CardResource"
REPO_PATH="/home/imane/WorkArea/repo"

usage ()
{
cat <<End-of-message
----------------------------------------
----------------------------------------
End-of-message
}

#if [ $# -le 0 ]
#then
#	usage
#	exit 0
#else
	while getopts ":hv:s:" Option
	do
		#echo $Option
		#echo $OPTARG
		case $Option in
			h) 
				usage
				exit 0
				;;
			v)
				VERSION=$OPTARG
				;;
			s)
				RES_HOST=$OPTARG
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
#fi

if [ ! -d $BASE_DIR$LIB_DIR$PLATFORM ]
then
	echo "can not find this document $BASE_DIR$LIB_DIR$PLATFORM"
	exit 0
fi

launch_name=card_"$PLATFORM"_`date +%s`_"$VERSION"_"$SVN_VERSION"
mkdir -p card_launch
mkdir -p card_launch/$launch_name
mkdir -p card_launch/$launch_name/lib
mkdir -p card_launch/$launch_name/shell
mkdir -p card_launch/$launch_name/bin
mkdir -p card_launch/$launch_name/config
mkdir -p card_launch/$launch_name/bin/$GAME_SERVER
mkdir -p card_launch/$launch_name/bin/$LOGIN_SERVER
mkdir -p card_launch/$launch_name/res

cp -r $BASE_DIR$LIB_DIR$PLATFORM/* card_launch/$launch_name/lib
cp $BASE_DIR$BUILD_DIR$GAME_SERVER/$GAME_SERVER card_launch/$launch_name/bin/$GAME_SERVER
cp $BASE_DIR$BUILD_DIR$GAME_SERVER/*.ini card_launch/$launch_name/bin/$GAME_SERVER
cp $BASE_DIR$BUILD_DIR$GAME_SERVER/*.sh card_launch/$launch_name/bin/$GAME_SERVER
cp $BASE_DIR$BUILD_DIR$LOGIN_SERVER/$LOGIN_SERVER card_launch/$launch_name/bin/$LOGIN_SERVER
cp $BASE_DIR$BUILD_DIR$LOGIN_SERVER/*.ini card_launch/$launch_name/bin/$LOGIN_SERVER
cp $BASE_DIR$BUILD_DIR$LOGIN_SERVER/*.sh card_launch/$launch_name/bin/$LOGIN_SERVER
cp server_ctrl.sh card_launch/$launch_name/shell
cp -r $CONFIG/* card_launch/$launch_name/config
cp -r $RES_DOWNLOAD/* card_launch/$launch_name/res

cd card_launch
tar -czvf $launch_name.tar.gz $launch_name
#cp $launch_name.tar.gz $REPO_PATH

scp $launch_name.tar.gz $RES_HOST
