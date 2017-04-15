ls  -l | awk -F " " '{print $NF}'  | sed  -n /\\.c/p  > list_c
