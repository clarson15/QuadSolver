CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o foutput.o
	${CC} ${CFLAGS} -o test test.o foutput.o

test.o:
	${CC} ${CFLAGS} -c test.c

foutput.o:
	${CC} ${CFLAGS} -c foutput.c

clean:
	rm -rf test *.o core

build: foutput.o
	cp foutput.o ../../build
