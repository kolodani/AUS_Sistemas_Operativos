# INTERACCION CON EL USUARIO 2

# echo
# Sintaxis:
#     echo [-neE] [arg ...]
# Imprime texto por STDOUT
# Por defecto imprime un caracter nueva-linea, con -n se suprime
# Con la opcion -e intrepreta caracteres especiales
#     \b       backspace
#     \c       suprime nueva-linea
#     \f       form-feed
#     \n       nueva-linea
#     \r       retorno de carro
#     \t       tabulador
#     \\       backslash
#     \nnn     caracter con codigo octal nnn

# Ejemplos:
a=`echo "HOLA" | tr A-Z a-z`
echo $a
# hola
echo -e "Nueva \nLinea"
# Nueva
# Linea