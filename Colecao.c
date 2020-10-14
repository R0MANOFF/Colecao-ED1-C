#include <stdlib.h>
#include <stdio.h>
#include _COLECAO_H_

Colecao *colCreate(int n){
    Colecao *c;
    if (n > 0){
        c = (Alunos*)malloc(sizeof(Alunos));
        if(c!=NULL){
            c->elms = (void**)malloc(sizeof(void*)*n);
            if(c->elms != NULL){
                c->nItens = 0;
                c->maxItens = 0;
                return c;
            }
            free(c);
        }
    }
    return NULL;
}
