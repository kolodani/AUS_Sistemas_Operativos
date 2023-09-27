# "ONE-LINERS" UTILES

# awk 'NF > 0' # solo lineas no vacias

# ls -l archivos|
#    awk '{ x += $4 } ; END { print "total bytes: " x }'
# cantidad de bytes ocupados en un directorio

# awk '{ if (NF > max) max = NF}
#       END { print max }'
# imprime el numero maximo de campos entre los registros

# - awk '{ nlines++ } ; END { print nlines }'
# - awk 'END { print NR }'
# cantidad de lineas en archivo(s), wc -l

# awk '{ print NR, $0 }'
# numera toda linea de entrada, cat -n

# awk 'BEGIN { FS = ":" }
#            { print $1 | "sort" }' /etc/passwd
# imprime una lista ordenada de los nombres de usuario

# awk 'length($0) > 80'
# imprime las lineas que contengan mas de 80 caracteres