#include    "unpipc.h"

int
main(int argc, char **argv)
{
    int     msqid;
    struct msqid_ds info;
    struct msgbuf   buf;

    msqid = Msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

    buf.mytype = 1;
    buf.mtext[0] = 1;
    Msgsnd(msqid, &buf, 1, 0);

    Msgctl(msqid, IPC_STAT, &info);
    printf("read-write: %03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
            info.msg_perm.mode, (__syscall_ulong_t)info.__msg_cbytes,
            (__syscall_ulong_t)info.msg_qnum, (__syscall_ulong_t)info.msg_qbytes);
    
    system("ipcs -q");

    Msgctl(msqid, IPC_RMID, NULL);
    exit(0);
}