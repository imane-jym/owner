VERSION_FILE="Version"
FILE_LIST="FileList.csv"
RESOURCE_DIR="/home/imane/WorkArea/card/Resource"
#set -x

cd $RESOURCE_DIR
rm -rf $FILE_LIST
FILES=`find -path *.svn* -prune -o -type f ! -name Version ! -name FileList.csv -print`
for i in $FILES
do
md5sum ${i:2} | awk  '{print $2"\n"$1}' >> $FILE_LIST
done
md5sum $FILE_LIST |awk '{print $1}' > $VERSION_FILE
