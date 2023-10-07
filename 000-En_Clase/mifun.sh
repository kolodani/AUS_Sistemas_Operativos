mkdummyFile () {
    # crear un archivo en la ruta especificada con los nros del 1...NRO
    MYFILE=$(date +"%s")
    for i in $(seq 1 $1)
    do
        echo -n "$i - "
    done >> $2/$MYFILE-aus.txt
}
