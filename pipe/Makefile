include ../Make.defines

PROGS = mainpipe fduplex mainpopen mainfifo server_main client_main

mainpipe: 	mainpipe.o client.o server.o
			${CC} ${CFLAGS} -o $@ mainpipe.o client.o server.o ${LIBS}

fduplex: 	fduplex.o
			${CC} ${CFLAGS} -o $@ fduplex.o ${LIBS}

mainpopen: 	mainpopen.o
			${CC} ${CFLAGS} -o $@ mainpopen.o ${LIBS}

mainfifo: 	mainfifo.o client.o server.o
			${CC} ${CFLAGS} -o $@ $^ ${LIBS}

server_main: server_main.o server.o
			${CC} ${CFlAGS} -o $@ $^ ${LIBS}

client_main: client_main.o client.o
			${CC} ${CFlAGS} -o $@ $^ ${LIBS}

pipeconf: 	pipeconf.o
			${CC} ${CFLAGS} -o $@ pipeconf.o ${LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}