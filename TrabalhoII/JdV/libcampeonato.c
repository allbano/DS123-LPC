/*  Bibliotecas Base */
#include <stdio.h>
#include <stdlib.h>
/*  Bibliotecas Específicas */
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "libvelha.h"
#include "libcampeonato.h"


/*  Funtions */
//Com retorno
int grava_jogadores(jogs *jogadores,FILE *dados){
    dados = fopen("dados_jogadores.txt","w");
    char separador=';';
    if(dados == NULL){
        printf("Erro ao criar o arquivo com os dados dos jogadores!\n");
        return 1;
        }
     for(int a=0;a<2;a++){
            for(int n=0;n<strlen((jogadores+a)->jog);n++){
                    fputc(*(&(jogadores+a)->jog[n]),dados);
            }
            fputc(separador,dados);
            fputc(*(&(jogadores+a)->simb),dados);
            if(a==0){
                fputc(separador,dados);
            }

     }
     fclose(dados);
return 0;
}
char jogar_partida(velha *pv,jogs *jds){
    char res=' ',jogador=' ',*velha=&(pv->jdv[0][0]);
    int contp=0,jogada,result=0,vef;
    inicializa_velha(&(pv->jdv[0][0]));
    do{
        //system("clear");
            imprime_velha(velha);
            jogador=(contp%2==0?jds->simb:(jds+1)->simb);
            if(jogador=='X'){
                jogada = entradaInteiros(8);
                } else {
                    jogada = entradaInteiros(9);
                    }
            setbuf(stdin,NULL);
            --jogada;
            vef=jogada_usuario(&jogada,&jogador,velha);
            if(vef==0){
                *(velha+jogada)=jogador;
                contp++;
            }
            if(vef==1) {
                    printf("\nPosição inválida!\n\n");
                    continue;
            }
            if(vef==2){
                    printf("\nPosição já preenchida, repetir jogada!\n\n");
                    continue;
            }
            printf("\n");
            if(contp>=5){
                result=verifica_ganhador(&jogador,velha);
            }
            if((result==88) || (result==79) || (result==86)) {
                switch(result){
                    case 88:{res='X'; break;}
                    case 79:{res='O'; break;}
                    case 86:{res='X'; break;}
                }
            }
      }while(res==' ');
return res;
}

//Sem retorno
void inicializa_jogador(jogs *jds, int jog) {
    printf("Digite o nome do jogador %d: ",jog);
    scanf("%s%*c",jds->jog);
    setbuf(stdin,NULL);
}