include ../Make.defines

incr1: 	incr1.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

incr2: 	incr2.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

incr3: 	incr3.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

incr_map_anon:	incr_map_anon.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

incr_dev_zero: 	incr_dev_zero.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test1: 	test1.o
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

test2: test2.o
	gcc -g -Wall -o test2 test2.o ../libunpipc.a -lpthread -lrt

clean:
	rm -f ${CLEANFILES}