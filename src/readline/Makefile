CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o readline.o
	${CC} ${CFLAGS} -o test test.o readline.o -lcunit

test.o:
	${CC} ${CFLAGS} -c test.c

readline.o:
	${CC} ${CFLAGS} -c readline.c

clean:
	rm -rf test *.o core logfile

build: readline.o
	cp readline.o ../../build
