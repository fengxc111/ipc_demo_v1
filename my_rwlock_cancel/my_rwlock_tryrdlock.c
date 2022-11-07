#include    "unpipc.h"
#include    "my_rwlock.h"

int
my_rwlock_tryrdlock(my_rwlock_t *rw)
{
    int     result;

    if (rw->rw_magic != RW_MAGIC)
        return(EINVAL);
    
    if ( (result = pthread_mutex_lock(&rw->rw_mutex)) != 0)
        return(result);
    
    if (rw->rw_refcount < 0 || rw->rw_nwaitwriters > 0)
        result = EBUSY;
    else
        rw->rw_refcount++;

    pthread_mutex_unlock(&rw->rw_mutex);
    return(result);
}

void
My_rwlock_tryrdlock(my_rwlock_t *rw)
{
    int     n;

    if ( (n = my_rwlock_tryrdlock(rw)) == 0)
        return;
    errno = n;
    err_sys("my_rwlock_tryrdlock() error");
}