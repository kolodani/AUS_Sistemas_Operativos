# EJECUCION DE PROGRAMAS AWK

# En linea de comandos, eventualmente como parte de un pipeline
# awk 'programa' archivo...

# Como script
# awk -f script.awk archivo...

# Sin archivos de entrada aplica el programa a la entrada estandar
# (Ctrl-d) para terminar
# awk 'programa'   o awk -f script.awk

# Como ejecutable
#   #! /bin/awk -f
#   # Primer script
#   BEGIN {print "Hola Mundo"}
#
