#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  Prototype Funtions */
void ler_aposta(int* aposta, int n);
void sorteia_valores(int *sorteio, int n);
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int *ns);

/*  Variáveis Globais */
int  apt,*ap,*sort,*qa,ns=20,acertos;

int main(void) {
    printf(" ==== Bem Vindo ao Bingo C ==== \n");
    printf("Digite quantos números deseja apostar (De 1 à 20): ");
    scanf("%d",&apt);
    ap=(int *)calloc(apt,sizeof(int));
    sort=(int *)calloc(ns,sizeof(int));
    ler_aposta(ap,apt);
    sorteia_valores(sort,ns);
    qa=compara_aposta(ap,sort,&acertos,apt,&ns);


    printf("Vetor Usuário:\n");
    for(int i=0;i<apt;i++){
        printf("Posicao %d: %d\n",i+1,*(ap+i));
    }
    printf("\nVetor Sorteio:\n");
     for(int i=0;i<ns;i++){
        printf("Posicao %d: %d\n",i+1,*(sort+i));
    }
    printf("O usuário acertou: %d números sorteados.",*qa);
     printf("\nNúmeros acertados:\n");
     for(int i=0;i<acertos;i++){
        printf("Acerto %d: %d\n",i+1,*(sort+i));
    }


return 0;
}

/*  Prototype Funtions */
void ler_aposta(int *aposta,int n) {
    for(int i=0;i<n;i++){
        do {
            printf("Digite a aposta número %d: ",i+1);
            scanf("%d",(aposta+i));
            }while((*(aposta+i)<0) || (*(aposta+i)>100));
    }
}
void sorteia_valores(int *sorteio, int n){
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++){
    *(sorteio+i)= (rand() % 100);
    }
}
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int *ns){
    int *act;
    for(int v=0;v<na;v++){
        for(int n=0;n<*ns;n++){
            if((aposta+v)==(sorteio+n)) {
                (*qtdacertos)++;
                }
        }
    }
    act=(int *)calloc(*qtdacertos,sizeof(int));
    for(int i=0;i<*qtdacertos;i++){
        for(int v=0;v<na;v++){
            for(int n=0;n<*ns;n++){
                if((aposta+v)==(sorteio+n)) {
                act[i]=*(aposta+v);
                }
            }
        }
    }
return act;
}

