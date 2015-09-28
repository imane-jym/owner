#!/bin/bash
address="jiangyiming@61.174.12.216"
password="yim@821.me"

expect -c "
set timeout -1
spawn ssh -o StrictHostKeyChecking=no $address
expect *assword*
send $password\n
spawn ls -lh
expect eof
"

echo 'ssss'
