# COMANDO XARGS

# Acepta una serie de palabras desde la STDIN y dispone como argumentos
# para un comando dado
# Ejemplo:
#    cat lista_archivos | xargs rm
# Si el numero de archivos es demasiado grande xargs ejecuta rm varias veces
# Puede especificarse cuantos argumentos STDIN seran procesados como argumentos
# para el comando mediante la opcion -n
# cat lista_archivos | xargs -n 20 rm      # borrar de 20 en 20
# ls
# capitulo 1    capitulo 2    caratula
# notas         prologo
# ls | xargs -n 2 echo --
# -- capitulo 1 capitulo 2
# -- caratula notas
# -- prologo

# Problema
# rm a*
# rm: arg list too long
# ls | grep '^a' | xargs -n 20 rm