#!/bin/bash

# prints colored text
print_style () {

    if [ "$2" == "info\n" ] ; then
        COLOR="96m";
    elif [ "$2" == "success\n" ] ; then
        COLOR="92m";
    elif [ "$2" == "warning\n" ] ; then
        COLOR="93m";
    elif [ "$2" == "danger\n" ] ; then
        COLOR="91m";
    else #default color
        COLOR="0m";
    fi

    STARTCOLOR="\e[$COLOR";
    ENDCOLOR="\e[0m";

    printf "$STARTCOLOR%b$ENDCOLOR" "$1";
}

print_style "This is a green text\n" "success\n";
print_style "This is a yellow text\n" "warning\n";
print_style "This is a light blue with a \t tab\n" "info\n";
print_style "This is a red text with a \n new line\n" "danger\n";
print_style "This has no color\n";
