#!/bin/bash

gcc 01_bash_system.c -o time
gcc 02_gtk_window.c -o win `pkg-config --libs gtk+-3.0` `pkg-config --cflags --libs gtk+-3.0`
echo "successfully compiled"
./time | ./win
