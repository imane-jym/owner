#!/bin/bash
user=hero_db
psd=123456
db=hero_login

for i in `cat bbb.log`
do
server_id=$(sudo mysql -u$user -p$psd $db -e"select re_passport_player.server_id from re_passport_player where role_id=$i")
server_id=${server_id:10}
echo $i','$server_id
done
