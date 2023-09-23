# Ejercicio 2: Día de cumpleaños
# El usuario debera ingresar en formato dd-mm-aaaa la fecha en que nació, el script deberá retornar
# el día de la semana de dicha fecha.
# Nota: La fecha introducida debe ser valida, el script verificará esto, en caso de fecha inválida el
# script aborta comentando dicha situación.

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
            diaDeLaSemana=$(date -d $fecha +"%A")
            echo $diaDeLaSemana
            CONDICION=false
        else
            echo "Fecha no valida"
        fi
    else
        echo "Formato de fecha incorrecta"
    fi
done

# 1) encierro todo en un bucle hasta que se ingrese una fecha valida, osea, con el formato correcto
# y que sea una fecha real.
# 2) a la fecha ingresada la comparo con una expresion regular, la misma acepta solo numeros separados
# por guiones, dd-mm-aaaa, si no cumple con el formato, vuelvo a empezar.
# 3) pasado el primer filtro, separo la fecha en tres variables: dia, mes y anio.
# 4) la guardo en la variable fecha en el formato mm/dd/aaaa, para ser evaluadas por el comando date.
# 5) ejecuto el comando date con la nueva fecha, si no es valida vuelvo a empezar.
# 6) pasado el segundo filtro, guardo en diaDeLaSemana el nombre del dia de la semana de la fecha ingresada.
# 7) Finalmente muestro el resultado por pantalla.