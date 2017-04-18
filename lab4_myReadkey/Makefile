CC = gcc
CFLAGS = -g -Wall
SRCS = rk_readkey.c rk_mytermsave.c rk_mytermrestore.c rk_mytermregime.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

lab2_exe: main.o lib
	$(CC) $(CFLAGS) -o lab4_exe main.o -L../lib -lmyTerms -lmyBigChars

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib:
	$(CC) $(CFLAGS) -c $(SRCS)
	ar cr ../lib/libmyReadKey.a $(OBJS)

clean:
	rm -f *.o lab4_exe
