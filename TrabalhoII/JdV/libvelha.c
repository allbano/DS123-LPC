/*  Bibliotecas Base */
#include <stdio.h>
#include <stdlib.h>
/*  Bibliotecas Específicas */
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include "libvelha.h"

/*  Funtions */
//Com retorno
int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc){
    int jogada,vec,cont=0,ganhador=0;
    char jogador=' ';
    *jogc=menu();
    escolha_simb(jog1,jog2);
    inicializa_velha(velha);
    do{
        //system("clear");
            imprime_velha(velha);
            jogador=(cont%2==0?*jog1:*jog2);
            if(jogador=='X'){
                jogada = entradaInteiros(8);
                } else {
                    jogada = entradaInteiros(9);
                    }
            fflush(stdin);
            --jogada;
            vec=jogada_usuario(&jogada,&jogador,velha);
            if(vec==0){
                *(velha+jogada)=jogador;
                cont++;
                ++ganhador;
            }
            if(vec==1) {
                    printf("\nPosição inválida!\n\n");
                    continue;
            }
            if(vec==2){
                    printf("\nPosição já preenchida, repetir jogada!\n\n");
                    continue;
            }
            printf("\n");
            if(ganhador>=5){
                *rest=verifica_ganhador(&jogador,velha);
            }
      }while(*rest==0);
      return *rest;
}
int verifica_ganhador(char *jog,char *velha) {
        int res=0;
        if(*jog=='X'){
            res=88;
        } else {
            res=79;
            }
        //Verifica as linhas
        if(((*(velha+0)==*jog) &&(*(velha+1)==*jog) && (*(velha+2)==*jog)) ||
            ((*(velha+3)==*jog) &&(*(velha+4)==*jog) && (*(velha+5)==*jog))||
            ((*(velha+6)==*jog) &&(*(velha+7)==*jog) && (*(velha+8)==*jog)))
            { return res; }

        //Verifica as colunas
        if(((*(velha+0)==*jog) &&(*(velha+3)==*jog) && (*(velha+6)==*jog)) ||
          ((*(velha+1)==*jog) &&(*(velha+4)==*jog) && (*(velha+7)==*jog))  ||
          ((*(velha+2)==*jog) &&(*(velha+5)==*jog) && (*(velha+8)==*jog)))
            { return res; }

        //Verifica as diagonais
        if((*(velha+0)==*jog) &&(*(velha+4)==*jog) && (*(velha+8)==*jog)
           ||(*(velha+2)==*jog) &&(*(velha+4)==*jog) && (*(velha+6)==*jog))
           { return res;}
        //Verifica o empate
        if((*(velha+0)!=' ') && (*(velha+1)!=' ') && (*(velha+2)!=' ') &&
           (*(velha+3)!=' ') && (*(velha+4)!=' ') && (*(velha+5)!=' ') &&
           (*(velha+6)!=' ') && (*(velha+7)!=' ') && (*(velha+8)!=' '))
                { return 86; }

return 0;
}
int jogada_usuario(int *pos,char *jogador,char *velha){
    switch(*pos){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8: {
            if(*(velha+*pos)==' '){
                return 0;
            }
            if( *(velha+*pos)!=' '){
                return 2;
            }
            break;
        }
        default: {
            return 1;
        }
    }
}
int entradaInteiros(int num){
    int res,retorno=-1;
    char letra;
    do{
        mensagensJV(num);
        retorno = scanf("%d",&res);
        do{
            letra=getchar();
        }while(letra !='\n');
    }while(retorno==0);
    return res;
}

int menu(){
    int escolha,erro=1;
    do {
        for (int i=0;i<4;i++){
            mensagensJV(i);
        }
        escolha = entradaInteiros(4);

        //printf("O valor da escolha é: %d", escolha);
        switch(escolha){
            case 0:{
                exit(0);
                break; }
            case 1:  {
                erro=0;
                break; }
            case 2:  {
                erro=0;
                break; }
            case 3:  {
                erro=0;
                break; }
            default:
                mensagensJV(5);
        }
    }while(erro==1);
return escolha;
}
//Sem retorno
void inicializa_velha(char *velha) {
        int l;
        for (l=0;l<9;l++){
                *(velha+l)=' ';

        }
}
void escolha_simb(char *jog1, char *jog2) {
        char escolha;
        int valor=0;
        do{
            mensagensJV(6);
            scanf("%c%*c", &escolha);
            escolha = toupper(escolha);
            switch(escolha){
            case 'X':{
                *jog1=escolha;
                *jog2='O';
                valor=1;
                break;
                }
            case 'O':{
                *jog1=escolha;
                *jog2='X';
                valor=1;
                break;
                }
            default:
                mensagensJV(7);
            }
          }while(valor==0);
}
void imprime_velha(char *posix){
    int l;
    printf("\t==== JOGO DA VELHA ====\n\n");
    printf("\t   ");
    for (l=0;l<3;l++){
            // Imprime a primera linha
            printf("  %c  ", *(posix+l));
            l<=1 ?printf("|"):printf(" ");
            }
    printf("\n\t   -----------------");
    printf("\n\t   ");
    for (l;l<6;l++){
            // Imprime a primera linha
            printf("  %c  ", *(posix+l));
            l<=4 ?printf("|"):printf(" ");
            }
    printf("\n\t   -----------------");
    printf("\n\t   ");
    for (l;l<9;l++){
            // Imprime a primera linha
            printf("  %c  ", *(posix+l));
            l<=7 ?printf("|"):printf(" ");
            }
    printf("\n");
}
void mensagensJV(int num){
    char mens[][200] = {
                    "\n====== MENU JOGO DA VELHA ======\n\n\n",//0
                    "(1) Jogar Jogo da Velha.\n",//1
                    "(2) Campeonato de Jogo da Velha.\n",//2
                    "(0) Se quiser sair.\n",//3
                    "\nEscolha uma das opções do Menu: ",//4
                    "\nDigite uma opção válida!!!\n",//5
                    "\nDigite qual caracter/símbolo o jogador '1' usará - 'X' ou 'O': ", //6
                    "Opção inválida! Favor digitar corretamente a opção 'X' ou 'O'!\n (maiúsculo ou minúsculo!)\n", //7
                    "\n Jogador X, digite uma posição de jogada de 1 à 9: ", //8
                    "\n Jogador O, digite uma posição de jogada de 1 à 9: " //9
                    };
    printf(mens[num]);
}
