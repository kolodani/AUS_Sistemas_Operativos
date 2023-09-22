# Modularizacion y terminacion

# con source o con "." podemos incluir el codigo de otro script en el nuestro:
#!\bin\bash
source funciones.sh     # en funciones.sh se define suma
suma 1 3
suma 12 12312

# exit y return
# - exit status
# Es el valor que retorna la funcion
# Puede ser epecificado explicitamente por return, de otra manera sera el
# exit status del ultimo comando ejecutado. Se obtiene su valor mediante $?
# - return [n]
# Termina una funcion, el argumento estero opcional es retornado al script
# invocante como el exit status de la funcion y se asigna a $?

# Nota: El entero positivo mas grande que una funcion puede retornar es 255
# Las versiones superiores a 2.05b del bash no sufren de esta limitacion
