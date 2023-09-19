# COMANDO GETOPTS

# sirve para tratar con opciones multiples y complejas
# puede utilizarse como una codicion en un bucle while, dada la especificacion
# del formato de opciones (validez y argumentos), en el cuerpo del while se procesan

# Sintaxis:
# getopts cadena variable
# - cadena contiene letras (opciones) y :'s (argumentos)
# - variable que almacena el argumento de la opcion que esta analizandose

# ejemplo

while getopts ":ab:c" opt; do
    case $opt in
        a) procesar la opcion -a ;;
        b) procesar la opcion -b
            $OPTARG es el argumento de la opcion ;;
        c) procesar la opcion -c ;;
        \?) echo 'usage: alice [-a] [-b barg] [-c] args...'
        exit 1
    esac
done