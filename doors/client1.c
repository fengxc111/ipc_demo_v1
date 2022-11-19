#include    "unpipc.h"

int
main(int argc, char **argv)
{
    int     fd;
    long    ival, oval;
    door_arg_t  arg;

    if (argc != 3)
        err_quit("usage: client1 <server-pathname> <interger-value>");
    
    fd = Open(argv[1], O_RDWR);

    ival = atol(argv[2]);
}