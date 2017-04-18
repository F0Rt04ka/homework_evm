lab3_exe: main.o libmyBigChars.a
	gcc -g -Wall -o lab3_exe main.o -L../lib/ -lmyTerms -L. -lmyBigChars

main.o: main.c
	gcc -c -g -Wall main.c

libmyBigChars.a: bc_bigcharread.o bc_bigcharwrite.o bc_box.o bc_getbigcharpos.o bc_printA.o bc_printbigchar.o bc_setbigcharpos.o
	ar cr libmyBigChars.a bc_bigcharread.o bc_bigcharwrite.o bc_box.o bc_getbigcharpos.o bc_printA.o bc_printbigchar.o bc_setbigcharpos.o

lib: bc_bigcharread.o bc_bigcharwrite.o bc_box.o bc_getbigcharpos.o bc_printA.o bc_printbigchar.o bc_setbigcharpos.o
	ar cr ../lib/libmyBigChars.a bc_bigcharread.o bc_bigcharwrite.o bc_box.o bc_getbigcharpos.o bc_printA.o bc_printbigchar.o bc_setbigcharpos.o
	rm -f *.o

bc_bigcharread.o: bc_bigcharread.c
	gcc -c -g -Wall bc_bigcharread.c
bc_bigcharwrite.o: bc_bigcharwrite.c
	gcc -c -g -Wall bc_bigcharwrite.c
bc_box.o: bc_box.c
	gcc -c -g -Wall bc_box.c
bc_getbigcharpos.o: bc_getbigcharpos.c
	gcc -c -g -Wall bc_getbigcharpos.c
bc_printA.o: bc_printA.c
	gcc -c -g -Wall bc_printA.c
bc_printbigchar.o: bc_printbigchar.c
	gcc -c -g -Wall bc_printbigchar.c
bc_setbigcharpos.o: bc_setbigcharpos.c
	gcc -c -g -Wall bc_setbigcharpos.c

clean:
	rm -f *.o *.a lab3_exe

