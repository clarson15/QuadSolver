CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o qsolve.o
	${CC} ${CFLAGS} -o test test.o qsolve.o -lm -lcunit

test.o:
	${CC} ${CFLAGS} -c test.c

qsolve.o:
	${CC} ${CFLAGS} -c qsolve.c 

clean:
	rm -rf test *.o core logfile

build: qsolve.o
	cp qsolve.o ../../build
