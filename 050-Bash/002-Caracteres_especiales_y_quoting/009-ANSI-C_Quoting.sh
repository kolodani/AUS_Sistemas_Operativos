#!/bin/bash
# ANSI-C Quoting

#   \a       alerta                    (alerta)
#   \b       retroceso                 (backspace)
#   \n       nueva línea               (new line)
#   \t       tabulador                 (horizontal tab)
#   \v       tabulador vertical        (vertical tab)
#   \\       barra invertida           (backslash)

echo Barra invertida = $'\\'
# salida por pantalla:
# Barra invertida = \

echo Se oye .... $'\a'
# salida por pantalla:
# Se oye .... (Beep!)

echo Hola $'\n'Mundo
# salida por pantalla:
# Hola
# Mundo