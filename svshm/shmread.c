#include    "unpipc.h"

int
main(int argc, char **argv)
{
    int     i, id;
    struct shmid_ds buff;
    unsigned char   c, *ptr;

    if (argc != 2)
        err_quit("usage: shmread <pathname>");

    id = Shmget(Ftok(argv[1], 0), 0, SVSHM_MODE);
    ptr = Shmat(id, NULL, 0);
    Shmctl(id, IPC_STAT, &buff);

    for (i = 0; i < buff.shm_segsz; i++)
        if ( (c = *ptr++) != (i%256))
            err_ret("ptr[%d] = %d\n", i, c);
        else
            printf("ptr[%d] = %d\n", i, c);
    exit(0);
}