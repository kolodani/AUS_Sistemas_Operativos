# Comando set

# el comando set despliega las variables de she junto a sus valores
# Permite definir el comportamiento del bash (opciones)

# Sintaxis:
# set [-abdefhkmntuvxBCHP] [(-|+) o opcion] [argumento ...]

# -n     lee comandos pero no los ejecuta, util para depurar sintacticamente scripts
# -v     Muestra las lineas de entrada del shell tal cual son leidas
# -x     Muestra una traza de un comando y sus argumentos luego de aplicar expansiones

# su uso habitual es para establecer los parametros posicionales
set `date`
echo Hora actual: $5