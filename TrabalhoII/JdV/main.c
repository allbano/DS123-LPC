#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  Bibliotecas  Específicas do Jogo */
#include "libvelha.h"
#include "libcampeonato.h"

/*  Escopo Global */
/*  Estruturas Globais */
//Struct que armazena os jogadores e que será gravada no arquivo TXT
jogs jg[2],*jd=&jg[0];
//Struct que foi solicitada pelo trabalho está na libcampeonato.h
//e é a Struct que será usada para gravar no arquivo binário Jogo da Velha
velha v,*vf=&v;
//Ponteiros de String que serão dinamicamente alocados com os nomes dos
//arquivos que vão guardar os dados das partidas e o nome dos players
char *binario,*jogadores;

/*  Variáveis Globais */
int jogc=0,res=0,np=0,fim=1,tam;

/*  Programa Principal */
int main(void){
 do {
    jogc=menu();
    switch(jogc){
        //Primeira escolha do Menu, jogar uma partida de Jogo da Velha
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
        //Segunda escolha do Menu, jogar o campeonato de Jogo da Velha
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
            //Aqui serão feita as cópias para gerar o arquivo
            strcat(strcpy(jogadores,jd->jog),(jd+1)->jog);
            strcat(strcpy(binario,jd->jog),(jd+1)->jog);
            strcat(jogadores,".txt");
            strcat(binario,".bin");
            printf("\nArquivo Jogadores: %s",jogadores);
            printf("\nArquivo Partidas: %s\n",binario);
            //Faz a escolha dos símbolos
            escolha_simb(&((jd+0)->simb),&((jd+1)->simb));
            do {
                //JOga uma partida de jogo da velha e retorna o resultado
                vf->resultado=jogar_partida(vf,jd,&np);
                //Grava uma partida no arquivo binário, se tiver sucesso
                //imprime o resultado da partida, se não sai do programa!
                fim==grava_partida(binario,vf)?imprime_resultado_partida(vf,jd):exit(0);
                //Faz a gravação dos jogadores no arquivo txt
                fim==grava_jogadores(jd,jogadores)?zera_partida(vf):exit(0);
                //Pergunta se o jogador deseja jogar novamente até cansar!!!rs
                printf("Deseja jogar mais uma vez?\n Digite\t1)Sim\t2)Não\n=> ");
                scanf("%i",&fim);
                switch(fim){
                    //Caso 1 limpa os dados da partida e recomeça outra partida
                    case 1:{
                        ++np;
                        zera_partida(vf);
                        break;
                        }
                        //Caso 2 limpa tudo que está em memória e sai do laço
                    case 2:{
                        fim=0;
                        printf("Partidas jogadas -> %d <-\n\n", np+1);
                        zera_tudo(jd,vf);
                        break;
                        }
                    }

                }while(fim!=0);
            //Função Principal, onde imprime através dos dados dos arquivos
            // binario e txt os resultados obtidos pelos jogadores no campeonato
            imprime_resultado_campeonato(binario,jogadores,jd,v,&np);
            free(binario);
            free(jogadores);
            break;
            }
        }
    }while(jogc==0);

return 0;
}
