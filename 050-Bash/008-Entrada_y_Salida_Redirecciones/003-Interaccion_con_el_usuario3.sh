# INTERACCION CON EL USUARIO 3

# printf
# Sintaxis:
#     printf cadena-de-formato... [parametro...]
# Es una mejora a echo, version limitada de la funcion printf() de C
# Se utiliza para formatear texto de salida

# Generalmente ubicado en /bin o /usr/bin

# Ejemplos:
PI=3.14159265358979
NRO=1234
Palabra1=Shell
Palabra2=Scripts

printf "Pi con dos cifras decimales = %1.2f\n" $PI
printf "Numero = \t%d\n" $NRO
printf "[%s\t%s]\n" $Palabra1 $Palabra2