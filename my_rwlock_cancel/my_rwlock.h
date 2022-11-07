#ifndef __my_rwlock_h
#define __my_rwlock_h

typedef struct{
    pthread_mutex_t rw_mutex;
    pthread_cond_t  rw_condreaders;
    pthread_cond_t   rw_condwriters;
    int     rw_magic;
    int     rw_nwaitreaders;
    int     rw_nwaitwriters;
    int     rw_refcount;        //-1wrlock, 0unuse, >0rdlock count
} my_rwlock_t;

#define RW_MAGIC    0x19283746

#define MY_RWLOCK_INITIALIZER { PTHREAD_MUTEX_INITIALIZER, \
            PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, \
            RW_MAGIC, 0, 0, 0}

typedef int my_rwlockattr_t;

int     my_rwlock_destory(my_rwlock_t *);
int     my_rwlock_init(my_rwlock_t *, my_rwlockattr_t *);
int     my_rwlock_rdlock(my_rwlock_t *);
int     my_rwlock_tryrdlock(my_rwlock_t *);
int     my_rwlock_trywrlock(my_rwlock_t *);
int     my_rwlock_unlock(my_rwlock_t *);
int     my_rwlock_wrlock(my_rwlock_t *);

void     My_rwlock_destory(my_rwlock_t *);
void     My_rwlock_init(my_rwlock_t *, my_rwlockattr_t *);
void     My_rwlock_rdlock(my_rwlock_t *);
void     My_rwlock_tryrdlock(my_rwlock_t *);
void     My_rwlock_trywrlock(my_rwlock_t *);
void     My_rwlock_unlock(my_rwlock_t *);
void     My_rwlock_wrlock(my_rwlock_t *);

#endif