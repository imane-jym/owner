#!/bin/bash
userid=$1
mysql -uroot -pmysql@ime merge_world -e "delete from player_blob_1 where account_id = $1"
mysql -uroot -pmysql@ime merge_world -e "delete from player_blob_2 where account_id = $1" 
mysql -uroot -pmysql@ime merge_world -e "delete from player_blob_3 where account_id = $1"  
mysql -uroot -pmysql@ime merge_world -e "delete from player_blob_4 where account_id = $1"  
mysql -uroot -pmysql@ime merge_world -e "delete from player_blob_5 where account_id = $1"  
mysql -uroot -pmysql@ime merge_world -e "delete from player_info where account_id = $1" 
mysql -uroot -pmysql@ime merge_world -e "delete from hero where account_id = $1" 
