#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "funcoes.h"
#include "sllist.h"
#include "alunos.h"
#include "menu.h"


int main(void) {

    SLList * l = NULL;
    Aluno * a = NULL;
    int erro = 0;
    int quant = 0;

    while(TRUE) {

        clear_cls();
        menu_titulo();
        menu_principal();

        switch (menu_opcao()) {
            case 0: {
                    sllDestroyAll(l);
                    exit(0);
            }
            case 1: {
                    if (l == NULL) {
                        l = sllCreate(&cmp, &printDadosAlunos);
                        menu_msg("A turma foi criada com sucesso!");
                    } else {
                        menu_msg("ja existe uma turma!");
                    }
                    break;
            }
            case 2: {
                    if(l == NULL) {
                        menu_msg("A turma ainda nao foi criada!");
                    } else {
                        a = createAluno();
                        if(a != NULL) {
                            clear_cls();
                            setDadosAluno(a, 0);
                            clear_cls();
                            menu_msg("Inserir no inicio ou no fim ?\n(1) - inicio\n(2) - final\n");
                            switch (menu_opcao()) {
                                case 1: {
                                        erro = sllInsertFirst(l, (void *)a);
                                        break;
                                }
                                case 2: {
                                        erro = sllInsertLast(l, (void *)a);
                                        break;
                                }
                            }
                            if(erro) {
                                menu_msg("Aluno inserido !");
                            }

                        } else {
                            menu_msg("Aluno nao foi criado!");
                        }
                    }
                    break;
            }
            case 3:
            {
                    if(l == NULL) {
                        menu_msg("A turma ainda nao foi criada!");
                    } else {
                        a = createAluno();
                        if(a != NULL) {
                            clear_cls();
                            menu_msg("Buscar por nome ou casa ?\n(1) - Por Nome\n(2) - Por Casa\n");
                            switch (menu_opcao()) {
                                case 1: {
                                        clear_cls();
                                        setDadosAluno(a, 1);
                                        sllPrint(l, sllGetAluno(l, 0, (void *)a->nome));
                                        break;
                                }
                                case 2: {
                                        clear_cls();
                                        setDadosAluno(a, 2);
                                        sllPrint(l, sllGetAluno(l, 1, (void *)a->casa));
                                        break;
                                }
                            }

                        } else {
                            menu_msg("Falha ao buscar aluno!");
                        }
                    }
                    break;
            }
            case 4:
            {
                    if(l == NULL) {
                        menu_msg("A turma ainda nao foi criada!");
                    } else {
                        clear_cls();
                        menu_msg("Expulsar aluno no inicio ou no fim ?\n(1) - Inicio\n(2) - Final\n(3) - Por nome");
                        switch (menu_opcao()) {
                        case 1: {
                                sllPrint(l, sllRemoveFirst(l));
                                menu_msg("Aluno expulso!");
                                break;
                        }
                        case 2: {
                                sllPrint(l, sllRemoveLast(l));
                                menu_msg("Aluno expulso!");
                                break;
                        }
                        case 3: {
                            a = createAluno();
                            setDadosAluno(a, 1);
                            sllPrint(l, sllRemoveSpecAluno(l, 0, (void *)a->nome));
                            menu_msg("Aluno expulso!");
                            break;
                        }

                        }
                    }
                    break;
            }
            case 5: {
                    sllPrintAll(l);
                    break;
            }
            case 6: {
                    quant = sllGetSize(l);
                    printf("%i\n", quant);
                    if (quant > 0) {
                        menu_msg("A turma n pode ser excluída pois ainda existem alunos matriculados");
                    } else {
                        erro = sllDestroy(l);
                        if (erro == 1) {//sem erro
                            l = NULL;
                            menu_msg("Turma removida com sucesso!!");
                        }
                    }
                    break;
            }
        }
        erro = 0;
        a = NULL;
        clear_keyboard_buffer();
        getchar();

    }
    return 0;
}

