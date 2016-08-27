(cat $1|
grep -i "^nicolas";
cat $1|
grep -i "^bomber" ;)|
awk -F' ' '{print $3}' |grep '^[0-9]'


