# Ejercicio 4: Compresión tar.bz2
# Escribir un programa que solicite al usuario la siguiente información:
# – El path absoluto a un directorio que contenga archivos
# – El nombre dedicado al archivo comprimido
# Con esta información se debe crear un archivo comprimido .tar.bz2 con todo el contenido del
# directorio de entrada.
# Al finalizar el script debe mostrar el tamaño total del directorio sin comprimir y el tamaño del
# archivo comprimido.
# Nota: La existencia del directorio de entrada debe ser validada, si no existe el programa aborta.

#!/bin/bash
DIRECTORIO_ACTUAL=$(pwd)

CONDICION=true
while $CONDICION
do
    echo "COMPRESOR DE ARCHIVOS:"
    echo "Ingrese el path absoluto del directorio a comprimir: (~/Documents/repositorio/directorio_del_archivo)"
    read DIRECTORIO
    if [ -d "$DIRECTORIO" ]
    then
        echo "Ingrese que nombre le dara al archivo comprimido"
        read NOMBRE
        cd $DIRECTORIO
        tar -cvjf $NOMBRE.tar.bz2 *
        if [ -f "$NOMBRE.tar.bz2" ]
        then
            echo "El tamaño del directorio sin comprimir es: $(du -sh $DIRECTORIO)"
            echo "El tamaño del archivo comprimido es: $(du -sh $NOMBRE.tar.bz2)"
            mv $NOMBRE.tar.bz2 $DIRECTORIO_ACTUAL
            CONDICION=false
        else
            echo "Error: El archivo no se pudo comprimir"
        fi
        cd $DIRECTORIO_ACTUAL
    else
        echo "El directorio no existe, intente con otro"
    fi
done