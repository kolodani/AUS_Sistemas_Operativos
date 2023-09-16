echo $1234
# bash intrepreta que $1 es una variable, pero no existe, por lo que expande
# a un valor vacio. y luego interpreta el 234 como un argumento para el comando echo
echo \$1234
# \$ indica que el caracter $ no debe ser interpretado como una variable
# por lo que se imprime literalmente $1234


echo Texto escrito en \
mas de una linea
