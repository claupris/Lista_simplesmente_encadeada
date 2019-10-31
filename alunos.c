#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "alunos.h"


//  attrib  valor
//    0 -   nome
//    1 -   casa
//    2 -   ano curso
//    3 -   altura
//    4 -   idade
int cmp(void * a, void * b, int attrib) {

    int ret = 0;

    Aluno * aux = (Aluno *)a;

    switch(attrib) {
        case 0: {
                ret = strcmp(aux->nome, (char *) b) ;
                break;
        }
        case 1: {
                ret = strcmp(aux->casa, (char *) b) ;
                break;
        }
        case 2: {
                ret = !(( aux->anoCurso) == (*(int *) b)) ;
                break;
        }
        case 3: {
                ret = !(aux->altura == (*(float *) b)) ;
                break;
        }
        case 4: {
                ret = !((aux->idade) == (*(int *) b)) ;
                break;
        }
    }

    return (ret == 0) ? TRUE : FALSE;
}

//
Aluno * createAluno() {
    Aluno * a = (Aluno *)malloc(sizeof(Aluno));

    return a;
}
/**
   0 - todos
   1 - nome
   2 - casa
   3 - ano curso
   4 - altura
   5 - idade
*/
void setDadosAluno(Aluno * a, int attrib) {
    if(a != NULL) {
        if(attrib == 0 || attrib == 1) {
            puts("Entre com o nome do aluno:");
            scanf("%s", a->nome);
        }
        if(attrib == 0 || attrib == 2) {
            if (attrib == 0) {
                puts(randonCasa(a->casa));
            } else {
                scanf("%s", a->casa);
            }
        }
        if(attrib == 0 || attrib == 3) {
            puts("Entre com o ano que o aluno deve entrar:");
            puts("(1)\t(2)\t(3)\t(4)\t(5)");
            scanf("%i", &a->anoCurso);
            while(a->anoCurso<1 || a->anoCurso> 5) {
                puts("Opcao inválida! entre com o ano certo:");
                scanf("%i", &a->anoCurso);
            }
        }
        if(attrib == 0 || attrib == 4) {
            puts("Entre com a altura do aluno:");
            scanf("%f", &a->altura);
        }
        if(attrib == 0 || attrib == 5) {
            puts("Entre com a idade do aluno:");
            scanf("%i", &a->idade);
        }
        clear_keyboard_buffer();
    }
}


void printDadosAlunos(void * a) {
    if(a != NULL) {
        Aluno * aux = (Aluno *)a;
        printf("----------------------------------------------------------\n");
        printf("Nome: %s\n", aux->nome);
        printf("Casa: %s\n", aux->casa);
        printf("Ano Curso: %i\n", aux->anoCurso);
        printf("Altura: %.2f\n", aux->altura);
        printf("Idade: %i\n", aux->idade);
    }
}

