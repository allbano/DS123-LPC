#ifndef CAMPEONATO_H_INCLUDED
#define CAMPEONATO_H_INCLUDED
/* Estruturas Globais */
typedef struct jogador {
    char jog[15],simb;
} jogs;
typedef struct {
    int partida;
    char jdv[3][3];
    char resultado;
} velha;
/*  Prototype Funtions */
// Com retorno
char jogar_partida(velha *pv,jogs *jds);
int grava_jogadores(jogs *jogadores,FILE *dados);


// Sem retorno
void inicializa_jogador(jogs *jds, int jog);

#endif // CAMPEONATO_H_INCLUDED