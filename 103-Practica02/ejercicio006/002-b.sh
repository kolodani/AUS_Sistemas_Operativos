# Ejercicio 6: Verificar password
# b) Crear un script que emule el proceso de login de un usuario, solicitando
# nombre de usuario y luego clave, la clave introducida no deberá mostrarse por
# pantalla mientas que tipea y debe cotejarse con la clave correspondiente al
# usuario en el archivo passwd.txt creado en el apartado a).

echo "Ingrese su nombre de usuario: "
read usuario
echo "Ingrese su contraseña: "
read -s contrasena                                    # -s: silent, no se muestra por pantalla lo que se escribe

clave=$(grep "^$usuario:" passwd.txt | cut -d: -f2)
# si no se encuentra el usuario, grep devuelve una cadena vacía
if [ -z "$clave" ]
then
    echo "Usuario no encontrado"
else
    if [ "$clave" = "$contrasena" ]; then
        echo "Usuario y Contraseña Correcta"
    else
        echo "Contraseña incorrecta"
    fi
fi

# grep lo que hace es buscar en el archivo passwd.txt la línea que empiece con el nombre de usuario ingresado
# yo ya se que la línea tiene el formato usuario:contraseña. entonces con cut separo la línea en dos campos
# el del usuario y el de la contraseña, y me quedo con el segundo campo, -d es el delimitador, -f2 es el campo 2
# si el usuario no existe, grep devuelve una cadena vacía, entonces la variable clave queda vacía, el if la detecta
# y muestra el cartel de usuario no encontrado.
# si el usuario existe, grep devuelve la línea del usuario, entonces la variable clave queda con la contraseña
# el if detecta que la variable clave no está vacía, entonces compara la contraseña ingresada con la contraseña
# que está en la variable clave, si son iguales muestra el cartel de contraseña correcta, si no son iguales