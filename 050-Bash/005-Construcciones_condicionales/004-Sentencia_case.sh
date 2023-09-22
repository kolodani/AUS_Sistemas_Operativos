# SENTENCIA CASE

# Sintaxis:
# case palabra in
#    patron1)comandos1 ;;
#    patron2)comandos2 ;;
#    ...         # el patron *) es (opcional) y se utilaza como "default"
# esac

# Ejemplo:
# fruta es igual a banana
fruta=banana

if [ "$fruta" = banana ] ; then
    echo "La banana es rica en potasio."
elif [ "$fruta" = kiwi ] ; then
    echo "El kiwi provee vitamina C."
elif [ "$fruta" = manzana ] ; then
    echo "La manzana es baja en calorias."
fi

# Con case
fruta=manzana

case $fruta in
    banana)     echo "La banana es rica en potasio." ;;
    kiwi)       echo "el kiwi provee vitamina C." ;;
    manzana)    echo "La Manzana es baja en calorias." ;;
esac
