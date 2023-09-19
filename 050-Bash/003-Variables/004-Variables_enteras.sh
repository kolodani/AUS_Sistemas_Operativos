# VARIABLES ENTERAS

# Los enteros son con signo (32 bits)
# Posibilidad de overflow
# No hay punto flotante
# El punto decimal lo toma como cadena

# para usar los numeros en punto flotante se usa bc
echo "2.35 + 56.90" | bc
echo "sqrt(2)" | bc
echo "sqrt(2.0)" |bc
echo "sqrt(2.000000000)" | bc
