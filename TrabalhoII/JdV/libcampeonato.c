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
//Com retorno tipado
int grava_jogadores(jogs *jogadores,char *arquivo){
    FILE *dados;
    dados = fopen(arquivo,"w");
    char separador=';';
    if(dados == NULL){
        printf("Erro ao criar o arquivo com os dados dos jogadores!\n");
        return 0;
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
     fputc('\n',dados);
     fclose(dados);
return 1;
}
char jogar_partida(velha *pv,jogs *jds,int *np){
    char res=' ',jogador=' ',*velha=&(pv->jdv[0][0]);
    int contp=0,jogada,result=0,vef;
    pv->partida=*np;

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
                    case 86:{res='V'; break;}
                }
            }
      }while(res==' ');
return res;
}
int grava_partida(char *arquivo,velha *pv){
    FILE *jogo;
    jogo = fopen(arquivo,"ab");
    if(jogo == NULL){
        printf("Erro ao criar o arquivo com os dados da partida!\n");
        return 0;
        }
        fwrite(pv,sizeof(struct jogodavelha),1,jogo);

     fclose(jogo);
return 1;
}
int tam_nome_jogadores(jogs *x){
    int tam,k,i;
    for(k=0;k<2;k++){ //Mede o tamanho dos dois nomes para formar os arquivos jogadores e binario
        i=0;
        while((x+k)->jog[i]!='\0'){
             ++tam;
             i++;
        }
        //--tam; essa linha retira o '\0' do fim da contagem
    }
return tam;
}
/* Com retorno de tipo definidos pelo usuário */
velha ler_partida(char *arquivo,int num){
    FILE *jogo;
    velha p,*pp=&p;
    jogo = fopen(arquivo,"rb");
    if(jogo == NULL){
        printf("Erro ao ler o arquivo com os dados da partida!\n");
        exit(1);
        }
    fseek(jogo,num*sizeof(velha),SEEK_SET);
    fread(pp,sizeof(velha),1,jogo);
    fclose(jogo);
return p;
}
char* aloca_string(int tam) {
    char *str;
    if((str=malloc(tam*sizeof(char)))==NULL){
        printf("Erro na alocação dinâmica - abortando...");
        exit(0);
    }
return str;
}

