#include    "svmsg.h"

void    client(int, int);

int
main(int argc, char **argv)
{
    int     readid, writeid;

    writeid = Msgget(MQ_KEY1, 0);

    readid = Msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

    client(readid, writeid);

    Msgctl(readid, IPC_RMID, NULL);

    exit(0);
}