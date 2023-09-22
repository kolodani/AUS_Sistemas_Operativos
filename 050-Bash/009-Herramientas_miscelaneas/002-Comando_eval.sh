# COMANDO EVAL

# Puede utilizarse cuando se desea que el shell reprocese la linea de
# comandos por segunda vez

# Sintaxis:
#   eval cualquier_comando

# Ejemplo:
SALIDA="> out.file"
echo hola $SALIDA
# hola > out.file
eval echo hola $SALIDA
# se creo el archivo out.file

# Luego se puede cambiar el valor original de SALIDA y asi afectar a
# todas las lineas que comiencen con eval y contengan $SALIDA

# Util para el caso en que se desea componer una linea de comandos
# utilizando metacaracteres contenidos en variables o producidos
# debido a sustitucion de comandos