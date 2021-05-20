#!/bin/bash

echo "eis o que posso dizer sobre o $1"
case $1 in
	boavista) echo "Porto";;
	sporting|benfica) echo "Lisboa";;
	iscte*) echo "Fica em Lisboa";;
	*) echo "desconheço a cidade";;

esac
