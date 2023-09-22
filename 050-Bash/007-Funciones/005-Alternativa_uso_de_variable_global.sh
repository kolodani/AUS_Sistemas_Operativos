# Alternativa:
Return_Val= # Variable global para almacenar el valor de retorno
alt_return_test () {
    Return_Val=$1
    return # Returns 0 (success).
}

alt_return_test 256
echo "return value = $Return_Val"     # 256
