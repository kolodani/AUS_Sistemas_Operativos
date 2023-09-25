# Ejercicio 3: Días de vida
# El usuario debera ingresar en formato dd-mm-aaaa la fecha en que nació, el script deberá retornar
# la cantidad de días transcurridos hasta la fecha.
# Nota: La fecha introducida debe ser valida, en caso contrario el programa aborta.

CONDICION=true
while $CONDICION
do
    echo "Ingrese el fecha en que nacio en formato dd-mm-aaaa (numeros):"
    read fecha
    if [[ $fecha =~ ^([0-9]{2}[-]){2}[0-9]{4}$ ]]
    then
        dia=${fecha:0:2}
        mes=${fecha:3:2}
        anio=${fecha:6:4}
        fecha=$mes/$dia/$anio
        date -d $fecha > /dev/null 2>&1
        valido=$?
        if [ $valido -eq 0 ]
        then
            fechaActual=$(date +"%m/%d/%Y")
            fechaActual=$(date -d $fechaActual +"%s")
            fecha=$(date -d $fecha +"%s")
            dias=$(( (fechaActual - fecha) / 86400 ))
            if [ $dias -gt 0 ]
            then
                echo "Usted tiene $dias dias de vida"
                CONDICION=false
            else
                echo "Fecha invalida, fecha de nacimiento mayor a la fecha actual"
            fi
        else
            echo "Fecha no valida"
        fi
    else
        echo "Formato de fecha incorrecta"
    fi
done

# 1) todo esta encerrado en un bucle que solo termina cuando se ingresa una fecha valida.
# 2) Primero se verifica que la fecha ingresada cumpla con el formato dd-mm-aaaa, si no es asi, vuelvo a empezar.
# 3) Si cumple con el formato, separo la fecha en tres variables: dia, mes y anio.
# 4) Guardo la fecha en la variable fecha en el formato mm/dd/aaaa, para ser evaluadas por el comando date.
# 5) Ejecuto el comando date con la nueva fecha, si no es valida vuelvo a empezar.
# 6) Si es valida, guardo en fechaActual la fecha actual en formato mm/dd/aaaa.
# 7) Guardo en fechaActual la fecha actual en formato segundos.
# 8) Guardo en fecha la fecha ingresada en formato segundos.
# 9) Resto fechaActual - fecha y lo divido por 86400, que es la cantidad de segundos que tiene un dia.
# 10) Si la cantidad de dias es mayor a 0, muestro el resultado por pantalla. Si no, vuelvo a empezar.