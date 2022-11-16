include ../Make.defines

PROGS = shmcreate shmread shmunlink shmwrite

all: ${PROGS}

shmcreate: 	shmcreate.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmread: 	shmread.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmunlink: 	shmunlink.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

shmwrite: 	shmwrite.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test3: 		test3.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

server1: 	server1.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

client1: 	client1.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

server2: 	server2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

client2: 	client2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
	rm -f ${CLEANFILES}