#include    "unpipc.h"
// #include    "getopt.h"

int
main(int argc, char **argv)
{
    int     c, flags;
    sem_t   *sem;
    unsigned int value;

    flags = O_RDWR | O_CREAT;
    value = 1;
    while ( (c = Getopt(argc, argv, "ei:")) != -1){
        // printf("while loop index = %d\n", optind);
        switch (c){
        case 'e':
            flags |= O_EXCL;
            break;
        case 'i':
            value = atoi(optarg);
            break;
        }
    }
    if (optind != argc - 1)
        err_quit("usage: semcreate [-e] [-i initalvalue] <name>");
    
    // printf("optind = %d, optarg = %s, argv[1] = %s\n", optind, optarg, argv[1]);
    // Sem_unlink(argv[1]);
    sem = Sem_open(argv[optind], flags, FILE_MODE, value);
    // printf("open finished\n");
    Sem_close(sem);
    exit(0);
}