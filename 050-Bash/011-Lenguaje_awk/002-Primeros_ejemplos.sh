# Primeros ejemplos

#   awk '/abc/ {print $0}' archivo

# Nota: barras/ y comillas '
# El patron o la accion pueden omitirse pero no ambos a la vez
# - patron omitido -> se realiza la accion para cada linea
# - accion omitida-> la accion por defecto es replicar la linea

# Ejemplos:
#  awk '{Print $0}' archivo        = cat archivo
#  awk '/abc/' archivo             = grep abc archivo

# Ejemplos mas elaborados:
# awk '/100/ {print $0}
#      /200/ {print $0}' cuotas_pagas impuestos
# Nota: si es una linea aparece tanto 100 como 200 se imprimira dos veces!

# ls -l | awk '$6=="Jun" { sum+=$5 } END { print sum }'
#
