#!/bin/bash

echo "select editor: 1 2 3"

read editor

case $editor in
	1)
		/usr/bin/vim
		;;
	2)
		/usr/bim/emacs
		;;
	3)
		echo "3"
		;;
	*)
		exit 0
		;;
esac

