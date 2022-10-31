include ../Make.defines

PROGS = slot

all: ${PROGS}

slot: slot.o
	${CC} ${CFLAGS} -o $@ slot.o ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}