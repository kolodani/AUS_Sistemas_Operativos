# OPERADORES MISCELANEOS

# Operador coma
# - permite encadenar dos o mas operaciones aritmeticas

# - se evalua cada operador (con posibles efectos larerales), pero solo se retorna
# la ultima operaciones

# similar al operador coma de C

# Ejemplo:
let "t1 = ((5 + 3, 7 - 1, 15 - 4))"
echo "t1 = $t1"
# t1 = 11

let "t2 = ((i =9, 15 / 3))"        # se establece i (efecto lateral)
echo "t2 = $t2 i = $i"
# t2 = 5 i = 9
