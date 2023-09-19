# CONDICIONES SOBRE ARCHIVOS

# -e        existe el archivo
# -f        es un archivo regular
# -r        tiene permisos de lectura
# -w        tiene permisos de escritura
# -x        tiene permisos de ejecucion
# -s        no tiene cero bytes (no es vacio)
# -d        es un directorio
# -b        es un block device (floppy, cdrom)
# -c        es un character device (keyboard, mouse, sound card)
# -p        es un pipe nominado (FIFO)
# -h        es un hard link
# -L        es un symbolic link
# -S        es un socket
# -O        soy el propietario del archivo?
# -G        el GID del archivo es igual al mio?
# -N        se modifico desde su ultima lectura?
# f1 -nt f2 f1 es mas nuevo que f2, en relacion a la actualizacion
# f1 -ot f2 f1 es msa viejo que f2, en relacion a la actualizacion
# f1 -ef f2 f1 y f2 son hard links al mismo archivo
# !         "no" o negacion (invierte el sentido del test, retorna
#           true si la condicion no esta presente)