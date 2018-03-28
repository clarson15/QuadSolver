CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o validate.o
	${CC} ${CFLAGS} -o test test.o validate.o -lcunit

test.o: 
	${CC} ${CFLAGS} -c test.c

validate.o:
	${CC} ${CFLAGS} -c validate.c

clean:
	rm -rf test *.o core logfile

build: validate.o
	cp validate.o ../../build
