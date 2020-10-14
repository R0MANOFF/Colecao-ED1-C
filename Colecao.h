#ifndef _COLECAO_H
#define _COLECAO_H

typedef struct Alunos{
    int matricula;
    char nome;
    float nota;
}Alunos;

typedef struct Colecao{
    int maxItens;
    int nItens;
    int curItem;
    void **elms;
}Colecao;

Colecao *colCreate(int n);
int colInsert(Colecao *c, void *item);
void *colRetirar(Colecao *C, void *item);
void *colBuscar(Colecao *c, void *key);
void *colPrint(Colecao *c);
void colDestruir(Colecao *c);




#endif