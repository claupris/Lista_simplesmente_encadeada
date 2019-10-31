//
//
typedef struct _ALUNO_ {
    char nome[80];
    char casa[40];
    int anoCurso;
    float altura;
    int idade;
} Aluno;


/**
    attrib  valor
      0 -   nome
      1 -   casa
      2 -   ano curso
      3 -   altura
      4 -   idade
*/
int cmp(void * a, void * b, int attrib); // compara dados da estrutura aluno //

Aluno * createAluno();

void setDadosAluno(Aluno * a, int attrib);

void printDadosAlunos(void * a);

