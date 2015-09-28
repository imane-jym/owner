#!/bin/bash
#set -x

FILENAME="../../../doc/csv.txt"
BASEPATH="../../Resource/Config/"
DESCPATH="../../Resource/Config_client/"

for i in `sed 's/\r//g' $FILENAME`
do
	cp -f $BASEPATH$i $DESCPATH
done

cd $DESCPATH
svn up
svn add *
echo "============="
svn ci -m ""
