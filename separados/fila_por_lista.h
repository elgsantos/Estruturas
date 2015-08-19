#include <stdio.h>
#include <stdlib.h>
struct lista{
    float info;
    struct lista* prox;
};
typedef struct lista Lista;
struct fila{
    Lista *ini;
    Lista *fim;
};
typedef struct fila Fila;
Fila* fila_cria(void){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini=f->fim=NULL;
    return f;
}
int fila_vazia(Fila* f){
    if(f->ini==NULL)
        return 1;
    return 0;
}
void fila_insere(Fila* f, float v){
    Lista* n =(Lista*)malloc(sizeof(Lista));
    n->info=v;
    n->prox=NULL; //novo nó passa a ser o último
    if(f->fim!=NULL) //verifica se a fila está vazia
        f->fim->prox=n; //se ela nao estiver vazia o proximo do ultimo recebe o novo nó
    else
        f->ini=n;//se estiver vazia o f->ini(ponteiro pro inicio) recebe o nó
    f->fim=n;//f->fim aponta para o nó inserido
}
float fila_retira (Fila* f){
    Lista* t;
    float v;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    t=f->ini;
    v=t->info;
    f->ini=t->prox;
    if(f->ini==NULL)
        f->fim=NULL;
    free(t);
    return v;
}
void fila_libera(Fila* f){
    Lista* q=f->ini;
    while(q!=NULL){
        Lista* t = q->prox; //segura o que e atribui o proximo a 't'
        free(q);//libera q
        q=t;//q recebe o t
    }
    free(f);
}
void fila_imprime(Fila* f){
    Lista* q=f->ini;
    while(q!=NULL){
        printf("->[%.2f]",q->info);
        q=q->prox;
    }
    printf("\n");
}