# SENTENCIA UNTIL

# until comando ;         # comando ~ condicion ~ comando test
# do
#     comandos(s)...
# done

# Sintaxis in-line:
# until comando ; do comando(s) ... ; done

# Ejemplo:
x=1
until [ $x -gt 10 ]       # while [ ! $x -gt 10 ]
do
    echo -n $x
    x=$(( $x + 1 ))
done
