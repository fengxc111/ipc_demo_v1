#include    "mesg.h"

ssize_t
mesg_recv(int id, struct mymesg *mptr)
{
    ssize_t n;

    n = msgrcv(id, &(mptr->mesg_type), MAXMESGDATA, mptr->mesg_type, 0);
    mptr->mesg_len = n;

    return(n);
}

ssize_t
Mesg_recv(int id, struct mymesg *mptr)
{
    ssize_t n;

    if( (n = mesg_recv(id, mptr)) == -1)
        err_quit("mesg_send error");

    return(n);
}