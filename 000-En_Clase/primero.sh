#!/bin/bash
# si no hay 3 argumentos sale
[ $# -ne 3 ] && exit 1

var1=$1
var2=$2
var3=$3

if [ $var1 -gt $var2 ]
then
    aux=var1
    var1=var2
    var2=aux
fi

suma=$((var1+var3))

if [ $suma -eq $var2 ]
then
    echo "El salto es esta correcto"
else
    echo "Salto erroneo"
fi

exit 0
