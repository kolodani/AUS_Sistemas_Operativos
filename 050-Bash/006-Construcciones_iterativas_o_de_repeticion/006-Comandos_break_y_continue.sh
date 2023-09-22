# COMANDOS BREAK Y CONTINUE

# Existe el riesgo de escribir bucles infinitos
# x=0
# while [ x -lt 10 ]         # Error, va $x !!!!
# do
#     echo $x
#     x=$(( $x + 1 ))
# done

# break finaliza el bucle que la contiene
# continue provoca un salto hasta la proxima iteracion
# a ambas construcciones pueden eventualmente tomar un parametro numerico
# break N ~ finaliza los bucles hasta el nivel N de anidacion

# Ejemplo:
while :
do
    read CMD
    case $CMD in
        [qQ]|[qQ][uU][iI][tT]) break ;;
    *) process $CMD ;;
    esac
done

