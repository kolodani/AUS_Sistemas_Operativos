# VISIBILIDAD Y DEFINICIONES

# las declaraciones de funciones pueden aparecer en casi cualquier lugar,
# inclusive donde iria un comando
ls -l | f () { echo "22"; }  # Correcto, aunque inutil

# bash admite funciones anidadas
#!/bin/bash
f1 () {
    f2 () {    # funcion anidada
        echo "Funcion \"f2\", dentro de \"f1\"."
    }
}

f2    # provoca un error

