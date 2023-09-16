# Ejemplo
echo "El reloj tiene un valor de $123"
# aqui el valor de salida sera
#     El reloj tiene un valor de 23
# esto sucede porque bash interpreta que $1 es una variable,
# la misma esta vacia y sigue con 23 para el comando echo

echo "El reloj tiene un valor de \$123"
# aqui el valor de salida sera
#     El reloj tiene un valor de $123
# esto sucede porque bash interpreta que el \ anula al signo de dolar
# y toma a todo como si fueran caracteres comunes para poder usarlos
# en el comando echo

echo "Es un vino con buen 'bouquet'"
# aqui el valor de salida sera
#     Es un vino con buen 'bouquet'
# esto sucede porque la comilla simple no se toma como mas que un caracter
# dentro del encomillado doble
