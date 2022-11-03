#include    "mesg.h"

void
client(int readfd, int writefd)
{
    size_t  len;
    ssize_t n;
    char    *ptr;
    struct mymesg mesg;

    snprintf(mesg.mesg_data, MAXMESGDATA, "%ld", (long)getpid());
    len = strlen(mesg.mesg_data);
    ptr = mesg.mesg_data + len;
    *ptr++ = ' ';
    Fgets(ptr, MAXMESGDATA, stdin);
    len = strlen(mesg.mesg_data);
    printf("messege: %s", mesg.mesg_data);
    if (mesg.mesg_data[len-1] == '\n')
        len--;
    mesg.mesg_len = len;
    mesg.mesg_type = 1;

    Mesg_send(writefd, &mesg);

    mesg.mesg_type = getpid();
    while( (n = Mesg_recv(readfd, &mesg)) > 0)
        Write(STDOUT_FILENO, mesg.mesg_data, n);
}