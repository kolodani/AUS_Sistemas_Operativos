# SENTENCIA IF 2

# Ejemplo:
#!/bin/bash
xusers=`who | wc -l`

if [ $xusers -gt l ] ;
then
    echo "Hay mas de un usuario conectado"
else
    echo "Solo ud. esta conectado"
fi
