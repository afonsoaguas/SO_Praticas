#!/bin/bash

echo "Estou a pensar num número entre 1 e 100. Quer adivinhar?"
echo ""
echo -n "S:N? "
read ans
if [ "$ans" = "S" ]; then
	n=$(( $RANDOM % 100 + 1 ))
	i=1

	while :; do
		echo "Introduza a sua tentativa #$i (0 para desistir):"
		read guess

		if (( $guess == $n )); then
			echo "Parabéns, acertou em $i tentativas!"
			exit 0
		elif (( $guess == 0 )); then
			echo "Não adivinhou em $i tentativa(s), o número era $n."
			exit 1
		elif (( guess < n )); then
			echo "Muito pequeno"
		else
			echo "Muito grande"
		fi

		i=$(( i + 1 ))
	done

else
	echo "Sou mais esperto que tu!"
fi
