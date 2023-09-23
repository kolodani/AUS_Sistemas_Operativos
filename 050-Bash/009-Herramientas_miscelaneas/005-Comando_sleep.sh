# COMANDO SLEEP

# Provoca una pausa por un numero determinado de segundos
# Sintaxis:
#    sleep n
# Algunos tipos de UNIX permiten otras unidades de tiempo

# Ejemplos:
echo -e "Ingrese un valor!\a"
sleep 1
echo -ne "\a"
sleep 1
echo -ne "\a"

while :
do
    echo ===========================================
    date
    echo ===========================================
    who
    sleep 300       # 5 minutos
done >> logfile
