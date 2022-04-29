#include <stdio.h>
#include <stdlib.h>
/*  Bibliotecas do Jogo */
#include "libvelha.h"
#include "libcampeonato.h"

/*  Escopo Global */
/*  Estruturas Globais */
jogs jg[2],*jd=&jg[0]; //Struct para gravar no TXT
velha v,*vf=&v; //Structs para gravar no arquivo binário Jogo da Velha
/*  Variáveis Globais */
int jogc=0,res=0,countp=0;
FILE *jogos,*js;

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
                    printf("\nO ganhador é o símbolo: -> %c <-\n\n", res);
                } else {
                    printf("\nDeu empate: -> %c <-\n\n", res);
                }
            break;
        case 2:
            for(int i=0;i<2;i++)
                { inicializa_jogador((jd+i),i+1); }
            escolha_simb(&((jd+0)->simb),&((jd+1)->simb));
            vf->resultado=jogar_partida(vf,jd);
            printf("Jogador 1: %s(%c)\n",jd->jog,jd->simb);
            printf("Jogador 2: %s(%c)\n",(jd+1)->jog,(jd+1)->simb);
            grava_jogadores(jd,js);
            if(vf->resultado=='V'){
                    printf("\nDeu empate: -> %c <-\n\n", res);
                }
            if(vf->resultado==jd->simb){
                printf("\nO ganhador foi: -> %s(%c) <-\n\n",jd->jog,vf->resultado);
            }
            if(vf->resultado==(jd+1)->simb) {
                printf("\nO ganhador foi: -> %s(%c) <-\n\n",(jd+1)->jog,vf->resultado);
                }

            break;
    }
    }while(jogc==0);
return 0;
}
