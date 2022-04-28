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

jogs jg[2],*jd=&jg[0]; //Structs usada no Trabalho II


velha v,*vf=&v;
int jogc=0,res=0;

/*  Programa Principal */
int main(){

do {
    jogc=menu();
    switch(jogc){
        case 1:
            res=jogar_velha(&(vf->jdv[0][0]),&((jd+0)->simb),&((jd+1)->simb),&res);
            system("clear");
            imprime_velha(&(vf->jdv[0][0]));
            if((res==88) || res==79){
                    printf("\nO ganhodor é o símbolo: -> %c <-\n\n", res);
                } else {
                    printf("\nDeu empate: -> %c <-\n\n", res);
                }
            break;

    }
}while(jogc==0);
//res=jogar_velha(gg,&jg1,&jg2,&res,&jogc);


return 0;
}
