/*  Prototype Funtions */
// Com retorno


int jogada_usuario(int *pos,char *jogador,char *velha);//fazendo
int verifica_ganhador(char *jog, int *rest);
int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc);//fazendo

// Sem retorno
void imprime_velha(char *posix);
void inicializa_velha(char *velha);
void jogada_computador(char jog,int nivel);
void escolha_simb(char *jog1, char *jog2);

/*  Funtions */
//Com retorno

int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc){
    int jogada,vec,cont=2,in;
    char jogador=' ';
    *jogc=menu();
    escolha_simb(jog1,jog2);
    inicializa_velha(velha);
    do{
        imprime_velha(velha);
            jogador=(cont%2==0?*jog1:*jog2);
            printf("\n Jogador '%c', digite uma posição de jogada de 1 à 9: ",jogador);
            //jogada = corrigirLeituraInteiros();
            fflush(stdin);
            jogada=jogada-1;
            vec=jogada_usuario(&jogada,&jogador,velha);
            if(vec==0){
                *(velha+jogada)=jogador;
                cont++;
            }
            if(vec==1) {
                    printf("\nPosição inválida!\n\n");
                    jogada=-1;
                    continue;
            }
            if(vec==2){
                    printf("\nPosição já preenchida, repetir jogada!\n\n");
                    continue;
            }
            printf("\n");
      }while(*rest==0);
    return 0;

}
int verifica_ganhador(char *jog,int *rest) {




return *rest;
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
            printf("\nSelecione qual caracter/símbolo o jogador '1' usará - 'X' ou 'O': ");
            scanf("%*c%c", &escolha);
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
                printf("Opção inválida! Favor digitar corretamente a opção 'X' ou 'O' (maiúsculo ou minúsculo!)\n");
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
