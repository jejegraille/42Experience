ldapsearch | grep 'cn:' | cut -d" " -f 3 | grep 'bon' | wc -l | sed "s/ //g"
