#!/bin/bash
i=1
while [ $i -le 10 ]; do
	echo " $1 x $i = $(( 1 * $i ))"
	i=$(( $i + 1))
done
