# INTERACCION CON EL USUARIO

# read
# Sintaxis:
#   read [-a aname]  [-p prompt] [-er] [variable...]
# Lee el valor de una variable desde STDIN
# Con la opcion -a permite leer variables tipo array

# Ejemplos:
#!/bin/bash
echo -n "Ingrese su nombre: "
read name
echo "name = $name"

echo -n "Ingrese su fecha de nacimiento (dd mm aaaa): "
read dia mes anyo
echo "date of birth = $dia $mes $anyo"

# un read sin variable(s) asociada(s) provoca que se establezca REPLY
# Algunas opciones de read
# -t            Entrada temporizada
# -p promt      Permite establecer un prompt para guiar la entrada
# -n N          Aceptar solo N caracteres de la entrada
