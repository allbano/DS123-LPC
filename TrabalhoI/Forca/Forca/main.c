#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>




void forca (int tentativa){
if(tentativa==0){
printf("-----------------");
printf("\n| |");
printf("\n|");
printf("\n|");
printf("\n|");
printf("\n|");
printf("\n|");
printf("\n__");
}
else if(tentativa==1){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n|");
printf("\n|");
printf("\n|");
printf("\n|");
printf("\n__");
}
else if(tentativa==2){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n| |");
printf("\n| |");
printf("\n|");
printf("\n|");
printf("\n__");
}
else if(tentativa==3){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n| -|");
printf("\n| |");
printf("\n|");
printf("\n|");
printf("\n__");
}
else if(tentativa==4){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n| -|-");
printf("\n| |");
printf("\n|");
printf("\n|");
printf("\n__");
}
else if(tentativa==5){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n| -|-");
printf("\n| |");
printf("\n| /");
printf("\n|");
printf("\n__");
}
else if(tentativa==6){
printf("-----------------");
printf("\n| |");
printf("\n| 0");
printf("\n| -|-");
printf("\n| |");
printf("\n| / \\");
printf("\n|");
printf("\n__ Você perdeu! :(");
}
}



int main (void){
char banco[10][10]= {"cachorro", "morango", "bicicleta", "curitiba", "computador", "cereal", "televisao", "faculdade", "trabalho", "girafa"};
int i;
int num=0;
char palavra[10];
char tela[10];


srand(time(NULL)); //biblioteca time.h
num = rand() % 10; //escolhe palavra aleatoria
for(i=0; i<10;i++){
palavra[i]=banco[num][i];
}
strcpy(tela, palavra); //grava o conteudo da char palavra em char tela




for (int i=0; i<strlen(tela);i++){ // transforma a palavra secreta da tela em _
tela[i]=('_'); //ESPACO
}
// printf("A palavra é %s \n", tela);
// scanf("%c", &palavra);




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
}

if(erros==6){
forca(erros);
break;
}
}
return 0;
}
