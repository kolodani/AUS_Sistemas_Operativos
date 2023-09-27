# EJEMPLOS VARIOS

# awk '{ i = 1              # imprime los primeros tres campos
#         while (i<= 3) {   # de cada registro
#             print $i
#             i++           # i=$i+1
#         }
# }'

# awk '{ for (i = 1; i <= 3; i++)    # idem anterior
#         print $i
# }'

# Bash script con codigo awk embebido
#!/bin/bash

# PASSWOEDS=/etc/passwd
# n=1         # Numero de usuario

# for name in $(awk 'BEGIN{FS=":"}{print $1}' < "$PASSWORD_FILE" )
# do
#     echo "USER #$n = $name"
#     let "n += 1"
# done