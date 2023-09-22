# Sentencia while

# Sintaxis:
# while comando ;     # comando ~ condicion ~ comando test
# do
#     comando(s)...
# done

# Sintaxis in-line:   while comando ; do comando(s)... ; done

# Ejemplo:
x=0
while [ $x -lt 10 ]
do
    echo -n $x
    x=$(( $x + 1 ))
done
