#include    "unpipc.h"

#define PATH_PIDFLIE    "pidfile"

int
main(int argc, char **argv)
{
    int     pidfd;
    char    line[MAXLINE];

    pidfd = Open(PATH_PIDFLIE, O_RDWR | O_CREAT, FILE_MODE);

    if (write_lock(pidfd, 0, SEEK_SET, 0) < 0){
        if (errno == EACCES || errno == EAGAIN)
            err_quit("unable to lock %s, is %s already running?",
                    PATH_PIDFLIE, argv[0]);
        else
            err_sys("unable to lock %s", PATH_PIDFLIE);
    }

    snprintf(line, sizeof(line), "%ld\n", (long)getpid());
    Ftruncate(pidfd, 0);
    Write(pidfd, line, strlen(line));

    pause();
}