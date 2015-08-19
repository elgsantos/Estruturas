#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista {
    int info;
    struct lista * prox;
};
typedef struct lista Lista;

struct pilha{
    Lista* prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria(void)
{
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}

void pilha_push(Pilha* p, int v)
{   
    Lista* n = (Lista*)malloc(sizeof(Lista));
    n->info=v;
    n->prox=p->prim;
    p->prim=n;
}

int pilha_vazia(Pilha* p){
    if(p->prim!=NULL)
        return 0;
    else
        return 1;
}

int pilha_pop(Pilha* p){
    Lista* t;
    int v;
    if(pilha_vazia(p)){
        printf("Pilha vazia. \n");
        exit(1);
    }
    t=p->prim;
    v=t->info;
    p->prim=t->prox;
    free(t);
    return v;
}
void pilha_libera(Pilha *p){
    Lista* q=p->prim;
    while(q!=NULL){
        Lista* t=q->prox;
        free(q);
        q=t;
    }
    free(p);
}
void calcula(Pilha* p1, Pilha* p2){
    int e1,e2;char simb;
    int r;
    e1=(int)pilha_pop(p1);
    e2=(int)pilha_pop(p1);
    simb=pilha_pop(p2);
    if(simb=='+'){//compara os simbolos para fazer as operacoes
        r=e2+e1;
    }else if(simb=='-'){
        r=e2-e1;
    }else if(simb=='*'){
        r=e2*e1;
    }else if(simb=='/'){
        r=e2/e1;
    }
    pilha_push(p1,r);
}
int val(char c){//converte de caracter para inteiro
    if(c=='1')return 1;
    else if(c=='2')return 2;
    else if(c=='3')return 3;
    else if(c=='4')return 4;
    else if(c=='5')return 5;
    else if(c=='6')return 6;
    else if(c=='7')return 7;
    else if(c=='8')return 8;
    else if(c=='9')return 9;
    else return 0;
}