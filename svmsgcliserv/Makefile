include ../Make.defines

server_main: 	server_main.o server.o mesg_send.o mesg_recv.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

client_main: 	client_main.o client.o mesg_send.o mesg_recv.o
		${CC} ${CFLAGS} -o $@ $^ ${LIBS}

clean:
		rm -f ${CLEANFILES}