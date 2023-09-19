# ARRAYS

# serie de casillas, cada una contiene una valor
# los elementos se acceden mediante indices
# los indices comienzan en 0 hasta mas de 5 mil billones
# son unicamente uni-direccionales

# Asignaciones:
colores[0]=rojo
colores[2]=verde
colores[1]=amarillo
colores=([2]=verde [0]=rojo [1]=amarillo)
colores=(rojo amarillo verde)
colores=(rojo [10]=amarillo verde)

# se puede declarar vicios explicitamente mediante
declare -a colores

# los atributos establecidos para el array (read-only) se aplican a todos los elementos

# Para referenciar un elemento: ${array[indice]}
echo 'No Pasar' es ${colores[0]}

# Para referenciar todos los elementos ${name[*]} o ${name[@]}
echo ${colores[*]}