CC = gcc
CFLAGS = -g -Wall -std=c99
SRCS = signals.c
OBJS = $(SRCS:.c=.o)

.PHONY: clean

libSignals: $(SRCS) $(OBJS)
	ar cr ../lib/libSignals.a $(OBJS)

clean:
	rm -f *.o lab5_exe