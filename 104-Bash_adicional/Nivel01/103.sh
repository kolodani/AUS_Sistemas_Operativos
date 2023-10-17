# Crear un script que permita el ingreso de una serie de números y determinar cuántos de ellos
# son pares, cuantos positivos y cuantos tienen 3 cifras

pares=0
positivos=0
tres_cifras=0
numeros=()                    # arreglo vacio

echo "Ingrese una serie de números (enter para terminar): "
read -a numeros

for i in ${numeros[@]}        # recorro el arreglo
do
    if [ $((i%2)) -eq 0 ]     # si es par
    then
        pares=$((pares+1))
    fi
    if [ $i -gt 0 ]           # si es positivo
    then
        positivos=$((positivos+1))
    fi
    if [ ${#i} -eq 3 ]        # si tiene 3 cifras
    then
        tres_cifras=$((tres_cifras+1))
    fi
done

echo "Cantidad de números pares: $pares"
echo "Cantidad de números positivos: $positivos"
echo "Cantidad de números con 3 cifras: $tres_cifras"
echo "Cantidad de números ingresados: ${#numeros[@]}"

exit 0
