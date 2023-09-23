# COMANDO EXPR

# Util para realizar operaciones aritmeticas enteras simples en notacion infija
# Sintaxis:
#    expr operando1 operador operando2

# Operadores:
#    +    suma
#    -    resta
#    \*   multiplicacion (operador quoted)
#    /    division entera
#   %     resto de la division

# expr requiere espacion para separar sus argumentos

# Ejemplos:
expr 3 + 2
# 5
expr "ABRIL" : '[A-G]*'
# 2
mail="daniel@mail.com"
[ expr"$mail":'.*' -eq expr"$mail":'.*@.*\..*']



