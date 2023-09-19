# EL COMANDO TEST

# evalua una expresion condicional
# $ test opcion expresion
# test retorna un 0 (true) o un 1 (false) luego de la evaluacion
# Una manera mas concisa esa mediante [...]
# $ [ opcion expresion]

# Ejemplos:
test 1 -gt 2
[ 1 -gt 2 ]      # espacios obligatorios [_ y _]

# Bash introdujo el comando extendido de test, [[...]], con un comportamiento
# mas familiar para los programadores
# [ -f /etc/passwd && -f /etc/group ]   # no aceptado
# [[ -f /etc/passwd && -f /etc/group ]] # ok

# las construcciones ((...)) y let... evaluan expresiones aritmeticas
# y teronan 0 (true) si el resultado es distinto de cero y 1 (false) en caso
# contrario

((1 > 2))
let 1 > 2