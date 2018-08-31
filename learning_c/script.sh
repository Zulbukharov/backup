#!/bin/bash

param1=$1
param2=$2
script_name=$0

if [[ "$param1" -eq "$param2" ]]; then
	echo "$param1 == $param2"
fi

echo "GROUP: $GROUPS"
echo "PWD: $PWD"
echo "hello $param1 from $script_name"
