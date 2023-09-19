# OPERADORES DE BITS

# <<     left shift (multiplica por 2)
# <<=    left-shift-igual
let "var <<= 2"    # como un producto de 2^n

# >>     right shift (divide por 2)
# >>=    right-shift-igual (inverso de <<=)
let "var >>= 3"    # como una division de 2^n

#  &      and
#  &=     and-igual
#  |      or
#  |=     or-igual
#  ~      negacion o not
#  !      negacion o not
#  ^      xor (o-exclusivo)
#  ^=     xor-igual

var1=24            # 00000000 00000000 00000000 00011000
var2=10            # 00000000 00000000 00000000 00001010
let "var1 &= var2"
echo $var1
# 8                # 00000000 00000000 00000000 00001000