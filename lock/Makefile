include ../Make.defines

locknone: 	lockmain.o locknone.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

lockfcntl: 	lockmain.o lockfcntl.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

lockopen: 	lockmain.o lockopen.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test2:		test2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test3:		test3.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test4:		test4.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

onedaemon: 	onedaemon.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${CLEANFILES}