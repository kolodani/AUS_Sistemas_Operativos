# TERMINACION EJEMPLO
#!/bin/bash
# verificando el valor del maximo entero que puede retornarse
return_test () {
    return $1
}

return_test 27        # bien
echo $?               # imprime 27
return_test 255       # bien aun
echo $?               # imprime 255
return_test 256       # Error!
echo $?               # imprime 1 (codigo "error miscelaneo")
