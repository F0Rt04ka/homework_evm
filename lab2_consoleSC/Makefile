lab2_exe: main.o libmyTerms.a
	gcc -g -Wall -o lab2_exe main.o -L. -lmyTerms

main.o: main.c
	gcc -c main.c

libmyTerms.a: myTerms.o
	ar cr libmyTerms.a myTerms.o

lib: myTerms.o
	ar cr ../lib/libmyTerms.a myTerms.o
	rm -f *.o

myTerms.o: myTerms.c myTerms.h
	gcc -c -g -Wall myTerms.c

clean:
	rm -f *.o *.a lab2_exe