//Sem retorno
void inicializa_jogador(jogs *jds, int jog) {
    printf("Digite o nome do jogador %d: ",jog);
    scanf("%s%*c",jds->jog);
    setbuf(stdin,NULL);
}
void zera_tudo(jogs *jogador,velha *pv){
    for(int j=0;j<2;j++){
        char *cc=&((jogador+j)->jog[0]);
        for(int l=0;l<15;l++){
            *(cc+l)=' ';
            }
        *(&(jogador+j)->simb)=' ';
    }
    pv->partida=0;
    for (int l=0;l<9;l++){
        *((&(pv->jdv[0][0]))+l)=' ';
    }
    pv->resultado=' ';
}
void le_jogadores(jogs *jg,char *jds){
    FILE *dados;
    dados = fopen(jds,"r");
    int i=0;
    char x[40];
    if(dados == NULL){
        printf("Erro ao ler o arquivo com os dados dos jogadores!\n");
        exit(1);
        }
    fgets(x,40,dados);
    fclose(dados);
    //Separação da string com ; nos campos da Struct jogadores
    for(int j=0;j<4;j++){
        switch (j) {
            case 0: {
                while (x[i] != ';') {
                //*((&((jg+0)->jog[0]))+i)=x[i];
                *((jg->jog)+i)=x[i];
                i++;
                }
                //*((&((jg+0)->jog[0]))+i)='\0';
                *((jg->jog)+i)='\0';
                ++i;
                break;
            }
            case 1: {
                while (x[i] != ';') {
                jg->simb=x[i];
                ++i;
                }
                ++i;
                break;
            }
            case 2: {
                int t=0;
                while (x[i] != ';') {
                //Formas de chegar no valor de um ponteiro de ponteiros
                //*((&((jg+1)->jog[0]))+t)=x[i];
                *(((jg+1)->jog)+t)=x[i];
                ++i;
                ++t;
                }
                *(((jg+1)->jog)+t)='\0';
                ++i;
                break;
            }
            case 3:{
                //*(&((jg+1)->simb))=x[i];
                *(&(jg+1)->simb)=x[i];
                break;
            }
        }
    }
}
void zera_partida(velha *pv){
    pv->partida=0;
    for (int l=0;l<9;l++){
        *((&(pv->jdv[0][0]))+l)=' ';
    }
    pv->resultado=' ';
}
void imprime_resultado_partida(velha *vf, jogs *jd){
    printf("\tRESULTADO DA PARTIDA\n\t\t-> %i <-\n\n",vf->partida+1);
    imprime_velha(&(vf->jdv[0][0]));
    printf("\n\n\tJogador 1 -> %s(%c) <-\n\t\t   VERSUS\n",jd->jog,jd->simb);
    printf("\tJogador 2 -> %s(%c) <-\n\n",(jd+1)->jog,(jd+1)->simb);


            if(vf->resultado=='V'){
                    printf("\nDeu Velha: -> %c <-\n\n", vf->resultado);
                }
            if(vf->resultado==jd->simb){
                printf("\nO ganhador da partida %d foi: -> %s(%c) <-\n\n",vf->partida+1,jd->jog,vf->resultado);
            }
            if(vf->resultado==(jd+1)->simb) {
                printf("\nO ganhador da partida %d foi: -> %s(%c) <-\n\n",vf->partida+1,(jd+1)->jog,vf->resultado);
                }
}
void imprime_resultado_campeonato(char *bin,char *players,jogs *jd,velha vf,int *np) {
    //Variáveis
    int contO=0,contX=0,contV=0,p=0;
    velha *v=&vf;
    FILE *f;
    f=fopen(bin,"r");
    if(f == NULL){
        printf("Erro ao ler o arquivo com os dados da partida!\n");
        system("pause");
        exit(1);
        }
    //while

    le_jogadores(jd,players);
    for(int i=0;i<(*np+1);i++){
        vf=ler_partida(bin,i);

        switch(v->resultado){
            case 'X':{++contX; break;}
            case 'O':{++contO; break;}
        }
        imprime_resultado_partida(v,jd);
    }
    if(contX==contO){
        printf("\n ===NÁO HOUVE GANHADORES, DEU EMPATE TÉCNICO === #triste");
            if((jd->simb=='X') ) {
                printf("\n\n\tJogador 1 -> %s(%c) (%i) <-\n\t\t   VERSUS\n",jd->jog,jd->simb,contX);
                printf("\tJogador 2 -> %s(%c) (%i) <-\n\n",(jd+1)->jog,(jd+1)->simb,contO);
                } else {
                    printf("\n\n\tJogador 1 -> %s(%c) (%i) <-\n\t\t   VERSUS\n",jd->jog,jd->simb,contO);
                    printf("\tJogador 2 -> %s(%c) (%i) <-\n\n",(jd+1)->jog,(jd+1)->simb,contX);
                }
        fclose(f);
        exit(0);
    }
    if((jd->simb=='X') ) {
        printf("\t=== PLACAR FINAL ===");
        printf("\n\n\tJogador 1 -> %s(%c) (%i) <-\n\t\t   VERSUS\n",jd->jog,jd->simb,contX);
        printf("\tJogador 2 -> %s(%c) (%i) <-\n\n",(jd+1)->jog,(jd+1)->simb,contO);
        printf("\n\n%s foi o(a) grande campeã(o) do Campeonato de Jogo da Velha!!!\n\n",jd->jog);
    } else {
        printf("\t\t=== PLACAR FINAL ===");
        printf("\n\n\tJogador 1 -> %s(%c) (%i) <-\n\t\t   VERSUS\n",jd->jog,jd->simb,contO);
        printf("\tJogador 2 -> %s(%c) (%i) <-\n\n",(jd+1)->jog,(jd+1)->simb,contX);
        printf("\n\n%s foi o(a) grande campeã(o) do Campeonato de Jogo da Velha!!!\n\n",(jd+1)->jog);
    }
    fclose(f);

}






















