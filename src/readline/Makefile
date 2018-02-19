CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o readline.o
	${CC} ${CFLAGS} -o test test.o readline.o

test.o:
	${CC} ${CFLAGS} -c test.c

readline.o:
	${CC} ${CFLAGS} -c readline.c

clean:
	rm -rf test *.o core

build: readline.o
	cp readline.o ../../build
