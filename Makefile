# Makefile for FIFO queue
# Lev Bernstein

CC		= gcc

CFLAGS		= -g  -Wall -std=c99

queue: queue.c
	$(CC) $(CFLAGS) -o queue queue.c

clean:
	rm -f *~ *.o a.out queue