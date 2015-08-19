#include <locale.h>
#include <time.h>
#include "estruturas.h"

#define cap 10

void insere_soldados(Circ* f);
int sorteio_chapeu();
void retira_soldado(Circ* f, int s);
void display(Circ* f){                                //Função para mostrar a parte visual do programa
    if(f->aux->prox!=f->aux)                          //Se houver mais de um soldado imprime os restantes, do contrário apenas
        circ_imprime(f);                              //o vencedor
    else
        printf("\n\tVencedor: %d\n\n",circ_pop(f));
    printf("\n");
}
int main(){
    int soldado, sorteado;
    Circ *f;

    system("COLOR F0");                               //Deixa o fundo branco
	setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    f = circ_cria();                                  //Cria lista circular
    insere_soldados(f);                               //Insere 10 soldados, cada um com identificador único
    soldado = mov_aux(f, rand() % 11);                //É selecionado o primeiro soldado aleatoriamente

    display(f);
    printf("\n Soldado Selecionado: %d\n\n",soldado);
    system("cls");                                    //Limpa a tela para uma melhor experiência
    do{
        display(f);

        sorteado = sorteio_chapeu();
        retira_soldado(f,sorteado);

        system("cls");
    }while(f->aux->prox!=f->aux);                    //Enquanto não restar apenas um soldado, continuará retirando

    display(f);
    circ_libera(f);
    return 0;
}
void insere_soldados(Circ* f){
    int i,n;

    circ_push(f,(rand()%4)+1);                       //Inicia a lista de soldados com um id de 1 a 4
    for(i=1;i<cap;i++){
        do{
            n = rand()%(10+i*2);                     //Para que cada soldado tenha uma id aleatória sem repetição em
        }while(f->aux->ant->info >= n);              //ordem crescente, é gerado sempre um número maior que o anterior
        circ_push(f,n);
    }
}
int sorteio_chapeu(){
    int s;
    do{
        s = (rand()%19)-9;                           //É gerado um número aleatório de 0~18, e subtraído por 9, para assim
    }while(s==0);                                    //termos -9~9 e diferente de 0
    printf(" Número Sorteado: %d\n",s);
    return s;
}
void retira_soldado(Circ* f, int s){
    if(s>0)                                          //número positivo anda para direita
        mov_aux(f,s);
    else{                                            //negativo para a esquerda
        s *=(-1);
        mov_aux_rev(f,s);
    }
    printf("\n Soldado Retirado: %d\n\n",circ_pop(f));
}