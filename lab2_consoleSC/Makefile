CC = gcc
CFLAGS = -g -Wall -std=c99
SRCS = myTerms.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

lab2_exe: main.o lib
	$(CC) $(CFLAGS) -o lab2_exe main.o -L../lib -lmyTerms

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib: $(SRCS) myTerms.h
	$(CC) $(CFLAGS) -c $(SRCS)
	ar cr ../lib/libmyTerms.a $(OBJS)

clean:
	rm -f *.o *.a lab2_exe
