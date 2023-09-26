# PATRONES

# /expresion regular/
# - El texto del registro de entrada concuerda con la expresion regular
# Ejemplos:
#  /texto/               Concordancia con texto
#  /x+/                  Una o mas ocurrencias de x
#  /x?/                  Una o ninguna ocurrencia de x
#  /x|y/                 Tanto x como y
#  (string)              Agrupa una cadena para usar con + o ?
#  $1 ~ /exp-reg/        Concordancia de campo

# Expresion
# - Vale cuando su valor es distinto de 0 (si representa un numero) o no nulo (si representa una cadena)
# - expresion se evalua cada vez que la regla se chequea contra un nuevo registro
# - Puede ser una expresion de la forma $N, que sependa del registro actual