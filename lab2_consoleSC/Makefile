lab2_exe: main.o libmyTerms.a
	gcc -o lab2_exe main.o -L. -lmyTerms

main.o: main.c
	gcc -c main.c

libmyTerms.a: myTerms.o
	ar cr libmyTerms.a myTerms.o

myTerms.o: myTerms.c myTerms.h
	gcc -c myTerms.c

clean:
	rm -f *.o *.a lab2_exe
