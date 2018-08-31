cat SHELLCODE\ CALC.txt | sed s,\\\\\x,,g | sed s,\"\,,g | tr -d "[:space:]" | sed s,char\$\buf\=\,,g | tr -d "." | tr -d ";" > e  
