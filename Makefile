# Создание всех либ в папку lib
lib: libmySimpleComputer.a libmyTerms.a libmyBigChars.a libmyReadKey.a

libmySimpleComputer.a:
	cd lab1_mySimpleComputer && make lib
libmyTerms.a:
	cd lab2_consoleSC && make lib
libmyBigChars.a:
	cd lab3_myBigChars && make lib
libmyReadKey.a:
	cd lab4_myReadKey && make lib

# Сборка всеx лаб с исполняемыми файлами (практически бесполезно)
all: lab1 lab2 lab3 lab4

lab1:
	cd lab1_mySimpleComputer && make
lab2:
	cd lab2_consoleSC && make
lab3:
	cd lab3_myBigChars && make
lab4:
	cd lab4_myReadKey && make

# Полная очистка
clean_all: clean_lib
	cd lab1_mySimpleComputer && rm -f *.o *.a lab1_exe
	cd lab2_consoleSC && rm -f *.o *.a lab2_exe
	cd lab3_myBigChars && rm -f *.o *.a lab3_exe
	cd lab4_myReadKey && rm -f *.o *.a lab4_exe

# Очистка папки с либами
clean_lib:
	cd lib && rm -f *.a
