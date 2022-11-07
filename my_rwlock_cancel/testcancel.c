#include    "unpipc.h"
#include    "my_rwlock.h"

my_rwlock_t rwlock = MY_RWLOCK_INITIALIZER;
pthread_t tid1, tid2;
void    *thread1(void *), *thread2(void *);

int
main(int argc, char **argv){
    void    *status;

    Set_concurrency(2);
    Pthread_create(&tid1, NULL, thread1, NULL);
    sleep(1);
    Pthread_create(&tid2, NULL, thread2, NULL);

    Pthread_join(tid2, &status);
    if (status != PTHREAD_CANCELED)
        printf("thread2 status = %p\n", status);
    Pthread_join(tid1, &status);
    if (status != NULL)
        printf("thread1 status = %p\n", status);
    
    printf("rw_refcount = %d, rw_nwaitreaders = %d, rw_nwaitwtiters = %d\n",
            rwlock.rw_refcount, rwlock.rw_nwaitreaders,
            rwlock.rw_nwaitwriters);
    My_rwlock_destory(&rwlock);

    exit(0);
}

void *
thread1(void *arg)
{
    My_rwlock_rdlock(&rwlock);
    printf("thread1() got a read lock\n");
    sleep(3);
    pthread_cancel(tid2);
    sleep(3);
    My_rwlock_unlock(&rwlock);
    return(NULL);
}

void *
thread2(void *arg)
{
    printf("thread2() trying to obtain a write lock\n");
    My_rwlock_wrlock(&rwlock);
    printf("thread2() got a write lock\n");
    sleep(1);
    My_rwlock_unlock(&rwlock);
    return(NULL);
}