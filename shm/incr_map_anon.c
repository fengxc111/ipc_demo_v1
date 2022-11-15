#include    "unpipc.h"

#define SEM_NAME    "mysem"
#define MAP_ANONYMOUS   -1

int
main(int argc, char **argv)
{
    int     fd, i, nloop, zero = 0;
    int     *ptr;
    sem_t   *mutex;

    if (argc != 2)
        err_quit("usage: incr_map_anon <#loops>");
    nloop = atoi(argv[1]);

    ptr = Mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    mutex = Sem_open(Px_ipc_name(SEM_NAME), O_CREAT | O_EXCL, FILE_MODE, 1);
    Sem_unlink(Px_ipc_name(SEM_NAME));

    setbuf(stdout, NULL);
    if (Fork() == 0){
        for (i = 0; i < nloop; i++){
            Sem_wait(mutex);
            printf("child: %d\n", (*ptr)++);
            Sem_post(mutex);
        }
        exit(0);
    }

    for (i = 0; i < nloop; i++){
        Sem_wait(mutex);
        printf("parent: %d\n", (*ptr)++);
        Sem_post(mutex);
    }
    wait(NULL);
    exit(0);
}