#include "fila_por_lista.h"
int main(){
    Fila *f1;
    float elemento;
    f1=fila_cria();
    fila_insere(f1, 10);
    fila_insere(f1, 20);
    fila_insere(f1, 50);
    fila_insere(f1, 100);
    fila_insere(f1, 500);
    fila_imprime(f1);
    elemento=fila_retira(f1);
    fila_imprime(f1);
    return 0;
}