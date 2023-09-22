# SENTENCIA SELECT

# sintaxis:
# select name [in lista];        # Los [] estan indicando opcion
# do                             # no es parte de la sintaxis
#     comando(s)...
# done

# Ejemplo:
#!/bin/bash
PS3='Elija su comida favorita: '   # Establece el prompt
echo
select food in "Asado" "Lasagna" "Paella" "Pizza"
    do
        [ -e "$food" ] && continue
        echo "Su comida favorita es $food."
        break
    done
exit 0
