#include    "mesg.h"

void
server(int readid, int writeid)
{
    FILE    *fp;
    char    *ptr;
    ssize_t n;
    struct mymesg   mesg;
    void    sig_chld(int);

    Signal(SIGCHLD, sig_chld);

    for(;;){
        mesg.mesg_type = 1;
        if ( (n = Mesg_recv(readid, &mesg)) == 0){
            err_msg("pathname missing");
            continue;
        }
        mesg.mesg_data[n] = '\0';

        if ( (ptr = strchr(mesg.mesg_data, ' ')) == NULL){
            err_msg("bogus request: %s", mesg.mesg_data);
            continue;
        }
        *ptr++ = 0;
        writeid = atoi(mesg.mesg_data);

        if (Fork() == 0){
            if ( (fp = fopen(ptr, "r")) == NULL){
                snprintf(mesg.mesg_data+n, sizeof(mesg.mesg_data)-n,
                ": cam't open, %s", strerror(errno));
                mesg.mesg_len = strlen(ptr);
                memmove(mesg.mesg_data, ptr, mesg.mesg_len);
                Mesg_send(writeid, &mesg);
            }else{
                while(Fgets(mesg.mesg_data, MAXMESGDATA, fp) != NULL){
                    mesg.mesg_len = strlen(mesg.mesg_data);
                    Mesg_send(writeid, &mesg);
                }
                Fclose(fp);
            }

            mesg.mesg_len = 0;
            Mesg_send(writeid, &mesg);
            exit(0);
        }
    }
}