#!/bin/bash
if [ $# -eq 1 ]; then
	if [ -f $1 ]; then
		echo "$1 existe"
		if [ -x $1 ]; then
			echo "e é executável"
		fi
	else
		echo "$1 não existe"
	fi
else
	echo "SYNTAX: $0 <filename>"
fi
