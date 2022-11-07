#include    "unpipc.h"
#include    "my_rwlock.h"

int
my_rwlock_unlock(my_rwlock_t *rw)
{
    int     result;

    if (rw->rw_magic != RW_MAGIC)
        return(EINVAL);
    
    if ( (result = pthread_mutex_lock(&rw->rw_mutex)) != 0)
        return(result);
    
    if (rw->rw_refcount > 0)
        rw->rw_refcount--;
    else if (rw->rw_refcount == -1)
        rw->rw_refcount = 0;
    else
        err_dump("rw_refcount = %d", rw->rw_refcount);
    
    if (rw->rw_nwaitwriters > 0){
        if (rw->rw_refcount == 0)
            result = pthread_cond_signal(&rw->rw_condwriters);
    }else if (rw->rw_nwaitreaders > 0)
        result = pthread_cond_broadcast(&rw->rw_condreaders);

    pthread_mutex_unlock(&rw->rw_mutex);
    return(result);
}

void
My_rwlock_unlock(my_rwlock_t *rw)
{
    int     n;
    if ( (n = my_rwlock_unlock(rw)) == 0)
        return;
    
    errno = n;
    err_sys("my_rwlock_unlock() error");
}