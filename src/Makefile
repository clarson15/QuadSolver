#Makefile for compiling and testing the QuadSolver.
CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

build: main.o
	cp main.o ../build/
	cd readline;\
	make build
	cd validate;\
	make build
	cd qsolve;\
	make build
	cd output;\
	make build
	cd ../build;\
	${CC} ${CFLAGS} -o quadsolver validate.o readline.o qsolve.o foutput.o main.o -lm

main.o:
	${CC} ${CFLAGS} -c main.c

rtest:
	cd readline;\
	make
	cd validate;\
	make
	cd qsolve;\
	make
	cd output;\
	make

run: build
	../build/quadsolver

clean:
	cd readline;\
	make clean
	cd validate;\
	make clean
	cd qsolve;\
	make clean
	cd output;\
	make clean
	cd ../build;\
	rm -rf quadsolver *.o core logfile
	rm -rf *.o core 
