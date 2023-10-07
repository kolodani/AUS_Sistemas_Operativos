#!/bin/bash

source mifun.sh

[ $# -ne 2 ] && echo "Cantidad de argumentos invalida" && exit 1
NRO=$1

[[ ! $NRO =~ ^[0-9]+$ ]] && echo "Argumento no es un numero" && exit 1

RUTA=$2
[ ! -d $RUTA ] && echo "Error dir no existe" && exit 2

# Permiso de escritura en la ruta
[ ! -w $RUTA ] && echo "Error no se puede escribir el directorio" && exit 3

mkdummyFile $NRO $RUTA

exit 0

