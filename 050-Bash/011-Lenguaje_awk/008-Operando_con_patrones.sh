# OPERANDO CON PATRONES

# Expresiones de comparacion de patrones
#  x < y    verdad si x es menor que y
#  x <= y   verdad si x es menor o igual que y
#  x > y    verdad si x es mayor que y
#  x >= y   verdad si x es mayor o igual que y
#  x == y   verdad si x es igual que y
#  x != y   verdad si x no es igual que y
#  x ~ y    verdad si x concuerda con la expresion regular y
#  x !~ y   verdad si x no concuerda con la expresion regular y

# Operadores booleanos de patrones
#   !    no
#   ||   o
#   &&   y

# Ejemplos:41
# awk '$1 == 5000 { print $1, $2 }'
# awk '/100/ && /200/'
# awk '! /100/'
# awk '/sa/ || /srl/'