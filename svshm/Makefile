include ../Make.defines

PROGS = shmget shmread shmrmid shmwrite

all: 	${PROGS}

shmget: 	shmget.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmread: 	shmread.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmrmid: 	shmrmid.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmwrite: 	shmwrite.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}
