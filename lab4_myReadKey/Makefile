CC = gcc
CFLAGS = -g -Wall
SRCS = rk_readkey.c rk_mytermsave.c rk_mytermrestore.c rk_mytermregime.c
OBJS = $(SRCS:.c=.o)
SRCS_TERM = Terminal/printTerminalBigChars.c Terminal/printTerminalMemory.c Terminal/printTerminalAllBox.c Terminal/myPrint.c Terminal/moveSelector.c Terminal/selector.c Terminal/setDefaultString.c Terminal/inputMemoryCell.c Terminal/keyHandler.c Terminal/printTerminalFlags.c
OBJS_TERM = $(SRCS_TERM:.c=.o)

.PHONY: clean

lab4_exe: Terminal main.o lib $(OBJS_TERM) $(SRCS_TERM)
	$(CC) $(CFLAGS) -o lab4_exe main.o $(OBJS_TERM) -L../lib -lmyTerms -lmyBigChars -lmyReadKey -lmySimpleComputer

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib: $(SRCS) $(OBJS)
#	$(CC) $(CFLAGS) -c $(SRCS)
	ar cr ../lib/libmyReadKey.a $(OBJS)
#
#Terminal:  $(SRCS_TERM)
#	$(CC) $(CFLAGS) -c $(SRCS_TERM)
##	ar cr ../../lib/libTerminal.a $(OBJS_TERM)

clean:
	rm -f *.o lab4_exe Terminal/*.o
