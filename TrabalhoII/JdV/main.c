#include <stdio.h>
/*  Bibliotecas do Jogo */
#include "libvelha.h"

/*  Variáveis Globais */
char jdv[3][3], *gg=&jdv[0][0],jg1=' ',jg2=' ';
int jogc=0,res=0;

/*  Programa Principal */
int main(){

//jogar_velha(gg,&jg1,&jg2,&res,&jogc);
res=jogar_velha(gg,&jg1,&jg2,&res,&jogc);
imprime_velha(gg);
printf("\nO ganhodor é o símbolo: -> %c <-\n\n", res);
return 0;
}
