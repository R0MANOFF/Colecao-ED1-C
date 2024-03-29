#include "Colecao.h"


// cria uma colecao
Colecao* colCriar(int maxItens){ 
  Colecao* c;
  if(maxItens > 0){  
    c = (Colecao *) malloc(sizeof(Colecao)); 
    if(c != NULL){ 
      c->item = (void* *) malloc(sizeof(void*)*maxItens); 
      if(c->item != NULL){
        c->numItens = -1;
        c-> maxItens = maxItens;
        return c; 
      }
      else{
        free(c);
      }
    }
  }
  return NULL;
}



// insere um aluno na colecao criada
int colInserir(Colecao *c, void* aluno){ 
  Aluno **a; // a gente n ta usando isso pra nada 
  Colecao *col;
  if(c != NULL){
    if(c->item != NULL){ 
      if(c->numItens < c->maxItens-1){
        c->numItens++;
        c->item[c->numItens] = aluno; 
        return TRUE;
      }
    }
  }
  return FALSE;
}



//busca um nome de um aluno dentro da colecao
void *colBuscar(Colecao *c, void* key,int(*cpm)(const void*, const void*)){

  void* a;
  int i = 0;
  int verificar,totalVet;
  //a = (void*)&i;

  if(c != NULL){
    if(c->item != NULL){
      if(c->numItens >= 0){
        while((verificar = cpm(c->item[i],key)) != TRUE){
          i++;
          totalVet = c->numItens;
          if(i > totalVet){
            break;
          }
        }
        if(verificar == 0){
          return NULL;
        }
        if(verificar == 1){
          return c->item[i];
        }
      }
    }
  }
  return NULL;
}

//remove um item da colecao
void *colRemover(Colecao *c, void* key,int(*cpm)(const void*, const void*)){

  void* *a;
  int i = 0, j=0;
  int verificar,totalVet;
  a = (void*)&i;
  void *aux;

  if(c != NULL){
    if(c->item != NULL){
      if(c->numItens >= 0){ 
        while((verificar = cpm(c->item[i],key)) != TRUE){
          i++;
          totalVet = c->numItens;
          if(i > totalVet){
            break;
          }
        }
        if(verificar == 0){
          return NULL;
        }
        if(verificar == 1){
          j = i;
          while(j <= c->numItens){ // reorganiza
            c->item[j] = c->item[j+1];
            j++;
          }
          c->numItens--;
          return aux;
        }
      }
    }
  }
  return NULL;
}
  



  
// imprime os campos de cada aluno da colecao
void *imprimirColecao(Colecao *c, int i){
  void* aux;
  if(c!=NULL){
    if(c->item != NULL){
        aux = c->item[i];
        return aux;
    }
  }
}

// destroi a colecao
int coldestruir(Colecao *c){ 
  if(c != NULL){
    if(c->item != NULL){
      if(c->numItens == -1){
        free(c->item);
        free(c);
      return TRUE;
      }
      
    }
  }
return FALSE;
}

