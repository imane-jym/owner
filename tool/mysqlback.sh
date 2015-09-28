#!/bin/bash
userid=$1
mysqldump -n -t -uroot -pmysql@ime merge_world player_blob_1 --where="account_id = $userid" >> /home/wuqi/tmp.sql
mysqldump -n -t -uroot -pmysql@ime merge_world player_blob_2 --where="account_id = $userid" >> /home/wuqi/tmp.sql 
mysqldump -n -t -uroot -pmysql@ime merge_world player_blob_3 --where="account_id = $userid" >> /home/wuqi/tmp.sql  
mysqldump -n -t -uroot -pmysql@ime merge_world player_blob_4 --where="account_id = $userid" >> /home/wuqi/tmp.sql  
mysqldump -n -t -uroot -pmysql@ime merge_world player_blob_5 --where="account_id = $userid" >> /home/wuqi/tmp.sql  
mysqldump -n -t -uroot -pmysql@ime merge_world player_info --where="account_id = $userid" >> /home/wuqi/tmp.sql    
mysqldump -n -t -uroot -pmysql@ime merge_world hero --where="account_id = $userid" >> /home/wuqi/tmp.sql    
