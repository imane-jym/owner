#!/bin/bash
rsafile="~/.ssh/id_rsa.pub"
desc=$1
mkdir -p ~/.ssh
if [ ! -f ~/.ssh/id_rsa.pub ]
then
	ssh-keygen -t rsa 
fi
ssh-copy-id -i ~/.ssh/id_rsa.pub $desc 
ssh $1
