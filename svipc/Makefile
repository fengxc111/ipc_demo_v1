include ../Make.defines

PROGS = ftok ftok1 ftok2

all: ${PROGS}

ftok: ftok.o
	${CC} ${CFLAGS} -o $@ ftok.o ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}