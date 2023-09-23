#!/bin/bash

PS3="Ingrese Opcion:"

while :
do
    select x in Salir Saludar Fecha_Hora Cal2023
    do
        [ -z "$x" ] && echo "Opcion Incorrecta!!!" && break
        case $x in
            Salir) exit 0 ;;
            Saludar) echo "Hola AUS!!!" $REPLY; break ;;
            Fecha_Hora) date; break ;;
            Cal2023) cal 2023; break ;;
            # *) echo "Opcion invalida, lea las opciones"; break ;;
            # no me sirve mas por la comprobacion antes del case
        esac
    done
    sleep 3
    clear
done

exit 0
