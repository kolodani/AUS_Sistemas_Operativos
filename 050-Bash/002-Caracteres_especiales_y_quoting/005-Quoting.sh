# EJEMPLOS
echo 2 * 3 > 1 es cierto
# No produce salida, que paso?
# lo que sucedio es que el shell interpreto el * como un comodin y lo expandio a
# todos los archivos del directorio actual. ademas, el > redirecciono la salida
# estandar a un archivo llamado 1. el resto de la linea se interpreto como
# argumentos para el comando echo.


echo El valor de este producto es $120
# El valor de este producto es
# $120 es una variable, el signo $ indica que se trata de una variable
# el shell interpreta el $ y lo expande a su valor, en este caso, vacio.


ls [Aa]+
# [Aa]+ es un patron de busqueda, el shell lo expande a todos los archivos
# que comiencen con A o a y tengan al menos un caracter mas.