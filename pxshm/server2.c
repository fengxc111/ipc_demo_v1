#include    "cliserv2.h"

int
main(int argc, char **argv)
{
    int     fd, index, lastnoverflow, temp;
    long    offset;
    struct shmstruct    *ptr;

    if (argc != 2)
        err_quit("usage: server2 <name>");
    
    shm_unlink(Px_ipc_name(argv[1]));
    fd = Shm_open(Px_ipc_name(argv[1]), O_CREAT | O_EXCL | O_RDWR, FILE_MODE);
    ptr = Mmap(NULL, sizeof(struct shmstruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    Ftruncate(fd, sizeof(struct shmstruct));
    Close(fd);

    for (index = 0; index < NMESG; index++)
        ptr->msgoff[index] = index * MESGSIZE;
    
    Sem_init(&ptr->mutex, 1, 1);
    Sem_init(&ptr->nempty, 1, NMESG);
    Sem_init(&ptr->nstored, 1, 0);
    Sem_init(&ptr->noverflowmutex, 1, 1);

    index = 0;
    lastnoverflow = 0;
    for (;;){
        Sem_wait(&ptr->nstored);
        Sem_wait(&ptr->mutex);
        offset = ptr->msgoff[index];
        //printf("index = %2d: %s\n", index, &ptr->msgdata[offset]);
        if (++index >= NMESG)
            index = 0;
        Sem_post(&ptr->mutex);
        Sem_post(&ptr->nempty);

        Sem_wait(&ptr->noverflowmutex);
        temp = ptr->noverflow;
        Sem_post(&ptr->noverflowmutex);
        if (temp != lastnoverflow){
            printf("noverflow = %d\n", temp);
            lastnoverflow = temp;
        }
    }
    exit(0);
}