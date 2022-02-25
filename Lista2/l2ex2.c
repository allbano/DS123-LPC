#include <stdio.h>

void main() { 
	int count,jogos,jogganhos,jogperdidos,jogempatados,golsm,golss,gols,somas,somam;
	double medias,mediam;
	char c;
	count=jogos=jogganhos=jogperdidos=jogempatados=golsm=golss=gols=somas=somam=0;
	printf("Digite a quantidade de jogos que foram realizados pela sua equipe: ");
	scanf("%d", &jogos);
	while(count<jogos) {
		count++;
		printf("Digite a quantidade de gols sofridos do jogo %d: ", count);
		scanf("%d", &golss);
		somas+=golss;
		printf("Digite a quantidade de gols marcados do jogo %d: ", count);
		scanf("%d", &golsm);
		somam+=golsm;
		if(golsm<golss) {
			jogganhos++;}
		if(golsm>golss) {
			jogperdidos++;}
		if(golsm==golss) {
			jogempatados++;}
		golss=0;
		golsm=0;
	}
	medias=((double)somas)/((double)jogos);
	mediam=((double)somam)/((double)jogos);


	printf("Valor de golss: %d\n",somas);
	printf("Valor de golsm: %d\n",somam);

	printf("Jogos ganhos: %d\n",jogganhos);
	printf("Jogos perdidos: %d\n",jogperdidos);
	printf("Jogos empatados: %d\n",jogempatados);
	printf("Média de Gols sofridos: %.2f\n", medias);
	printf("Média de Gols marcados: %.2f\n", mediam);
}
