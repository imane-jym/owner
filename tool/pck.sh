#! /bin/bash


if [ $# -ne 2 ]; then
	echo "execute with [tar_file_name] [zone]"
	exit 1
fi

name="hero-$1".`svn info | grep -E 'Last Changed Rev|最后修改的版本' | cut -d: -f 2 | cut -c 2-`
dir_name="hero"
address=""
password=""

case $2 in
	"imo" )
		address="root@61.153.99.132:/data/hero_files"
		password="ime@server01!";;
	* )
		echo "zone para must be [imo]"
		exit 1
esac

if [ -e $dir_name ]; then
	rm -rf $dir_name
fi

mkdir $dir_name

#tar -zcvf $1 \
cp --parents \
		libc/* \
		shell/start_server.sh \
		shell/stop_server.sh \
		shell/log_gameserver.sh \
		data/config/*.csv \
		build/gameserver/Gameserver \
		build/gameserver/gameserver.ini \
		build/gameserver/game.sql \
		build/loginserver/Loginserver \
		build/loginserver/loginserver.ini \
		build/loginserver/login.sql \
		build/relayserver/Relayserver \
		build/relayserver/relayserver.ini \
	$dir_name

touch $dir_name/$name

tar -zcvf $name.tar.gz $dir_name

rm -rf $dir_name

expect -c "
set timeout -1
spawn scp -o StrictHostKeyChecking=no $name.tar.gz $address
expect *assword*
send $password\n
expect eof
"
