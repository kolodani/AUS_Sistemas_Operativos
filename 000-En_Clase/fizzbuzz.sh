#!/bin/bash

echo "Bienvenido a Fizz-Buzz"
NUMERO=1

while [ $NUMERO -lt 100 ]
do
    CONDICION=0
    if [[ $((NUMERO%3)) -eq 0 ]]
    then 
        echo -n "Fizz"
        CONDICION=10
    fi
    if [[ $((NUMERO%5)) -eq 0 ]]
    then 
        echo -n "Buzz"
        CONDICION=10
    fi
    if [ $CONDICION -lt 5 ]
    then
        echo -n "$NUMERO "
    fi
    NUMERO=$(($NUMERO + 1))
done
