CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o output.o
	${CC} ${CFLAGS} -o test test.o output.o

test.o:
	${CC} ${CFLAGS} -c test.c

output.o:
	${CC} ${CFLAGS} -c output.c

clean:
	rm -rf test *.o core

build: output.o
	cp output.o ../../build
