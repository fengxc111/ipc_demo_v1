include ../Make.defines

FUNCS = my_rwlock_init.o my_rwlock_rdlock.o my_rwlock_wrlock.o \
		my_rwlock_tryrdlock.o my_rwlock_trywrlock.o my_rwlock_unlock.o \
		my_rwlock_destroy.o

testcancel: testcancel.o ${FUNCS}
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${CLEANFILES}