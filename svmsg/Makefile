include ../Make.defines

PROGS = slot 

all: 	${PROGS}

slot: 	slot.o
		${CC} ${CFLAGS} -o $@ slot.o ${LIBS}

ctl:	ctl.o
		${CC} ${CFLAGS} -o $@ ctl.o ${LIBS}
msgcreate:	msgcreate.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}
msgrcv:	msgrcv.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}
msgsnd:	msgsnd.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}
msgrmid:	msgrmid.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}
msgrcvid: 	msgrcvid.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

limits: 	limits.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}