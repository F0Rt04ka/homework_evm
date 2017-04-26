#include "myBigChars.h"

int getBigChar (char bigChar, int big[2])
{
    int bigChars[18][2] = {
            {3284386815, 4291019715}, // 0
            {404232222, 4279769112},  // 1
            {4290822399, 4278387711}, // 2
            {4290822399, 4290822399}, // 3
            {4291019715, 3233857791}, // 4
            {4278387711, 4290822336}, // 5
            {4278387711, 4291019775}, // 6
            {811647231, 50727960},    // 7
            {4286677503, 4286677503}, // 8
            {4286677503, 405823680},  // 9
            {3278257176, 3284386815}, // A
            {2139325311, 4286808959}, // B
            {50593788, 4244570883}, // C
            {2206434175, 2139325315}, // D
            {4278387711, 4278387711}, // E
            {4278387711, 50529279}, // F
            {4279769112, 404232447}, //PLUS
            {0, 255} // MINUS
    };
    int selectNumber;

    switch (bigChar) {
        case ' ':
        case '0':
            selectNumber = 0;
            break;
        case '1':
            selectNumber = 1;
            break;
        case '2':
            selectNumber = 2;
            break;
        case '3':
            selectNumber = 3;
            break;
        case '4':
            selectNumber = 4;
            break;
        case '5':
            selectNumber = 5;
            break;
        case '6':
            selectNumber = 6;
            break;
        case '7':
            selectNumber = 7;
            break;
        case '8':
            selectNumber = 8;
            break;
        case '9':
            selectNumber = 9;
            break;
        case 'A':
            selectNumber = 10;
            break;
        case 'B':
            selectNumber = 11;
            break;
        case 'C':
            selectNumber = 12;
            break;
        case 'D':
            selectNumber = 13;
            break;
        case 'E':
            selectNumber = 14;
            break;
        case 'F':
            selectNumber = 15;
            break;
        case '+':
            selectNumber = 16;
            break;
        case '-':
            selectNumber = 17;
            break;
        default:
            return -1;
    }

    big[0] = bigChars[selectNumber][0];
    big[1] = bigChars[selectNumber][1];

    return 0;
}