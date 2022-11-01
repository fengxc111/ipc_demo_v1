include ../Make.defines

mqcreate1: 	mqcreate1.o
		${CC} ${CFLAGS} -o $@ mqcreate1.o ${LIBS}

mqcreate: 	mqcreate.o
		${CC} ${CFLAGS} -o $@ mqcreate.o ${LIBS}

mqunlink: 	mqunlink.o
		${CC} ${CFLAGS} -o $@ mqunlink.o ${LIBS}

mqgetattr: 	mqgetattr.o
		${CC} ${CFLAGS} -o $@ mqgetattr.o ${LIBS}

mqreceive:	mqreceive.o
		${CC} ${CFLAGS} -o $@ mqreceive.o ${LIBS}

mqsend:		mqsend.o
		${CC} ${CFLAGS} -o $@ mqsend.o ${LIBS}

mqsysconf:		mqsysconf.o
		${CC} ${CFLAGS} -o $@ mqsysconf.o ${LIBS}

clean:
		rm -f ${CLEANFILES}