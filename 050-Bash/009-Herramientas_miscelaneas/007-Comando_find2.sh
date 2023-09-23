# COMANDO FIND 2

# Combinacion de criterios
# -And
# find / -size +50 -mtime -3 -print
# find / -size +50 -print -Mtime -3   # se ignora -mtime -3

# -Or
# find / \(-size +50 -o -mtime -3 \)

# -Not
# find /dev ! \( -type b -o -type c -o -type d \)

# Si mediane -exec hay que procesar muchos archivos como en
# find / -name core -exec rm -i {} \;
# utilizar en su lugar xargs como en
# find / -name core | xargs rm -i
# Este comando tambien borra los archivos core pero mucho mas rapido y con menos
# sobrecarga que -exec que llama rm -i para cada archivo