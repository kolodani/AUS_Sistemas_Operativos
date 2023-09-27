# SENTENCIAS PRINT Y PRINTF 2

# print formato item1, item2, ... # los () son necesarios a veces
# formato es una cadena que indica como deben imprimirse los items
# es una version inferior a la funcon printf() de C
# no coloca automaticamente un caracter nueva-linea al final
#    printf "%f\n", $2

# Ejemplos:
# $ awk '{ print "(%-10s, %d, %c)\t", $1, $3, $4 }' # inventario
# $ awk 'BEGIN { format = "%-10s %s\n"
#                printf format, "Nombre", "Numero"
#                printf format, "------", "------" }
#        { printf format, $1, $2 }' # archivo_con_datos

# Redirecciones
# $ awk '{ print $2 > "lista-telefonos"
#          print $1 > "lista-nombres" }' # archivo_con_datos

# $ awk '{ print $1>"nombres-desordenados"
#          print $1 | sort-r > "nombres-ordenados" }' # archivo_con_datos