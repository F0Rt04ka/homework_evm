CC = gcc
CFLAGS = -g -Wall
SRCS = bc_bigcharread.c bc_bigcharwrite.c bc_box.c bc_getbigcharpos.c bc_printA.c bc_printbigchar.c bc_setbigcharpos.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

lab3_exe: main.o lib
	$(CC) $(CFLAGS) -o lab3_exe main.o -L../lib/ -lmyTerms -lmyBigChars

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar cr ../lib/libmyBigChars.a $(OBJS)

clean:
	rm -f *.o *.a lab3_exe

