#include <stdio.h>
#include <stdlib.h>
/*  Bibliotecas do Jogo */
#include "libvelha.h"
#include "libcampeonato.h"

/*  Estruturas Globais */
/* Estruturas Globais */
typedef struct jogador {
    char jog[15],simb;
} jogs;
typedef struct {
    int partida;
    char jdv[3][3];
    char resultado;
} velha;


/*  Variáveis Globais */
//char jdv[3][3], *gg=&jdv[0][0],jg1=' ',jg2=' ';
char jdv2[3][3], *gg=&jdv2[0][0];
jogs jg1,jg2;
jogs *jd1=&jg1,*jd2=&jg2;


velha v,*vf=&v;
int jogc=0,res=0;

/*  Programa Principal */
int main(){

//jogar_velha(gg,&jg1,&jg2,&res,&jogc);
//res=jogar_velha(gg,&jg1,&jg2,&res,&jogc);
res=jogar_velha(&(vf->jdv[0][0]),&(jd1->simb),&(jd2->simb),&res,&jogc);
system("clear");
imprime_velha(gg);
if((res==88) || res==79){
        printf("\nO ganhodor é o símbolo: -> %c <-\n\n", res);
    } else {
        printf("\nDeu empate: -> %c <-\n\n", res);
    }
return 0;
}
