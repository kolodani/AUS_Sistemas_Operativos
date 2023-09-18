#    $find / -name programa.c
#
# Nombre comando     = find <-> $0
# 1er argumento      = /    <-> $1
# 2do argumento      = -name <-> $2
# 3er argumento      = programa.c <-> $3
# Mas argumentos     = $4, $5, $6, ..., ${10}, ${11}, ${12}, ...

# - basename  $0: nombre del comando
# - dirname   $0: directorio donde se encuentra el comando
# - shift: rota los argumentos hacia la izquierda $i <- ${i+1}, $0 no cambia

# Variables argumento especiales
# - $# : numero de argumentos pasados al comando
# "$*" : todos los argumentos "$*" = "$1 $2 $3 $4 $5 $6 $7 $8 $9"
# "$@" : todos los argumentos "$@" = "$1" "$2" "$3" "$4" "$5" "$6" "$7" "$8" "$9" separados por espacio ' '
# $_: comando previo o anterior
# $-: flags pasadas al script
# $$: pid del proceso shell
# $!: pid del ultimo proceso ejecutado en segundo plano
# $?: exit status
# $* y $@ difieren solo cuando estan encerradas entre comills dobles
