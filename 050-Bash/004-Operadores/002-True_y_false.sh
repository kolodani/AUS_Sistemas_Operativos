# TRUE Y FALSE

# TRUE
# - true: comando que retorna siempre un exit status exitoso (cero) sin hacer nada
true
echo $?
# tambien evaluan a true: 0, 1, -1, "abc"".

# FALSE
# - false: comando que retorna siempre un exit status no exitoso (distinto de cero) sin hacer nada
false
echo $?
# tambien evaluan a false: NULL, variable no inicializada, variable nula.

