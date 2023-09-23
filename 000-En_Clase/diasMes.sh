#!/bin/bash

PS3='Ingrese un numero para elegir el mes: '
echo
select mes in "ENERO" "FEBRERO" "MARZO" "ABRIL" "MAYO" "JUNIO" "JULIO" "AGOSTO" "SEPTIEMBRE" "OCTUBRE" "NOVIEMBRE" "DICIEMBRE"
    do
        [ -e "$mes" ] && continue
        echo "Ahora ingrese el numero del anio: " $anio
        read anio
        dias=$(cal $(date +"$mes $anio") | awk 'NF {DAYS = $NF}; END {print DAYS}') 
        echo "El mes tiene $dias dias"
        break
    done
exit 0
