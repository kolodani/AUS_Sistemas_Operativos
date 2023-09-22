# SENTENCIA WHILE 2

# Bucles anidados
# while condicion1 ;            # Bucle principal
#   do
#       comandos...
#       while condicion2 ;      # bucle anidado
#       do
#           comandos...
#       done
#       comandos...
#   done

# no hay retriccionesrelaciones con el nivel de anidacion
x=0
while [ "$x" -lt  10 ]  ;
do
    y="$x"
    while [ "$y" -ge 0 ] ;
    do
        echo "$y \c"
        y=$(( $y - 1 ))
    done
    echo $x
    x=$(( $x + 1 ))
done
