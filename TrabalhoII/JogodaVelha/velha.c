/*  Bibliotecas Base */
#include <stdio.h>
#include <stdlib.h>
/*  Bibliotecas Específicas */
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <time.h>
/*  Bibliotecas do Jogo */
#include "structJV.h"
#include "velhalib.h"

/*  Variáveis Globais */
char jdv[3][3], *gg=&jdv[0][0],jg1=' ',jg2=' ';
int jogc=0,res=0;

/*  Programa Principal */
int main(){

//jogar_velha(gg,&jg1,&jg2,&res,&jogc);
jogar_velha(gg,&jg1,&jg2,&res,&jogc);
printf("\nO jogo será => usuário versus %s", (jogc==1?"computador":"usuário"));
printf("\nJogador 1: %c", jg1);
printf("\nJogador 2: %c", jg2);




printf("\n\n");
return 0;
}













