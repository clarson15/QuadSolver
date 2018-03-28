CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

rtest: test
	./test

test: test.o foutput.o
	${CC} ${CFLAGS} -o test test.o foutput.o -lcunit

test.o:
	${CC} ${CFLAGS} -c test.c

foutput.o:
	${CC} ${CFLAGS} -c foutput.c

clean:
	rm -rf test *.o core logfile testfile

build: foutput.o
	cp foutput.o ../../build
