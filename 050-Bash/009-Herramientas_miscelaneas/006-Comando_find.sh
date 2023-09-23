# COMANDO FIND

# comando muy poderoso, provee un mecanismo muy flexible para crear una lista de
# archivos que verifican ciertos criterios
# Sintaxis:
#    find directorio_partida opciones acciones

# Ejemplos:
# find / -name core -print          # -print es considerado por defecto
# find / -name '*core*'             # * ? [caracteres] [! caracteres]
# find / -type d
# find / -size +2000                # 2000 bloques de 512 bytes
# find / -mtime -5

#          +n  Modificados hace mas de n dias atras
#           n  Modificados exactamente hace n dias
#          -n  Modificados hace menos de n dias

#     -mtime <--> Modificacion
#     -atime <--> Acceso
#     -ctime <--> Creacion, permisos, propiedad

# find / -atime +100 -exec rm -i {} \;