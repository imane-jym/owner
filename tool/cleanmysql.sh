#/bin/bash

user=imane
passwd=imane
database=card_world

mysql -u$user -p$passwd  --default-character-set=utf8 -e "drop database $database; create database $database"
