# Ejercicio 5: Renombre masivo de archivos
# Crear un script que permita, dado un directorio como entrada, renombrar un conjunto de archivos que posean una extension determinada
# Por ejemplo:
# $ ls /directorio/*
# a.c b.c c.c x.c
#
# $ bash ejercicio005.sh
# ingrese un directorio: /directorio
# ingrese extension: .c
# Ingrese patron de renombre: programa
# Se renombra a.c a programa1.c
# Se renombra b.c a programa2.c
# Se renombra c.c a programa3.c
# Se renombra x.c a programa4.c
# Se muestra contenido:
# programa1.c programa2.c programa3.c programa4.c

#!/bin/bash
DIRECTORIO_ACTUAL=$(pwd)
BUCLEDIREC=true
while $BUCLEDIREC
do
    echo "Ingrese un directorio: (ej: ~/documentos/jorge/directorioDestino)"
    read DIRECTORIO
    if [ -d "$DIRECTORIO" ]
    then
        echo "Directorio Encontrado"
        cd $DIRECTORIO
        BUCLEDIREC=false
    else
        echo "Este directorio: "
        echo $DIRECTORIO
        echo "NO existe, intente con otro"
    fi
done

BUCLEEXTEN=true
while $BUCLEEXTEN
do
    echo "Ingrese extension: (ej: .c .hs .sh .txt)"
    read EXTENSION
    if [[ -n "$EXTENSION" && "$EXTENSION" == .* ]]
    then
        echo "Extension valida"
        BUCLEEXTEN=false
    else
        echo "Esta extension: "
        echo $EXTENSION
        echo "NO es valida, intente con otra"
    fi
done

BUCLEPATRON=true
while $BUCLEPATRON
do
    echo "Ingrese patron de renombre: (ej: si elige, nono, el resultado sera nono1.c)"
    read PATRON
    if [ -n "$PATRON" ]
    then
        echo "Patron elegido correctamente"
        BUCLEPATRON=false
    else
        echo "NO ingreso ningun patron de renombre, intentelo nuevamente"
    fi
done

CONTADOR=1
if [ "$BUCLEPATRON" == false ]
then
    for ARCHIVO in $(ls *$EXTENSION)
    do
        echo "Se renombra $ARCHIVO a $PATRON$CONTADOR$EXTENSION"
        mv $ARCHIVO $PATRON$CONTADOR$EXTENSION
        CONTADOR=$(($CONTADOR+1))
    done
else
    echo "ERROR: no se pudo realizar la tarea solicitada"
fi

echo "Se muestra contenido:"
ls
cd $DIRECTORIO_ACTUAL