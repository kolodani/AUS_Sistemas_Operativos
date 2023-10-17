# Crear un script para mostrar por pantalla los números impares del 1 al n.
# n es un argumento recibido por la línea de comandos y debe ser un entero positivo.

if [ $1 -lt 0 ]
then
    echo "El número debe ser positivo"
    exit 1
else
    for i in $(seq 1 $1)
    do
        if [ $(($i % 2)) -ne 0 ]
        then
            echo -n "$i "
        fi
    done
fi