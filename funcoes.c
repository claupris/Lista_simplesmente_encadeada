#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include <time.h>
#include <string.h>




//
void clear_cls() {
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

//
void clear_keyboard_buffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return;
}

char * randonCasa(char * str) {
    srand(time(NULL));
    int op_rand = (rand()%4)+1;
    switch(op_rand) {
        case 1: {
            strcpy(str,"Grinffindor");
            break;
        }
        case 2: {
            strcpy(str, "Slytherin");
            break;
        }
        case 3: {
            strcpy(str, "Hufflepuff");
            break;
        }
        case 4: {
            strcpy(str, "Ravenclaw");
            break;
        }
        default: {
            break;
        }
    }
    return str;
}
