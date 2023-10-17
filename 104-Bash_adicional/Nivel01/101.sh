# Crear un script que reciba una cantidad de argumentos indefinida e indique si
# recibió una cantidad par o impar de argumentos.
# Considerar el uso de shift

#!/bin/bash

if [ $# -eq 0 ]             # Si no se reciben argumentos
then
    echo "No se recibieron argumentos"
fi

i=0
while [ $# -gt 0 ]          # Mientras haya argumentos
do
    i=$((i+1))            # Incremento el contador
    shift                   # Elimino el primer argumento
done

if [ $((i%2)) -eq 0 ]       # Par es verdadero, impar es falso
then
    echo "Se recibieron una cantidad par de argumentos"
else
    echo "Se recibieron una cantidad impar de argumentos"
fi

echo "La cantidad de argumentos recibidos fue: $i"