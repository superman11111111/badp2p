CC=gcc

all: p2p 
p2p: p2p.c
	$(CC) -pthread -o p2p.bin p2p.c

run: p2p
	./p2p
