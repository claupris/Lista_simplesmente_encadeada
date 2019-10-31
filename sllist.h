//#include <stdio.h>
//#include <stdlib.h>

typedef struct _slNode_ {
    void * data;
    struct _slNode_ * next;
} SLNode;

typedef struct _slList_ {
    SLNode * first;
    int (* comp)(void *, void *, int );
    void (* print)(void *);
    int sllsize;
} SLList;

SLList * sllCreate(int (* compare)(void *, void *, int), void (* print)(void *));

int sllDestroy(SLList * l);

int sllDestroyAll(SLList * l);

int sllInsertFirst(SLList * l, void * data);

int sllInsertLast(SLList * l, void * data);

void * sllRemoveFirst(SLList * l);

void * sllRemoveLast(SLList * l);

/**
    attrib  valor
      0 -   nome
      1 -   casa
      2 -   ano curso
      3 -   altura
      4 -   idade
*/
void * sllGetAluno(SLList * l, int attrib, void * key);

int sllGetSize(SLList * l);

int sllCountNodes(SLList * l);

void sllPrint(SLList * l, void * item);

void sllPrintAll(SLList * l);

void * sllRemoveSpecAluno(SLList * l, int attrib, void * key);
