include ../Make.defines

server_main: 	server_main.o server.o mesg_recv.o mesg_send.o sigchldwaitpid.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

client_main: 	client_main.o client.o mesg_recv.o mesg_send.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
		rm -f ${CLEANFILES}