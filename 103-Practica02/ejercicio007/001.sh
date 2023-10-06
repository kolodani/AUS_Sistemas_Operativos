# Ejercicio 7: Front-end para el comando find
# Mediante las man pages u otro recurso investigar el funcionamiento del comando find y crear una
# interfaz de usuario que permita buscar archivos según los siguientes criterios:
# > Tipo (directorio, archivo, pipe con nombre, symbolic link)
# > Tamaño (bytes, kbytes, megabytes)
# > Permisos (lectura, escritura, ejecución , combinaciones de los anteriores)
# > Por inodo
# Ejemplo:
# $ bash my_find.sh
# deberá mostrar un menú similar al siguiente
# Interfaz para comando find
# 1 - Busqueda por tipo de archivo
# 2 – Busqueda por tamaño de archivo
# 3 – Busqueda según los permisos del archivo
# 4 – Busqueda por inodo
# Introduzca criterio de búsqueda:
# En este punto se le pedirá al usuario que especifique el path desde donde se comenzará la
# búsqueda y las entradas correspondientes a la selección realizada.
# Comentarios:
# – Para la interfaz de usuario utilizar la estructura de control select
# – Utilizar case para determinar y tratar cada criterio
# – Considere el uso de funciones para reducir código

# - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - # - #

# FUNCIONES
# Función que muestra el menú
function menu() {
    echo "Bienvenido al buscador de archivos: FIND v1.0"
    echo "Ingrese el path desde donde se comenzará la búsqueda:"
    echo "(Recuerde que el path debe ser absoluto, ej: /home/user/...)"
    read path
}
# Funcion que corroborar que el path ingresado sea correcto
function corroborarPath() {
    if [ ! -d $path ]; then
        echo "El path ingresado no es correcto"
        exit
    fi
}
# Funcion select para el primer menu de opciones
function menuOpciones() {
    echo "Seleccione una opción:"
    select opcion in "Tipo de archivo" "Tamaño de archivo" "Permisos del archivo" "Inodo" "Salir"; do
        case $opcion in
        "Tipo de archivo")
            menuTipo
            break
            ;;
        "Tamaño de archivo")
            menuTamano
            break
            ;;
        "Permisos del archivo")
            menuPermisos
            break
            ;;
        "Inodo")
            menuInodo
            break
            ;;
        "Salir")
            exit
            ;;
        *)
            echo "Opción incorrecta"
            ;;
        esac
    done
}
# Funcion select para el menu de opciones de tipo de archivo
function menuTipo() {
    echo "Seleccione una opción:"
    select opcion in "Directorio" "Archivo" "Pipe con nombre" "Symbolic link" "Salir"; do
        case $opcion in
        "Directorio")
            echo "Ingrese el nombre del directorio a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -type d -name $nombre
            break
            ;;
        "Archivo")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -type f -name $nombre
            break
            ;;
        "Pipe con nombre")
            echo "Ingrese el nombre del pipe con nombre a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -type p -name $nombre
            break
            ;;
        "Symbolic link")
            echo "Ingrese el nombre del symbolic link a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -type l -name $nombre
            break
            ;;
        "Salir")
            exit
            ;;
        *)
            echo "Opción incorrecta"
            ;;
        esac
    done
}
# Funcion select para el menu de opciones de tamaño de archivo
function menuTamano() {
    echo "Seleccione una opción:"
    select opcion in "Bytes" "Kbytes" "Mbytes" "Salir"; do
        case $opcion in
        "Bytes")
            echo "Ingrese el tamaño en bytes del archivo a buscar:"
            read tamano
            echo "Resultado de la búsqueda:"
            find $path -size $tamano"c"
            break
            ;;
        "Kbytes")
            echo "Ingrese el tamaño en kbytes del archivo a buscar:"
            read tamano
            echo "Resultado de la búsqueda:"
            find $path -size $tamano"k"
            break
            ;;
        "Mbytes")
            echo "Ingrese el tamaño en mbytes del archivo a buscar:"
            read tamano
            echo "Resultado de la búsqueda:"
            find $path -size $tamano"M"
            break
            ;;
        "Salir")
            exit
            ;;
        *)
            echo "Opción incorrecta"
            ;;
        esac
    done
}
# Funcion select para el menu de opciones de permisos de archivo
function menuPermisos() {
    echo "Seleccione una opción:"
    select opcion in "Lectura" "Escritura" "Ejecución" "Lectura y Escritura" "Lectura y Ejecucion" "Escritura y Ejecucion" "Todos los permisos" "Salir"; do
        case $opcion in
        "Lectura")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+r -name $nombre
            break
            ;;
        "Escritura")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+w -name $nombre
            break
            ;;
        "Ejecución")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+x -name $nombre
            break
            ;;
        "Lectura y Escritura")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+rw -name $nombre
            break
            ;;
        "Lectura y Ejecucion")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+rx -name $nombre
            break
            ;;
        "Escritura y Ejecucion")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+wx -name $nombre
            break
            ;;
        "Todos los permisos")
            echo "Ingrese el nombre del archivo a buscar:"
            read nombre
            echo "Resultado de la búsqueda:"
            find $path -perm -u+rwx -name $nombre
            break
            ;;
        "Salir")
            exit
            ;;
        *)
            echo "Opción incorrecta"
            ;;
        esac
    done
}
# Funcion select para el menu de opciones de inodo
function menuInodo() {
    echo "Seleccione una opción:"
    select opcion in "Inodo" "Salir"; do
        case $opcion in
        "Inodo")
            echo "Ingrese el número de inodo del archivo a buscar:"
            read inodo
            echo "Resultado de la búsqueda:"
            find $path -inum $inodo
            break
            ;;
        "Salir")
            exit
            ;;
        *)
            echo "Opción incorrecta"
            ;;
        esac
    done
}

# MAIN
menu
directorio=$(pwd)
corroborarPath
cd $path
menuOpciones
cd $directorio
echo "Gracias por utilizar el buscador de archivos: FIND v1.0"
