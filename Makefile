# Создание всех либ в папку lib
lib: create_lib libmySimpleComputer.a libmyTerms.a libmyBigChars.a libmyReadKey.a

libmySimpleComputer.a:
	cd lab1_mySimpleComputer && make lib
libmyTerms.a:
	cd lab2_consoleSC && make lib
libmyBigChars.a:
	cd lab3_myBigChars && make lib
libmyReadKey.a:
	cd lab4_myReadKey && make lib

# Сборка всеx лаб с исполняемыми файлами (практически бесполезно)
all: create_lib lab1 lab2 lab3 lab4

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
	cd lab1_mySimpleComputer && make clean
	cd lab2_consoleSC && make clean
	cd lab3_myBigChars && make clean
	cd lab4_myReadKey && make clean
	cd lab5_signals && make clean
	cd lab6_hdd && make clean

# Очистка папки с либами
clean_lib:
	cd lib && rm -f *.a

create_lib:
	@if [ ! -d $(DIR) ] ; then echo "creating directory `lib`" ; mkdir lib; fi

.PHONY: create_lib