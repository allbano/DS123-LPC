#include <stdio.h>

void main() { 
	int count,soma,verificador;
    double media=0.0;
	count=soma=verificador=0;
    do {
	    printf("Digite um número para média ou um número negativo para sair: ");
        scanf("%d", &verificador);
	    printf("Verificador: %d\n",verificador);
        if(verificador>0){
            soma+=verificador;
            count++;
        }
        } while(verificador>0);

    if(count==0){
        printf("Não houveram entradas para fazer a média!\n");
        } else {
            media=((double)soma)/((double)count);
            printf("Quantidade de entradas: %d\n",count);
    	    printf("Média: %.2f\n",media);
            }
}
