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
char jogar_partida(velha *pv,jogs *jds,int *np);
int grava_jogadores(jogs *jogadores,char *jds);
int grava_partida(char *arquivo,velha *pv);
int tam_nome_jogadores(jogs *x);
/* Função específica que tem como retorno a struct velha */
velha ler_partida(char *arquivo,int num);
char* aloca_string(int tam);

// Sem retorno
void zera_tudo(jogs *jogador,velha *pv);
void inicializa_jogador(jogs *jds, int jog);
void le_jogadores(jogs *jg,char *jds);
void zera_partida(velha* pv);
void imprime_resultado_partida(velha *pv, jogs *jds);
void imprime_resultado_campeonato();

#endif // CAMPEONATO_H_INCLUDED
