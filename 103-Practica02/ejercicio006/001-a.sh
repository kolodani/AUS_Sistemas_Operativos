# Ejercicio 6: Verificar password
# a) Crear un script que tome como entrada dos archivos de texto usuarios.txt y
# claves.txt, ambos deberán contener una única palabra por línea. El primero
# contendrá nombres de usuario, mientras que el segundo claves de acceso en
# formato plano. Ninguno puede ser vacío y deben contener la misma cantidad de
# líneas (ambas condiciones deben ser validadas por el script).
# El script deberá generar un nuevo archivo passwd.txt que contendrá registros
# de la forma usuario:clave, donde usuario proviene del archivo usuarios.txt y
# clave del archivo claves.txt.

#!/bin/bash
DIRECTORIO_ACTUAL=$(pwd)
FILEU=usuarios.txt
FILEC=claves.txt
SEGUIR=false

if [[ -f "$FILEC" && -f "$FILEU" ]]
then
    SEGUIR=true
else
    SEGUIR=falso
    echo "No se encontraron los archivos usuarios.txt ni claves.txt"
fi

if [ "$SEGUIR" == true ]
then
    numeroUsuarios=$(wc -l < usuarios.txt)
    numeroClaves=$(wc -l < claves.txt)
    patron=" "
    contadorEspacios=0

    if [[ "$numeroUsuarios" == "$numeroClaves" && "$numeroUsuarios" != 0 ]]
    then
        input="$DIRECTORIO_ACTUAL/$FILEU"
        while IFS= read -r line
        do
            if [[ $line =~ $patron ]]
            then
                contadorEspacios=$((contadorEspacios+1))
            fi
        done < "$input"

        input="$DIRECTORIO_ACTUAL/$FILEC"
        while IFS= read -r line
        do
            if [[ $line =~ $patron ]]
            then
                contadorEspacios=$((contadorEspacios+1))
            fi
        done < "$input"

    else
        echo "cantidad de registros nula o dispar entre archivos"
        SEGUIR=false
    fi
fi

if [[ "$SEGUIR" == true && "$contadorEspacios" == 0 ]]
then
    if [ -f "$DIRECTORIO_ACTUAL/passwd.txt" ]
    then
        rm "$DIRECTORIO_ACTUAL/passwd.txt"
    else
        touch "$DIRECTORIO_ACTUAL/passwd.txt"
    fi

    input="$DIRECTORIO_ACTUAL/$FILEU"
    input2="$DIRECTORIO_ACTUAL/$FILEC"
    while IFS= read -r line
    do
        read -r line2 <&3
        echo "$line:$line2" >> "$DIRECTORIO_ACTUAL/passwd.txt"
    done < "$input" 3< "$input2"
else
    echo "No se pudo crear el archivo passwd.txt"
fi