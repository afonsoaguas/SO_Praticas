#!/bin/bash
echo -n "diga o nome: "
read nome
if echo $nome >> nome.txt ; then
echo "o nome $nome foi guardado"
else
echo "Problemas ao guardar $nome"
fi
