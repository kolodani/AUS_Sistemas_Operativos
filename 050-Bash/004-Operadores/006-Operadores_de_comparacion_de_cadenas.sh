# OPERADORES DE COMPARACION DE CADENAS

#  =      es igual a          [ "$a" = "$b" ]
#  ==     es igual a          [ "$a" == "$b" ]
#  !=     es distinto a       [ "$a" != "$b" ]
#  <      es menor en orden lexicografico
#                             [[ "$a" < "$b" ]]
#                             [ "$a" \< "$b" ]
#  >      es mayor en orden lexicografico
#                             [[ "$a" > "$b" ]]
#                             [ "$a" \> "$b" ]

# Nota: "<" y ">" necesitan ser escapados dentro de []

# ${#var}                  retorna la longitud del valor de var
# expr length $var         retorna la longitud del valor de var
# expr "$var" : '.*'       retorna la longitud del valor de var
# -z                       la cadena es "null" (tiene longitud cero)
# -n                       la cadena no es "null"
