#!/bin/bash

#Retorna la longitud de la linea mas larga de un archivo de entrada

#Valide argumentos
[ $# -ne 1 ] && echo "Cant de argumentos invalida!! Debe enviar solo el nombre de un archivo!" && exit 1

#Validar la entrada, recibi un archivo?
INPUT_FILE=$1
[ ! -f "$INPUT_FILE" ] && echo "Ruta de archivo no valida!" && exit 2

[ ! -r "$INPUT_FILE" ] && echo "No se tiene permiso de lectura!" && exit 3

MAX_CHARS_LINE=0
MAX_LINE=0

echo "Recibi $1"
cat $INPUT_FILE

while read line 
do 
   if [${#line} -gt $MAX_CHARS_LINE ]
   then
      MAX_LINE=$line
      MAX_CHARS_LINE=${#line}
   fi
done < $INPUT_FILE 

echo
echo "La linea mas larga es"
echo $MAX_LINE
echo "y mide $MAX_CHARS_LINE"

#Si llego aca todo ok!!!
exit 0
