#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "menu.h"

void menu_titulo() {

    printf("----------------------------------------------------------\n");
    printf("!!! BEM VINDO A ESCOLA DE MAGIA E BRUXARIA DE HOGWARTS !!!\n");
    printf("----------------------------------------------------------\n");
}

void menu_principal() {

    printf("1 - Criar uma turma em HOGWARTS\n");
    printf("2 - Matricular um novo aluno\n");
    printf("3 - Buscar um aluno matriculado\n");
    printf("4 - Expulsar  um aluno indisciplinado\n");
    printf("5 - Listar todos os alunos matriculados\n");
    printf("6 - Remover a turma de HOGWARTS\n");
    printf("0 - Sair\n");
}

void menu_msg(char * str) {
    if(str != NULL) {
       puts(str);
    }
}

int menu_opcao() {

    int op;
    printf("----------------------------------------------------------\n");
    printf("opcao: ");
    scanf("%d",&op);

    //clear_keyboard_buffer();

    return op;
}
