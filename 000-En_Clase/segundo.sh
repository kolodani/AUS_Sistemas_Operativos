#!/bin/bash

while [ $# -ne 1 ]
do
    if [ $1 -lt $2 ]
    then
        shift
    else
        echo "La secuencia no esta en orden"
        exit 0
    fi
done

echo "La secuencia esta ordenada"

exit 0


