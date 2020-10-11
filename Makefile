all: p2p run 
CC=gcc
CFLAGS=-I.

p2p: p2p.c
	$(CC) -o p2p p2p.c

run: p2p
	./p2p
