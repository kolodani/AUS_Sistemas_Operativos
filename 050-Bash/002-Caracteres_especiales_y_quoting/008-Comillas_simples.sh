VAR=10
echo '$VAR'
# en este caso la salida por pantalla es
# $VAR
# esto sucede porque el bash interpreta que lo que esta dentro de las comillas se
# muestre tal cual y no si es una variable y menos su contenido

echo 'd* = el caracter <d> seguido de cualquier cadena, \
inclusive la vacia'
# aque tomo toda la cadena y lo interpreto como eso porque dentro de la misma no se
# di ninguna excepcion

echo 'La comilla simple (`) tambien es llamdo apostrofo'
# si en vez de poner a comilla hacia atras colocabamos la recta
# nos iba a tirar un error porque iba a interpretar el final en
# esa comilla y no en la del final de la linea
