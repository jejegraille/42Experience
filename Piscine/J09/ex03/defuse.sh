echo  `stat -f +%a bomb.txt` ;
export bombtime=$((`stat -f +%a bomb.txt` -1));
touch -a `echo $bombtime`  bomb.txt;
echo $bombtime;
echo `stat -f +%a bomb.txt`;

