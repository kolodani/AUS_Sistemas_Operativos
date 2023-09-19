# OPERADORES LOGICOS

# negacion        !expr
# and logico      expr1 && expr2
# or logico       expr1 || expr2
# asociatividad   ( expr ) utilizado para forzar evaluacion

# Ejemplo:
echo -n "Hola" && echo " Mundo"
# Hola Mundo
false && echo " Mundo"
# (nada, evalua a 1)
true && echo " Mundo"
# Mundo

echo -n "Hola" || echo " Mundo"
# Hola
false || echo " Mundo"
# Mundo
true || echo " Mundo"
# (nada, evalua a 0)
