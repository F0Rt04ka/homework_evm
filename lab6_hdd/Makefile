lab6_exe: hdd.o main.o
	gcc -g -Wall -std=c99 -o lab6_exe main.o hdd.o -L../lib -lmyTerms -lmyBigChars

hdd.o:
	gcc -g -Wall -std=c99 -c -o hdd.o hdd.c

main.o:
	gcc -g -Wall -std=c99 -c -o main.o main.c

clean:
	rm -f *.o lab6_exe