/*
    int op, insert, ale, busca;
    char *nome, *name;
    //SLNode *name;
    SLList *l = NULL;
    aluno *a = (aluno *) malloc(sizeof(aluno));
    srand(time(NULL));

    do
    {
        clear_cls();
        printf("-----------------------------------------------------\n");
        printf("BEM VINDO A ESCOLA DE MAGIA E BRUXARIA DE HOGWARTS!!!\n");
        printf("-----------------------------------------------------\n\n");

        printf("---------------\tEscolha uma opcao:\t-----------------\n");
        printf("1 - Criar uma turma em HOGWARTS\n");
        printf("2 - Matricular um novo aluno\n");
        printf("3 - Buscar um aluno ja matriculado\n");
        printf("4 - EXPULSAR  um aluno indisciplinado\n");
        printf("5 - Listar todos os alunos matriculados\n");
        printf("6 - Remover a turma de HOGWARTS\n");
        printf("0 - Sair\n");
        printf("---------------\tEscolha uma opcao:\t-----------------\n");
        scanf("%d",&op);
        clear_cls();
        printf("-----------------------------------------------------\n");
        printf("BEM VINDO A ESCOLA DE MAGIA E BRUXARIA DE HOGWARTS!!!\n");
        printf("-----------------------------------------------------\n\n");
        clear_keyboard_buffer();

        switch(op)
        {
        case 1:
        {

            if (l==NULL)
            {
                l = sllCreate(&cmp);
                printf("A turma foi criada com sucesso!");
                getchar();
            }
            else
            {
                printf("jah existe uma turma!");
                getchar();
            }
            break;
        }
        case 2:
        {

            if(l == NULL)
            {
                printf("A turma ainda nao foi criada!!\n");
                getchar();
                system("clear");
            }
            else
            {
                printf("deseja inserir no inicio da turma ou no final?\n(1) - inicio\n(2) - final\n");
                scanf("%d", &insert);
                switch(insert)
                {
                case 1:
                {
                    printf("informe o nome do aluno:\n");
                    scanf("%s",(a->nome));
                    printf("informe o ano que o aluno deve entrar:\n");
                    printf("(1)\t(2)\t(3)\t(4)\t(5)\n");
                    scanf("%d",&(a->anoCurso));
                    while (a->anoCurso< 1 || a->anoCurso> 5)
                    {
                        printf("opcao invalida, digite a opcao correta!\n");
                        scanf("%d",&(a->anoCurso));
                    }
                    printf("informe a altura do aluno:\n");
                    scanf("%f",&(a->altura));
                    printf("informe a idade do aluno:\n");
                    scanf("%d",&(a->idade));
                    ale = rand()%4+1;
                    system("CLS");
                    switch(ale)
                    {
                    case 1:
                    {
                        strcpy(a->casa,"Grinffindor");
                        break;
                    }
                    case 2:
                    {
                        strcpy(a->casa, "Slytherin");
                        break;
                    }
                    case 3:
                    {
                        strcpy(a->casa, "Hufflepuff");
                        break;
                    }
                    case 4:
                    {
                        strcpy(a->casa, "Ravenclaw");
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                    sllInsertFirst(l, a);
                    clear_keyboard_buffer();
                    break;
                }
                case 2:
                {
                    printf("informe o nome do aluno:\n");
                    scanf("%s",(a->nome));
                    printf("informe o ano que o aluno deve entrar:\n");
                    printf("(1)\t(2)\t(3)\t(4)\t(5)\n");
                    scanf("%d",&(a->anoCurso));
                    while (a->anoCurso< 1 || a->anoCurso> 5)
                    {
                        printf("opcao invalida, digite a opcao correta!\n");
                        scanf("%d",&(a->anoCurso));
                    }
                    printf("informe a altura do aluno:\n");
                    scanf("%f",&(a->altura));
                    printf("informe a idade do aluno:\n");
                    scanf("%d",&(a->idade));
                    ale = rand()%4+1;
                    system("CLS");
                    switch(ale)
                    {
                    case 1:
                    {
                        strcpy(a->casa,"Grinffindor");
                        break;
                    }
                    case 2:
                    {
                        strcpy(a->casa, "Slytherin");
                        break;
                    }
                    case 3:
                    {
                        strcpy(a->casa, "Hufflepuff");
                        break;
                    }
                    case 4:
                    {
                        strcpy(a->casa, "Ravenclaw");
                        break;
                    }
                    default:
                    {
                        break;
                    }
                    }
                    sllInsertLast(l, a);
                    clear_keyboard_buffer();
                    break;
                }
                }
            }
            break;
        }
        case 3:
        {
            printf("Deseja buscar por:\n(1) - nome\n(2) - casa\n");
            scanf("%d", &busca);
            switch(busca)
            {
            case 1:
            {
                printf("informe o nome a ser buscado:\n");
                scanf("%s", nome);
                name = sllGetAluno(l, 0, nome);
                if (name == NULL){
                    printf("nao existe nenhum aluno em HOGWARTS com esse nome!");
                }else{
                    printf("nome: %s",sllGetAluno(l, 0, a->nome));
                    printf("Casa: %s",sllGetAluno(l, 1, a->casa));
                    printf("Altura: %.2f",sllGetAluno(l, 2, a->altura));
                    printf("Idade: %d",sllGetAluno(l, 3, a->idade));
                    printf("Ano: %d",sllGetAluno(l, 4, a->anoCurso));
                }
                break;
            }
            case 2:
            {
                printf("informe a casa a ser buscado:\n");
                printf("Grinffindor\nSlytherin\nHufflepuff\nRavenclaw\n");
                scanf("%s", nome);
                name = sllGetAluno(l, 1, nome);
                break;
            }
            default:
            {
                printf("Opcao inválida!");
                break;
            }
            }
            break;
        }
        case 4:
        {
            //printf("Digite o nome do aluno a ser removido:\n");
            //scanf("%s",name->data);
            break;
        }
        case 5:
        {

            break;
        }
        case 6:
        {

            break;
        }
        case 0:
        {
            printf("Ate a Proxima!!\n\n");
            break;
        }
        default:
        {
            printf("\nOpcao invalida!!!\n");
            getchar();
            system("clear");
            break;
        }
        }
    }
    while(op);
    */
