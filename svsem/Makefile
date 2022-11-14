include ../Make.defines

PROGS = semcreate semsetvalues semgetvalues semops semrmid

all: 	${PROGS}

semcreate: 	semcreate.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semsetvalues: 	semsetvalues.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semgetvalues: 	semgetvalues.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semops: 	semops.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

semrmid: 	semrmid.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}