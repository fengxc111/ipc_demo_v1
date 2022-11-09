#include    "unpipc.h"

#define LOCKFILE    "/tmp/seqno.lock"

void
my_lock(int fd)
{
    int     tempfd;

    while ( (tempfd = open(LOCKFILE, O_RDWR | O_CREAT | O_EXCL, FILE_MODE)) < 0){
        if (errno != EEXIST)
            err_sys("open errpr for lock file");
    }
    Close(tempfd);
}

void
my_unlock(int fd)
{
    Unlink(LOCKFILE);
}