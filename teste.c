#include "estruturas.h"
int main(){
    Lista *l;
    l=lst_cria();
    l=lst_insere(l,10);
    l=lst_insere(l,20);
    lst_imprime(l);
    
}