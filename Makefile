all: mySimpleComputer myTerms myBigChars

mySimpleComputer:
	cd lab1_mySimpleComputer && make
myTerms:
	cd lab2_consoleSC && make
myBigChars:
	cd lab3_myBigChars && make

lib: libmySimpleComputer.a libmyTerms.a libmyBigChars.a

libmySimpleComputer.a:
	cd lab1_mySimpleComputer && make lib

libmyTerms.a:
	cd lab2_consoleSC && make lib

libmyBigChars.a:
	cd lab3_myBigChars && make lib

clean_all: clean_lib
	cd lab1_mySimpleComputer && rm -f *.o *.a lab1_exe
	cd lab2_consoleSC && rm -f *.o *.a lab2_exe
	cd lab3_myBigChars && rm -f *.o *.a lab3_exe

clean_lib:
	cd lib && rm -f *.a