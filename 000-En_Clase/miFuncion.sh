#!/bin/bash

mifunc () {
    P=$1
    echo "HOLA"
    echo "Subiendo al piso $P"
}

PISO=$1
DPTO=$2

mifunc $PISO

exit 0
