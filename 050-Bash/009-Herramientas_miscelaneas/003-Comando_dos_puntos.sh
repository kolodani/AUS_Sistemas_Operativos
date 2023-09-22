# COMANDO :

# No hace nada, retorna 0 indicando ejecucion de comando exitoso
# Puede utilizarse con seguridad en cualquier lugar que se requiera un
# comando por cuestiones puramente sintacticas

# Ejemplo:
if [ -x $CMD ]
then
    :
else
    echo Error: $CMD no es ejecutable >&2
fi

# Construccion de bucles infinitos
while :               # mas eficiente que while true
do
    echo "Ingrese una palabra: \c"
    read ENTRADA
    [ "$ENTRADA" = "basta" ] && break
done

# el uso de : provoca que el shell evalue sus argumentos, esto es util
# para invocar sustitucion de variables