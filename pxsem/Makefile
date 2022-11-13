include ../Make.defines

PROGS = semcreate semgetvalue sempost semunlink semwait prodcons1

all: 	${PROGS}

semcreate: 	semcreate.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semgetvalue: 	semgetvalue.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

sempost: 	sempost.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semunlink: 	semunlink.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semwait: 	semwait.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

prodcons1: 	prodcons1.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

prodcons2: 	prodcons2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

prodcons3: 	prodcons3.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

prodcons4: 	prodcons4.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

mycat2:	mycat2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semsysconf:	semsysconf.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}