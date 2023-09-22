# TABLA DE OPERADORES DE REDIRECCION
# Operador	       Descripción
# cmd1 | cmd2	   Pipe, toma STDOUT de cmd1 y lo pasa como STDIN a cmd2
# > arch           STDOUT a arch, si arch existe lo reemplaza
# < arch           Toma STDIN desde arch
# >> arch          STDOUT a arch, escribe al dinal si arch existe
# >| arch          Fuerza STDOUT a arch aun si noclobber esta establecido
# n>| arch         Igual para el archivo cuyo descriptor de archivo es n
# <> arch          Usa arch como STDIN tanto como STDOUT
# n<> arch         Usa arch como STDIN tanto como STDOUT para el descriptor de arch n
# << label         Here document
# n> arch          Direcciona el descriptor de archivo n a arch
# n< arch          Toma el descriptor de archivo m desde arch
# n>> arch         Direcciona el descriptor de archivo n a arch, agrega datos al final de arch si ya existe
# n>&              Duplica STDOUT a descriptor de archivo n
# n<&              Duplica STDIN a descriptor de archivo n
# n>&m             El descriptor de archivo n se transforma en una copia del descriptor de archibo de salida m
# n<&m             El descriptor de archivo n se transforma en una copia del descriptor de archivo de entrada m
# &> arch          Direcciona STDOUT y STDERR a arch
# <&-              Cierra STDIN
# >&-              Cierra STDOUT
# n>&-             Cierra STDOUT del descriptor de archivo n
# n<&-             Cierra STDIN del descriptor de archivo n