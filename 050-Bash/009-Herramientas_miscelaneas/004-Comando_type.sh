# COMANDO TYPE

# Brinda el path absoluto de uno o mas comandos
# Sintaxis:
#   type comando...

# Si comando no es un comando externo al shell, type respondera
# - es un comando built-in
# - es una palabra reservada del shell
# - es un alias

# Si es un alias de un comando, typo tambien dara el comando subyacente

# Ejemplo:
type true vi case eval history
# LO QUE DICE EN EL APUNTE
# true is /bin/true
# vi is /usr/bin/vi
# case is a keyword
# eval is a shell builtin
# history is an exported alias for fc -l

# LO QUE DICE EN MI PC
# true is a shell builtin
# vi is /usr/bin/vi
# case is a shell keyword
# eval is a shell builtin
# history is a shell builtin