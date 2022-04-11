/*  Bibliotecas Base */
#include <stdio.h>
#include <stdlib.h>

/*  Bibliotecas Específicas */
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <time.h>

/*  Bibliotecas do Jogo */
#include "velhalib.h"


/*  Constantes */

/*  Variáveis Globais */
char jdv[3][3], *gg=&jdv[0][0],jg1=' ',jg2=' ';
int jogc=0;



/*  Prototype de funções */
// Com retorno
int menu();
int jogada_usuario(int lin,int col,char jog);
int verifica_ganhador(char jog);
// Sem retorno
void jogada_computador(char jog,int nivel);
void escolha_simb(char *jog1, char *jog2); //Feita
void inicializa_velha(char *jogv); //Feita



int main(){

jogc=menu();
inicializa_velha(gg);
escolha_simb(&jg1,&jg2);

printf("\nJogando contra: %d", jogc);
printf("\nJogador 1: %c", jg1);
printf("\nJogador 2: %c", jg2);


return 0;
}



/*
int l;
for (l=0;l<9;l++){
            printf("%c  \n", *(gg+l));
            }
 printf("\nVerificação...\n");

*(gg+3)='9';

for (l=0;l<9;l++){
            printf("%c  \n", *(gg+l));
            }

escolha_simb(&jg1,&jg2);
printf("\nJogador 1: %c", jg1);
printf("\nJogador 2: %c", jg2);



*/











