/*
**************************************
* Analise de expressão aritmetica 
(o programa por enquanto so funciona com o uso de parenteses nas 
expressoes e só funciona com numeros 0-9, ex: (3*(8+5))
pode-se ver que eu não inclui nenhum maior que 9, pois no primeiro 
momento a pilha so consegue um digito por vez.)
***************************************
*/
#include "pilha.h"
int main(){
    char op;
    char valor[30];
    Pilha* p1;
    Pilha* p2;
    p1=pilha_cria();
    p2=pilha_cria();
    printf("\nOla, meu nome eh Fulano1,");
    do{
        printf("\nEntre com a expressao para que eu resolva: ");
        scanf(" %[^\n]s",valor);
        int i;
        int length = strlen(valor);
        for(i=0;i<length;i++){
            if(isdigit(valor[i])){//verifica se e numero
                int v=val(valor[i]);
                pilha_push(p1,v);
            } else if(valor[i]=='('){
            }
            else if(valor[i]==')'){//ao encontrar ) calcula
                calcula(p1,p2);
            }else{
                pilha_push(p2,valor[i]);//acrescenta o operador a pilha
            }
        }
        int result=pilha_pop(p1);
        printf("\nObrigado, o resultado da sua expressão é: %d",result);
        do{
            printf("\nDeseja continuar (s/n)?:");
            scanf(" %c",&op);
        }while(op!='s'&&op!='n');
    }while(op=='s');
    printf("\nFim !!!\n");
    pilha_libera(p1);
    pilha_libera(p2);
    return 0;
}