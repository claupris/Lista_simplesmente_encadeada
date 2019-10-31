#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "sllist.h"

// cria a lista
SLList * sllCreate(int (* compare)(void *, void *, int), void (* printer)(void *)) {
    SLList * l = (SLList *)malloc(sizeof(SLList)); //cria SLList
    if (l != NULL) { // testa se a lista existe
        l->first = NULL; // faz com que o primeiro elemento da lista aponte para NULL
        l->sllsize = 0;
        l->comp = compare;
        l->print = printer;
        return l; // retorna a lista
    }
    return NULL;
}

// destroi a lista
int sllDestroy(SLList * l) {
    if (l != NULL) {
        if (l->first == NULL) {
            free(l);
            l = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

// destroi a lista completa
int sllDestroyAll(SLList * l) {
    if (l != NULL) {
        if (l->first != NULL) {
            SLNode * cur = l->first;
            SLNode * aux = NULL;
            while(cur->next != NULL){
                aux = cur;
                cur = cur->next;
                free(aux->data);
                free(aux);
            }
        }
        free(l);
        return TRUE;
    }
    return FALSE;
}

// insere um novo elemento no inicio da lista
int sllInsertFirst(SLList * l, void * data) {
    if(l != NULL) {
        SLNode * newNode = (SLNode *)malloc(sizeof(SLNode));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->next = l->first;
            l->first = newNode;
            l->sllsize++;
            return TRUE;
        }
    }
    return FALSE;
}


// insere um novo elemento no final da lista
int sllInsertLast(SLList * l, void * data) {
    if(l != NULL) {
        SLNode * newNode = (SLNode *)malloc(sizeof(SLNode));
        if (newNode != NULL) {
            newNode->data = data;
            newNode->next = NULL;
            if (l->first == NULL) {
                l->first = newNode;
            } else {
                SLNode * cur = l->first;
                while(cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = newNode;
            }
            l->sllsize++;
            return TRUE;
        }
    }
    return FALSE;
}

// remove um elemento do inicio da lista
void * sllRemoveFirst(SLList * l) {
    void * data;
    SLNode * aux;
    if (l!=NULL) {
        aux = l->first;
        data = aux->data;
        l->first = aux->next;
        free(aux);
        l->sllsize--;
        return data;
    }
    return NULL;
}


// remove um elemento do final da lista
void * sllRemoveLast(SLList * l) {
    if (l != NULL) {
        if (l->first != NULL) {
            SLNode * cur = l->first;
            //
            while(cur->next != NULL) {
                cur = cur->next;
            }
            //
            void * val = cur->data;
            free(cur);
            l->sllsize--;
            return val;
        }
    }
    return NULL;
}

//  attrib  valor
//    0 -   nome
//    1 -   casa
//    2 -   ano curso
//    3 -   altura
//    4 -   idade
void * sllGetAluno(SLList * l, int attrib, void * key) {
    if (l != NULL) {
          if(l->first != NULL) {
               SLNode * cur = l->first;
               int ret = 0;
               while(cur != NULL) {
                   switch(attrib) {
                       case 0:{
                           ret = l->comp(cur->data, key, 0); // nome
                           if(ret) {
                             return cur->data;
                           }
                           break;
                       }
                       case 1:{
                           ret = l->comp(cur->data, key, 1);// casa
                           if(ret) {
                             return cur->data;
                           }
                           break;
                       }
                   }
                   cur = cur->next;
                   ret = 0;
               }
          }
    }
    return NULL;
}

int sllGetSize(SLList * l) {
    if(l != NULL) {
        return l->sllsize;
    }
    return 0;
}

//conta a quantidade de alunos
int sllCountNodes(SLList * l) {
    int sllenght = 0;
    if(l != NULL) {
        SLNode * cur = l->first;
        while(cur != NULL) {
            sllenght++;
            cur = cur->next;
        }
    }
    return sllenght;
}

void sllPrint(SLList * l, void * item) {
    if(l != NULL) {
        l->print(item);
    }
}

void sllPrintAll(SLList * l) {
    if(l  != NULL) {
        SLNode * cur = l->first;
        while(cur != NULL) {
            l->print(cur->data);
            cur = cur->next;
        }
    }
}

void * sllRemoveSpecAluno(SLList * l, int attrib, void * key) {
    if (l != NULL) {
          if(l->first != NULL) {
               SLNode * cur = l->first;
               int ret = 0;
               void * data;
               while(cur != NULL) {
                   switch(attrib) {
                       case 0:{
                           ret = l->comp(cur->data, key, 0); // nome
                           if(ret) {
                             data = cur->data;
                             l->sllsize--;
                             free(cur);
                             return data;
                           }
                           break;
                       }
                       case 1:{
                           ret = l->comp(cur->data, key, 1);// casa
                           if(ret) {
                             data = cur->data;
                             l->sllsize--;
                             free(cur);
                             return data;
                           }
                           break;
                       }
                   }
                   cur = cur->next;
                   ret = 0;
               }
          }
    }
    return NULL;
}

/*void *sllRemoveSpec(Sllist *l, void* key, int (*cmp)(void*,void*))
{
    Slnode *cur, *prev;
    int stat;
    void *data;
    if(l!=NULL){
        if(l->first!=NULL){
            cur=l->first;
            prev=NULL;
            stat=comp(key,cur->data);
            while(stat!=TRUE && cur->next!=NULL){
                prev = cur;
                cur=cur->next;
                stat=comp(key,cur->data);
            }
            if(stat == TRUE){
                if(prev!=NULL){
                    prev->next = cur->next;
                }else{
                    l->first = cur->next;
                }
                data = cur->data;
                free(cur);
                return data;
            }
        }
    }
    return NULL;
}*/


