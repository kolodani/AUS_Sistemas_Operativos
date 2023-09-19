# OPERADORES DE COMPARACION DE ENTEROS

# -eq    es igual a                       [ "$a" -eq "$b" ]         EQ
# -ne    es distinto a                    [ "$a" -ne "$b" ]         NE
# -gt    es mayor que                     [ "$a" -gt "$b" ]         GT
#  >     es mayor que                     [ "$a" > "$b" ]           GT
# -ge    es mayor o igual que             [ "$a" -ge "$b" ]         GE
#  >=    es mayor o igual que             [ "$a" >= "$b" ]          GE
# -lt    es menor que                     [ "$a" -lt "$b" ]         LT
#  <     es menor que                     [ "$a" < "$b" ]           LT
# -le    es menor o igual que             [ "$a" -le "$b" ]         LE
#  <=    es menor o igual que             [ "$a" <= "$b" ]          LE

# Ejemplos:
var1=21; var2=22
(("$var1" <= "$var2"))
echo $?
# 0
[ "$var1" -le "$var2" ]
echo $?
# 0
(("$var1" > "$var2"))
echo $?
# 1