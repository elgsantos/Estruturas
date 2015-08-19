#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{//struct lista é utilizada pelas estruturas
    int info;
    struct lista* prox;//é um ponteiro para o proximo elemento
};
typedef struct lista Lista;
//Listas
Lista * lst_cria(){//funcao de criacao da lista, apontando-a para null
    return NULL;
}
Lista * lst_insere(Lista *l,int info){//inclusao de elementos na lista
    Lista *p = malloc(sizeof(Lista));
    p->info=info;
    p->prox=l;//o proximo do nó inserido será a lista
    return p;//retorna a lista com o nó já incluído
}
void lst_imprime(Lista *l){//imprime os elementos da lista
    Lista *p;//lista auxiliar
    if(lst_vazia(l)){
        puts("lista vazia");
    }
    for(p=l;p!=NULL;p=p->prox)//enquanto p for diferente de null, imprimir a informacao
        printf("-->[%d]",p->info);
}
int lst_buscar(Lista *l, int chave){
    Lista *p;//é criada uma lista auxiliar pois a original foi passada por referencia
    for(p=l;p!=NULL;p=p->prox)
        if(chave==p->info) 
            return 1;//se encontrado retorna 1 e sai da função
    return 0;//se não encontrado retorna 0
}
int lst_vazia(Lista *l){//returna 1 se a lista estiver vazia
    if(l==NULL)
        return 1;
    return 0;
}
void lst_libera(Lista* l){//funcao para liberar a lista
    Lista* p = l;
    while (p!=NULL){
        Lista*t = p->prox;
        free(p);
        p=t;
    }
}
int lst_conta(Lista *l){//contar elementos da lista
    Lista *p;//é criada uma lista auxiliar pois a original foi passada por referencia
    int cont=0;
    if(lst_vazia(l)){//verifica se a lista esta vazia
        return 0;
    }
    for(p=l;p!=NULL;p=p->prox)
        {
            cont++;//contador é incrementado
        }
    return cont;
}

Lista* separa(Lista* l, int n){//função de separação da lista
    Lista *p=l;//p recebe lista l
    Lista *aux=NULL;
    while(p!=NULL&&p->info!=n){
        p=p->prox;//enquanto nao encontrado o 'n' passa de elemento na lista
    }
    if(p==NULL)
        return NULL;//se não achou retorna NULL
    aux=p;//chegando aqui ja foi encontrado e aux recebe a lista p
    p=p->prox;//p recebe seu proximo, ou seja sai do elemento encontrado
    aux->prox=NULL;//retira a referencia do proximo ao elemento encontrado, dizendo que a lista termina ali
    l=aux;//retorna a lista dividida ate o elemento para l
    return p;//retorna a subdivisao apos o elemento para a Lista na main
}
struct fila{//estrutura da fila
    Lista *ini;//guarda o primeiro elemento
    Lista *fim;//guarda o último elemento
};
typedef struct fila Fila;
Fila* fila_cria(void){//função de criação da fila
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini=f->fim=NULL;//ponteiros de inicio e fim recebem null
    return f;
}
int fila_vazia(Fila* f){//retorna 1 se a fila estiver vazia
    if(f->ini==NULL)
        return 1;
    return 0;
}
void fila_insere(Fila* f, int v){//inserção de elementos na fila
    Lista* n =(Lista*)malloc(sizeof(Lista));
    n->info=v; //info do nó recebe o valor passado
    n->prox=NULL; //novo nó passa a ser o último
    if(f->fim!=NULL) //verifica se a fila está vazia
        f->fim->prox=n; //se ela nao estiver vazia o proximo do ultimo recebe o novo nó
    else
        f->ini=n;//se estiver vazia o f->ini(ponteiro pro inicio) recebe o nó
    f->fim=n;//f->fim aponta para o nó inserido
}
int fila_retira (Fila* f){//retirada da fila
    Lista* t;
    int v;
    if(fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    }
    t=f->ini;
    v=t->info;//o valor contido no nó é passado para a variavel v
    f->ini=t->prox;//retira o elemento da fila
    if(f->ini==NULL)
        f->fim=NULL;
    free(t);//espaço do no retirado é liberado
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
void fila_imprime(Fila* f){//imprimir os elementos da fila
    Lista* q=f->ini;
    while(q!=NULL){
        printf("->[%d]",q->info);
        q=q->prox;
    }
    printf("\n");
}

//pilhas
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

typedef struct listaDupla{
    int info;
    struct listaDupla *prox;
    struct listaDupla *ant;
}listaDupla;

typedef struct circular{
    listaDupla* ini;
    listaDupla* aux;
    listaDupla* fim;
}Circ;

Circ* circ_cria(){                          //Inicializa círculo
    Circ *f=(Circ*)malloc(sizeof(Circ));
	f->aux = f->ini = f->fim = NULL;
	return f;
}
void circ_imprime(Circ *f){
    listaDupla *t;
    int n=1;
    for(t=f->ini;t!=f->fim;t=t->prox){
        printf("\tSoldado %d: %d\n",n,t->info);
        n++;
    }
    printf("\tSoldado %d: %d\n",n,t->info);
}
void circ_push(Circ *f,int x){
    listaDupla *n = (listaDupla*)malloc(sizeof(listaDupla)),*t;

    n->info = x;

    if(f->fim != NULL)
    	f->fim->prox = n;
    else
    	f->ini = n;
    t = f->fim;                         //variável do tipo listaDupla segura valor anterior ao fim
    f->fim = n;
    f->fim->ant = t;
    f->ini->ant = f->fim;               //anterior do início recebe o final da listaDupla
    f->aux = n->prox = f->ini;          //próximo valor após final da listaDupla recebe o inicio da listaDupla
}
int circ_vazia(Circ* f){
    if(f->fim==NULL)
        return 1;
    else
        return 0;
}
int circ_pop(Circ *f){
    listaDupla *t;
    int x;
    if (circ_vazia(f)){
    	printf("lista vazia.\n");
    	exit (1);
	}
	t = f->aux;
	x = t->info;
	//printf("\n %d\n",t->prox->info);
	t->ant->prox = f->aux = t->prox;      //Valor atual é tirado da listaDupla
	t->prox->ant = t->ant;

	if(f->fim==f->ini){                   //Se o último valor é retirado, então temos uma listaDupla vazia
		f->aux=NULL;
		f->fim=NULL;
		f->ini=NULL;
	}
	if(t==f->fim)                         //Se o valor atual retirado for igual ao fim ou início da listaDupla, então seu valor é
        f->fim = f->fim->ant;             //atualizado
    if(t==f->ini)
        f->ini = f->ini->prox;
	free(t);
	return x;
}

void circ_libera(Circ *f){
	listaDupla *q = f->ini;
	while(q!=f->fim){
		listaDupla *t=q->prox;
		free(q);
		q=t;
	}
	free(f->fim);
}

int mov_aux(Circ* f,int x){              //Move o auxiliar para a direita
    int i;
    for(i=0;i<x;i++)
        f->aux = f->aux->prox;
    return f->aux->info;
}
int mov_aux_rev(Circ* f,int x){          //Move o auxiliar para a esquerda
    int i;
    for(i=0;i<x;i++)
        f->aux = f->aux->ant;
    return f->aux->info;
}