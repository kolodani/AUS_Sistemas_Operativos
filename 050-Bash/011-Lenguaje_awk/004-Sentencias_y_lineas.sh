# SENTENCIAS Y LINEAS

# Cada linea de un programa awk es una sentencia o regla independiente

# Una sentencia puede ocupar mas de una linea dividiendola con
# nueva-linea detras de alguno de los caracteres:
# ,   {   ¿   :    ||   &&   do   else
# de otra manera la nueva-linea indicaria fin de sentencia

# Se puede cortar tambien con el caracter \ en cualquier punto
#  awk '/oferta de fin de mes/ \
#    {print $0}' lista-precios

# El caracter ; se utiliza para colocar mas de una sentencia en
# un misma linea
# awk '/100/ {print $0} ; /200/ {print $0}' impuestos
#
