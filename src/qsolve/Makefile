CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o qsolve.o
	${CC} ${CFLAGS} -o test test.o qsolve.o -lm

test.o:
	${CC} ${CFLAGS} -c test.c

qsolve.o:
	${CC} ${CFLAGS} -c qsolve.c -lm

clean:
	rm -rf test *.o core

build: qsolve.o
	cp qsolve.o ../../build
