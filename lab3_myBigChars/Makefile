lab3_exe: main.o libmyBigChars.a
	gcc -o lab3_exe main.o -L. -lmyBigChars

main.o: main.c
	gcc -c main.c

libmyTBigChars.a: myBigChars.o
	ar cr libmyBigChars.a myBigChars.o

myBigChars.o: myBigChars.c myBigChars.h
	gcc -c myBigChars.c

clean:
	rm -f *.o *.a lab3_exe
