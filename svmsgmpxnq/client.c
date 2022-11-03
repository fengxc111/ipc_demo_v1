#include    "mesg.h"

void
client(int readid, int writeid)
{
    size_t  len;
    ssize_t n;
    char    *ptr;
    struct mymesg   mesg;

    snprintf(mesg.mesg_data, MAXMESGDATA, "%d", readid);
    len = strlen(mesg.mesg_data);
    ptr = mesg.mesg_data + len;
    *ptr++ = ' ';
    // len++;

    Fgets(ptr, MAXMESGDATA-len, stdin);
    len = strlen(mesg.mesg_data);
    if (mesg.mesg_data[len-1] == '\n')
        len--;
    mesg.mesg_len = len;
    mesg.mesg_type = 1;

    Mesg_send(writeid, &mesg);

    while ( (n = Mesg_recv(readid, &mesg)) > 0)
        Write(STDOUT_FILENO, mesg.mesg_data, n);
}