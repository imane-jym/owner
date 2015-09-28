#!/bin/bash
rsafile="~/.ssh/id_rsa.pub"
desc=$1
mkdir -p ~/.ssh
ssh-keygen -t rsa
ssh-copy-id -i ~/.ssh/id_rsa.pub "$desc" 
ssh $1
