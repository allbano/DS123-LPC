//Bibliotecas padrão da Linguagem C
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Bibliotecas específicas
#include <time.h>
#include <string.h>
//Biblioteca do Jogo
#include "forcalib.h"

//Prototype das funções utilizadas
void forca (int tentativa);
void escolhePalavra(int *num) ;


//Variáveis Globais
char banco[10][10]= {"cachorro", "morango", "bicicleta", "curitiba", "computador", "cereal", "televisao", "faculdade", "trabalho", "girafa"};
int num=0;

int main (void) {

        int i;
        char palavra[10];
        char tela[10];


        escolhePalavra(&num);
        strcpy(palavra,banco[num]);
        strcpy(tela, banco[num]);


        for (int i=0; i<strlen(tela);i++){ // transforma a palavra secreta da tela em _
            tela[i]=('_'); //ESPACO
        }



        int erros = 0;
        while(1){
                forca(erros);
                printf("\n Adivinhe a palavra: ");
                for(int i=0;i<strlen(tela);i++){
                printf("%c ",tela[i]);
                }


                printf("\nLetra: ");
                char letra;
                scanf(" %c", &letra);

                int letra_errada=1;
                for(int i=0;i<strlen(palavra); i++){
                    if(letra==palavra[i]){
                        tela[i]=letra;
                        letra_errada=0;
                    }
                }
                if(letra_errada==1){
                erros++;
                }

                if(strcmp(tela,palavra)==0){
                printf("Você venceu! :)");
                break;
                }

                if(erros==6){
                forca(erros);
                break;
                }
        }
        return 0;
}
