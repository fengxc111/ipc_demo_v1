#include    "svmsg.h"

void client(int, int);

int
main(int argc, char **argv)
{
    int     msqid;

    msqid = Msgget(MQ_KEY1, 0);

    client(msqid, msqid);

    exit(0);
}