# SENTENCIA IF

# Sintaxis:
# if condicion1;
# then
#   comandos1
# elif condicion2;    #  opcional
# then                #  opcional
#   comandos2         #  opcional
# else                #  opcional
#   comandos2         #  opcional
# fi

# elif es una abreviatura de elseif

# if de manera linea:
# if condicion; then comandos1 else comandos2 fi

# ejemplo:
if grep saldo clientes > /dev/null   # grep -qs saldo clientes
then
    echo "clientes contiene al menos una ocurrencia de saldo."
elif grep deuda clientes > /dev/null
then
    echo "clientes contiene al menos una ocurrencia de deuda."
else
    echo "las palabras saldo y deuda no estan presentes en clientes"
fi
# en el ejercicio de ejemplo falta la palabras then despues del elseif
# lo que ocaciona un error.
