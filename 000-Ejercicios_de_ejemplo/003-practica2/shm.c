#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

int main () {
    int segment_id;
    char* shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x6400;
    
    /* Alloca un segmento de memoria compartida. */
    segment_id = shmget (IPC_PRIVATE, shared_segment_size,
    IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    /* Attacha el segmento de memoria compartida. */
    shared_memory = (char*) shmat (segment_id, 0, 0);
    printf ("Memoria compartida attachada en la direccion:  %p\n", 
			 shared_memory);

    sleep(10); 
    /* Determina el tamanio del segmento. */
    shmctl (segment_id, IPC_STAT, &shmbuffer);
    segment_size = shmbuffer.shm_segsz;
    printf ("Tamanio del segmento: %d\n", segment_size);

    /* Escribe una string en el segmento de memoria compartida. */
    sprintf (shared_memory, "Hello, world.");
    
    /* Detacha el segmento de memoria compartida. */
    shmdt (shared_memory);
    /* Reattacha segmento de memoria compartida, un una direccion 
	 * diferente. */
    shared_memory = (char*) shmat (segment_id, (void*) 0x5000000, 0);
    printf ("Memoria compartida reattachada en la direccion %p\n",
			 shared_memory);
    
    /* Imprime la string desde la memoria compartida. */
    printf ("%s\n", shared_memory);
    
    /* Detacha el segmento de memoria compartida. */
    shmdt (shared_memory);
    sleep(10); 
    /* Desalloca segmento de memoria compartidat. */
    shmctl (segment_id, IPC_RMID, 0);
    
    return 0;
}


