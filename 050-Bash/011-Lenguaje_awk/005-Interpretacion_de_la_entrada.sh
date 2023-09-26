# INTERPRETACION DE LA ENTRADA

# awk consume la entrada en registros, divididos a su vez en campos

# Con las variables built-in se puede cambiar esto
# - variable RS (Record Separator): separador de registros
# awk 'BEGIN {RS="/"}; {print $0}' fechas
# //cambia RS antes de consumir entrada

# - RS="" indica que los registros seran separados por lineas en blanco

# - variable FS (Field Separator) separador de campos

# - variable FNR: almacena la cantidad de registros leidos hasta el
# momento del archivo actual, este valor se reinicia con cada archivo

# - variable NR: (Number of Records) guarda el numero total de
# registros leidos (no se reinicia automaticamente)

# - variable NF: (Number of Fields) guarda la cantida de campos
# en un registro

# Referenciando campos:
#  - $0: Registro completo
#  - $1: Primer campo del registro
#  - $2: Segundo campo del registro
#  -...
#  - $NF: Ultimo campo del registro
