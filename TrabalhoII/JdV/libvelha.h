#ifndef LIBVELHA_H_INCLUDED
#define LIBVELHA_H_INCLUDED

/*  Prototype Funtions */
// Com retorno

int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc);
int verifica_ganhador(char *jog,char *velha);
int jogada_usuario(int *pos,char *jogador,char *velha);
int entradaInteiros();
int menu();


// Sem retorno
void imprime_velha(char *posix);
void inicializa_velha(char *velha);
void jogada_computador(char jog,int nivel);
void escolha_simb(char *jog1, char *jog2);
void mensagensJV(int num);


#endif // LIBVELHA_H_INCLUDED
