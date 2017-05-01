#ifndef HOMEWORK_EVM_TERMINAL_H
#define HOMEWORK_EVM_TERMINAL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../../lab1_mySimpleComputer/mySimpleComputer.h"
#include "../../lab2_consoleSC/myTerms.h"
#include "../../lab3_myBigChars/myBigChars.h"
#include "../myReadkey.h"

#define SAVE_MEMORY_FILE "saveMemory"

// Вывод строки через write
void myPrint (char* string);

// Отрисовка ячеек памяти
void printTerminalMemory (void);

// Вывод флагов регистра
int printTerminalFlags (void);

// Установка стандартных цветов и переход на строку под терминальным окном
void setDefaultString (void);

// Рисование строки большими символами
void printTerminalBigChars (char* string);

// Рисование всех рамок
int printTerminalAllBox (void);

// Перемещение селектора
int moveSelector (enum keys key);

int getSelector (void);

void setSelector (int select);

// Обработчик нажатий клавиш
int keyHandler (enum keys key);

// Ввод ячейки памяти
int inputMemoryCell (void);

#endif //HOMEWORK_EVM_TERMINAL_H
