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

# Сборка всеx лаб с исполняемыми файлами
all:
	@if [ ! -d lib ] ; then echo "creating directory `lib`" ; mkdir lib; else echo "Directory lib exist"; fi
	cd lab1_mySimpleComputer && make
	cd lab2_consoleSC && make
	cd lab3_myBigChars && make
	cd lab5_signals && make
	cd lab4_myReadKey && make

# Полная очистка
clean_all: clean_lib
	cd lab1_mySimpleComputer && make clean
	cd lab2_consoleSC && make clean
	cd lab3_myBigChars && make clean
	cd lab4_myReadKey && make clean
	cd lab5_signals && make clean
	cd lab6_hdd && make clean
	rmdir lib

# Очистка папки с либами
clean_lib:
	cd lib && rm -f *.a