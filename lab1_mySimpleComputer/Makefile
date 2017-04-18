all: libmySimpleComputer.a  main.o
	gcc -o lab1_exe main.o -L. -lmySimpleComputer

main.o: main.c
	gcc -c main.c

libmySimpleComputer.a: mySimpleComputer.o
	ar cr libmySimpleComputer.a mySimpleComputer.o

lib: mySimpleComputer.o
	ar cr ../lib/libmySimpleComputer.a mySimpleComputer.o
	rm -f *.o

mySimpleComputer.o: mySimpleComputer.c constantsRegisterFlags.h
	gcc -c mySimpleComputer.c

clean:
	rm -f *.o *.a lab1_exe