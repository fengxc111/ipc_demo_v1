#include    "svmsg.h"

void client(int, int);

int
main(int argc, char **argv)
{
    int     readid, writeid;

    writeid = Msgget(MQ_KEY1, 0);
    readid = Msgget(MQ_KEY2, 0);
    while(1){
    client(readid, writeid);}

    Msgctl(readid, IPC_RMID, NULL);
    Msgctl(writeid, IPC_RMID, NULL);

    exit(0);
}