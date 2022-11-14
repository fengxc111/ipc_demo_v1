#include    "unpipc.h"

int
main(int argc, char **argv)
{
    int     c, i, flag, semid, nops;
    struct sembuf   *ptr;

    flag = 0;
    while ( (c = Getopt(argc, argv, "nu")) != -1 && optind < 2){
        switch (c){
        case 'n':
            flag |= IPC_NOWAIT;
            break;
        case 'u':
            flag |= SEM_UNDO;
            break;
        }
    }
    if (argc - optind < 2)
        err_quit("usage: semops [-n] [-u] <pathname> opreation ...");

    semid = Semget(Ftok(argv[optind], 0), 0, 0);
    optind++;
    nops = argc - optind;

    ptr = Calloc(nops, sizeof(struct sembuf));
    for (i = 0; i < nops; i++){
        ptr[i].sem_num = i;
        ptr[i].sem_op = atoi(argv[optind + i]);
        ptr[i].sem_flg = flag;
    }
    Semop(semid, ptr, nops);

    exit(0);
}