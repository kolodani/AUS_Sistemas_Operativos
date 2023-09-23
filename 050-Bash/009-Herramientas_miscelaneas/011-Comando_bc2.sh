# COMANDO BC

# Usos tipicos en scripts
AVERAGE=´echo "scale=4; $PRICE/$UNITS" | bc´
PI=$(echo "scale=10; 4*a(1)" | bc -l)   # a: atan(x)
                                        # -l: mathlib

# Permite realizar conversiones en diferentes bases
# es importante establecer primero la base output
bc
obase=16       # base output = hexadecimal
ibase=8        # base input = octal
400
100
77
3f
10*3
18
quit