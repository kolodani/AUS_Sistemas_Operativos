var1=21
var2=22
[ "$var1" -ne "$var2" ] && echo "$var1 no es igual a $var2"
# Es lo mismo que
if [ "$var1" -ne "$var2" ] ;
then
    echo "$var1 no es igual a $var2"
fi
# Y esto a que es igual ?
[ "$var1" -ne "$var2" ] || echo "$var1 no es igual a $var2"
