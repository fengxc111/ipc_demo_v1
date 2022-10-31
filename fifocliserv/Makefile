include ../Make.defines

PROGS = mainserver mainclient

mainserver: 	mainserver.o
				${CC} ${CFLAGS} -o $@ $^ ${LIBS}

mainclient: 	mainclient.o
				${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
				rm -f ${PROGS} ${CLEANFILES}