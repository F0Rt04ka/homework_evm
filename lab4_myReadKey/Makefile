CC = gcc
CFLAGS = -g -Wall -std=c99
SRCS = rk_readkey.c rk_mytermsave.c rk_mytermrestore.c rk_mytermregime.c
OBJS = $(SRCS:.c=.o)
TERMINAL_SOURCES = printTerminalBigChars printTerminalMemory printTerminalAllBox myPrint moveSelector selector setDefaultString inputMemoryCell keyHandler printTerminalFlags accumulator instructionCounter operation inputNum

SRCS_TERM = $(addprefix Terminal/,$(addsuffix .c, $(TERMINAL_SOURCES)))
OBJS_TERM = $(SRCS_TERM:.c=.o)

.PHONY: clean

lab4_exe: main.o lib
	$(CC) $(CFLAGS) -o lab4_exe main.o -L../lib -lTerminal

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

lib: $(SRCS) $(OBJS) $(SRCS_TERM) $(OBJS_TERM)
	ar cr ../lib/libmyReadKey.a $(OBJS)
	cd include && ar x ../../lib/libmyBigChars.a && ar x ../../lib/libmyReadKey.a && ar x ../../lib/libmyTerms.a && ar x ../../lib/libmySimpleComputer.a && ar x ../../lib/libSignals.a
	ar cr ../lib/libTerminal.a $(OBJS_TERM) include/*.o
	rm -f include/*.o

clean:
	rm -f *.o lab4_exe Terminal/*.o
