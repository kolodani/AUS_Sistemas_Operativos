# Ejercicio 001: Comando tac
# b) Crear un script que imprima el contenido de un archivo de texto de manera invertida, es decir
# primero la última línea, luego la penúltima y así sucesivamente hasta imprimir en último lugar la
# primer línea.

FILE="./ejemplo.txt"                          # guardo el nombre del archivo en una variable

i=$(cat $FILE | wc -l)                        # i = líneas del archivo

echo "El archivo ordenado: "
cat $FILE                                     # imprimo el archivo ordenado

echo "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"

echo "El archivo desordenado: "
while [ $i -ne 0 ]                            # mientras i es distinto de 0 (mientras haya líneas)
do
    head -n $i $FILE | tail -n 1
    i=$(($i - 1))
done

#  head -n $i $FILE | tail -n 1
# hago head del archivo hasta la línea i, esto me muestra las primeras i líneas del archivo
# a eso le hago tail -n 1, esto me muestra la última línea de las primeras i líneas del archivo
# osea en cada ciclo tomo todas las i lineas y me quedo con la ultima de ellas y la imprimo
# luego decremento i y vuelvo a hacer lo mismo hasta que i sea 0