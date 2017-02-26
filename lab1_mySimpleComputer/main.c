#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "mySimpleComputer.h"

int main() {
    setlocale(LC_ALL, "Russian");

    sc_regInit();
    while (1) {
        printf("Текущее значение регистра: %d\n", getRegistr());

        int flag, value;
        printf("Какой флаг установить в какое значение? (1 - 5)\n");
        printf("Флаг (1-5): ");
        scanf("%d", &flag);
        printf("\nЗначение (0 или 1): ");
        scanf("%d", &value);

        switch (flag){
            case 1: flag = FLAG_A;
                break;

            case 2: flag = FLAG_B;
                break;

            case 3: flag = FLAG_C;
                break;

            case 4: flag = FLAG_D;
                break;

            case 5: flag = FLAG_E;
                break;

            default: exit(1);
        }

        sc_regSet(flag, value);
    }

    return 0;
}