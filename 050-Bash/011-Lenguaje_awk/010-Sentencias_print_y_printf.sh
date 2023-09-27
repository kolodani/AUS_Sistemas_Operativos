# SENTENCIAS PRINT Y PRINTF

# Son de las mas utilizadas como accion
# print (item1, item2, ...)  # los parentesis son necesarios a veces
# print     = print $0
# print ""  = linea en blanco

# Separadores de salida
# - OFS Output Field Separator    (espacio por defecto)
# - ORS Output Record Separator   (nueva-linea por defecto)

# Ejemplo:
# $ awk 'patron { print }' a_ent > a_sal
# // $ grep patron a_ent > a_sal
# $ awk 'BEGIN { print "linea uno\nlinea dos" }'
# linea uno
# linea dos
# $ date | awk '{ print $1,$2 }'
# Ene 14
# $ date | awk '{ print $1,$2 }
# Ene14
# $ date | awk '{ print "Precios Unitario"
#                 print "======= ========" }' factura
# # awk 'BEGIN { OFS = ";" ORS = "\n\n" }
#                 { print $1, $3, $NF }' listado