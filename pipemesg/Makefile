include ../Make.defines

PROGS = mainpipe mainfifo

OBJS = client.o server.o mesg_send.o mesg_recv.o

all: ${PROGS}

mainpipe: 	mainpipe.o ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ ${LIBS}

mainfifo:	mainfifo.o ${OBJS}
			${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}