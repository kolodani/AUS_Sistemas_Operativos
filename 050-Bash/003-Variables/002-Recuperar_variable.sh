#!/bin/bash
dosmil=numero
numero=2000
echo $dosmil           #Referencia directa
eval echo \$$dosmil    #Referencia indirecta
