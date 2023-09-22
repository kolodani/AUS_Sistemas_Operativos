# SENTENCIA FOR

# Sintaxis:
# for arg in lista ;
# do
#   comando (s)...
# done

# Ejemplo:
for planeta in Mercurio Venus Tierra Marte ;
do
    echo $planeta
done

for file in /var/*.bck ;
do
    rm $file
done
