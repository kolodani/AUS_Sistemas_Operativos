# SENTENCIA CASE 2

# Otro ejemplo
case $archivo in
    *.conf)        echo "$archivo es un archivo de configuracion" ;;
    *.gz|*.bz2)    echo "$archibo es un archivo comprimido" ;;
    *.[gif|jpg])   echo "$archivo es un archivo de imagen" ;;
    *)             echo "$archivo es un archivo no clasificado" ;;
esac
