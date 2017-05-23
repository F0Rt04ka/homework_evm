CC = gcc
CFLAGS = -g -Wall -std=c99
SRCS = mySimpleComputer.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

lab1_exe: main.o lib
	$(CC) $(CFLAGS) -o lab1_exe main.o -L../lib -lmySimpleComputer

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar cr ../lib/libmySimpleComputer.a $(OBJS)

clean:
	rm -f *.o *.a lab1_exe