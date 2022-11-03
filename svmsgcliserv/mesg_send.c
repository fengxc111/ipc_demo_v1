#include    "mesg.h"

ssize_t
mesg_send(int id, struct mymesg *mptr)
{
    return(msgsnd(id, &(mptr->mesg_type), mptr->mesg_len, 0));
}

void
Mesg_send(int id, struct mymesg *mptr)
{
    ssize_t n;

    if ( (n = mesg_send(id, mptr)) == -1)
        err_sys("mesg_send error");
}