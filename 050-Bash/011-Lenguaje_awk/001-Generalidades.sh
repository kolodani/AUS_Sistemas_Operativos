# GENERALIDADES

# Forma general
# awk 'Programa' archivo ...

# Un programa awk consiste en una o mas reglas de la forma
# patron { accion } # las llaves separan la acciones de los patrones
# patron { accion }

# Perspecriva awk de la entrada
#   archivo = secuencia de lineas o registros
#   registros = secuencias de campos

# awk consume cada archivo... registro por registro analizando si
# entre sus campos "esta presente" el patron, si es asi se apica las
# accion sobre este registro

# awk es case sensitive

# awk no altera el contenido de los archivos ...

