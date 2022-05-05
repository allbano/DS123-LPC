#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Bibliotecas do Jogo */
#include "libvelha.h"
#include "libcampeonato.h"

/*  Escopo Global */
/*  Estruturas Globais */
jogs jg[2],*jd=&jg[0]; //Struct para gravar no TXT
velha v,*vf=&v; //Structs para gravar no arquivo binário Jogo da Velha
//char binario[]={"partidas.bin"},jogadores[]={"dados_jogadores.txt"};
char *binario,*jogadores;

/*  Variáveis Globais */
int jogc=0,res=0,np=0,fim=1,tam,tam2;

/*  Programa Principal */
int main(void){
 do {
    jogc=menu();
    switch(jogc){
        case 1:{
            res=jogar_velha(&(vf->jdv[0][0]),&((jd+0)->simb),&((jd+1)->simb),&res);
            system("clear");
            imprime_velha(&(vf->jdv[0][0]));
            if((res==88) || res==79){
                    printf("\nO ganhador é o símbolo: -> %c <-\n\n", res);
                } else {
                    printf("\nDeu empate: -> %c <-\n\n", res);
                }
            break;
            }
        case 2:{
            system("clear");
            printf("====== BEM VINDO AO CAMPEONATO DE JOGO DA VELHA ======\n\n\n");
            //Solicita o nome dos jogadores
            for(int i=0;i<2;i++)
                { inicializa_jogador((jd+i),i+1); }
            //Aqui é uma área de estrutura, onde é feita dinamicamente
            //O nome dos arquivos que seram gravados
            tam=tam_nome_jogadores(jd);//Calula o tamanho da string nome que é jg[posicao].jog
            jogadores=aloca_string((tam+3));//Aloca o espaço necessário para o nome do arquivo jogadores
            binario=aloca_string((tam+3));//Aloca o espaço necessário para o nome do arquivo binario
            strcat(strcpy(jogadores,jd->jog),(jd+1)->jog);
            strcat(strcpy(binario,jd->jog),(jd+1)->jog);
            strcat(jogadores,".txt");
            strcat(binario,".bin");
            printf("Arquivo Jogadores: %s\n\n",jogadores);
            printf("Arquivo Partidas: %s\n\n",binario);
            //Faz a escolha dos símbolos
            escolha_simb(&((jd+0)->simb),&((jd+1)->simb));
            do {
                vf->resultado=jogar_partida(vf,jd,&np);
                fim==grava_partida(binario,vf)?imprime_resultado_partida(vf,jd):exit(0);
                fim==grava_jogadores(jd,jogadores)?zera_partida(vf):exit(0);
                printf("Deseja jogar mais uma vez?\n Digite\t1)Sim\t2)Não\n=> ");
                scanf("%i",&fim);
                switch(fim){
                    case 1:{
                        ++np;
                        zera_partida(vf);
                        break;
                        }
                    case 2:{
                        fim=0;
                        zera_tudo(jd,vf);
                        break;
                        }
                    }

                }while(fim!=0);
                //Funçáo que irá imprimir o resultado final do jogo da velha!
            imprime_resultado_campeonato();
            free(binario);
            free(jogadores);
            break;
            }
        }
    }while(jogc==0);

return 0;
}
