#!/bin/bash

p1=$1
p2=$2
p3=$3

printf "press 1 to start "
printf "\033[31;1m

 ██▓███   ██▀███  ▓█████   ██████   ██████    ▓█████  ███▄    █ ▄▄▄█████▓▓█████  ██▀███
▓██░  ██▒▓██ ▒ ██▒▓█   ▀ ▒██    ▒ ▒██    ▒    ▓█   ▀  ██ ▀█   █ ▓  ██▒ ▓▒▓█   ▀ ▓██ ▒ ██▒
▓██░ ██▓▒▓██ ░▄█ ▒▒███   ░ ▓██▄   ░ ▓██▄      ▒███   ▓██  ▀█ ██▒▒ ▓██░ ▒░▒███   ▓██ ░▄█ ▒
▒██▄█▓▒ ▒▒██▀▀█▄  ▒▓█  ▄   ▒   ██▒  ▒   ██▒   ▒▓█  ▄ ▓██▒  ▐▌██▒░ ▓██▓ ░ ▒▓█  ▄ ▒██▀▀█▄
▒██▒ ░  ░░██▓ ▒██▒░▒████▒▒██████▒▒▒██████▒▒   ░▒████▒▒██░   ▓██░  ▒██▒ ░ ░▒████▒░██▓ ▒██▒
▒▓▒░ ░  ░░ ▒▓ ░▒▓░░░ ▒░ ░▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░   ░░ ▒░ ░░ ▒░   ▒ ▒   ▒ ░░   ░░ ▒░ ░░ ▒▓ ░▒▓░
░▒ ░       ░▒ ░ ▒░ ░ ░  ░░ ░▒  ░ ░░ ░▒  ░ ░    ░ ░  ░░ ░░   ░ ▒░    ░     ░ ░  ░  ░▒ ░ ▒░
░░         ░░   ░    ░   ░  ░  ░  ░  ░  ░        ░      ░   ░ ░   ░         ░     ░░   ░
               
                
               ░▓█████████████████████░
              ░▓█████████████████████▒█░█░
           ░░░░▓███████████████████▓▓▒▓░░░▓░
          ░░░░░▓▓██████▒▒██████▓▓██▒▒░░░░▒█▒░░
          ░█░░▓▓▓▒░▓░▒▒░▓▒▒██░█▒█░▓█▓▓░█░░▓██░
         ░█░▓▓▓▓▓░██░▓░▓█░▓█▒█▒█▓█░██▒▒█████▓▒░
        ░███▓▒▒▒▒▒█▒▓▒▓▓██▓█▓█▒█░░█▒████▓██▓██░
        ░███░█▒█████▓▓█▒███▒██▓░ ░▓█░▓█████████░   ░
        ░█████▒████▓▓███▒▓░░▒░░█▓▓▒█▒░░▓███████░
        ░████▓███░░░░░░░░░░▒▒▒▓░░░░▒▒░░░░██████░
        ░███▓▒░            ░▒░▓░▓▒░▓░▒▒░▒▓█████░
        ░██▓▓▓▒░░   ░░    ░░░▓ ▓▓░░░▒░░▓▓░█████░
        ░██▓██░ █░▓█░░    ░▒█▒▓█░░▓░░▒░▓▓░█▒███▓░
        ░█████░ ░▓▓░   ░░ ░░▓▓░░█░░░▒░▓░░▒██░███▒
        ░███▒█▒       ░░▒ ░▓░▒░░░▒▓█▓▒░░░▒█░░████░  ░
        ▒████░▓░       ░░   ░▒░  ░▓░  ░░░░░░█████░
       ░██████░▓               ░░░░░▒▒░ ░░░███████░
      ░▓███████░░                      ░██████████▒░
     ░█▓█▓█▓██████       ▒░░░▓░       ░████████████▓░
  ░░▒▓ ░█░▒████████░░░             ░░██████████░██░░█░
  ░░░  ░▒░▒▒██████████▓░ ░      ░░█░░█████████▒░▒░▒░░▒
  ░░      ░░██░██▓█████░█▓█░░░▒▒▒░░ ░████▒██▓░░░▒░░▒ ░
  ░       ░▒░░░░░░░░▓▒█░ ▒▓▒▒▒░░    ░█▒▒░▒▒▒░░
         ░░           ░▒░░░     ░░░▒░░░░
                   ░░░░▒░ ▒░   ░░░░▒  ▒░
              ░░░▒     ░▒░ ░  ░▒  ░░     ░▓░░░
      ░░░░░░░░░░   ░░░░░░░░   ░▒           ░░░░▓░░░░
    ░░░░           ░░░░▒▒░▒   ░░▒░░░               ░░▓▒
   ░                     ░░░░░░░                       ░▓░
  ░                   ░░░                                ░░
 "
read -n 1 start

if [[ $start = "" ]]
then
	echo ""
	./a.out $1 $1 $3
else
	printf "
	\033[31;1m       you pressed wrong key\n"
fi

#/a.out 10 3 4 # ./a.out [num of lists] [find] [remove]
#/a.out 10 3 4 # ./a.out [num of lists] [find] [remove]