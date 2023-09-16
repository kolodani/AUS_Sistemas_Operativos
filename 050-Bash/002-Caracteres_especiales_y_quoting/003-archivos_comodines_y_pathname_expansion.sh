# COMODINES
# ?                    un caracter cualquiera
# *                    cualquier cadena de caracteres
# [...]                cualquier caracter dentro de los corchetes (conjunto)
# [!...]               cualquier caracter que no esté dentro de los corchetes

# CONJUNTOS
# [abc]                a, b o c
# [.,;]                punto, coma o punto y coma
# [a-c]                a, b o c
# [a-z]                Todas las minusculas
# [!0-9]               Ningun digito
# [0-9!]               Todos los digitos y el caracter !
# [a-zA-Z]             Todas las letras minusculas y mayusculas

# EXPANSION DE LLAVES (BRACE EXPANSION)
# prefijo{cadenas}sufijo
# echo ca{pa,ra,sa}s
# capas caras casas