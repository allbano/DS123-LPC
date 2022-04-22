/*  Prototype Funtions */
// Com retorno


int jogada_usuario(int *pos,char *jogador,char *velha);
int verifica_ganhador(char *jog,char *velha);
int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc);

// Sem retorno
void imprime_velha(char *posix);
void inicializa_velha(char *velha);
void jogada_computador(char jog,int nivel);
void escolha_simb(char *jog1, char *jog2);

/*  Funtions */
//Com retorno
int jogar_velha(char *velha,char *jog1, char *jog2,int *rest,int *jogc){
    int jogada,vec,cont=0,ganhador=0;
    char jogador=' ';
    *jogc=menu();
    escolha_simb(jog1,jog2);
    inicializa_velha(velha);
    do{
        imprime_velha(velha);
            jogador=(cont%2==0?*jog1:*jog2);
            if(jogador=='X'){
                jogada = entradaInteiros(8);
                } else {
                    jogada = entradaInteiros(9);
                    }
            fflush(stdin);
            --jogada;
            vec=jogada_usuario(&jogada,&jogador,velha);
            if(vec==0){
                *(velha+jogada)=jogador;
                cont++;
                ganhador++;
            }
            if(vec==1) {
                    printf("\nPosição inválida!\n\n");
                    continue;
            }
            if(vec==2){
                    printf("\nPosição já preenchida, repetir jogada!\n\n");
                    continue;
            }
            printf("\n");
            if(ganhador>3){
                *rest=verifica_ganhador(&jogador,velha);
            }
      }while(*rest==0);
      return *rest;
}
int verifica_ganhador(char *jog,char *velha) {
        //Verifica as linhas
        int res=0;
        if(*jog=='X'){
            res=88;
        } else {
            res=79;
            }
        if((*(velha+0)==*jog) &&(*(velha+1)==*jog) && (*(velha+2)==*jog)
           ||(*(velha+3)==*jog) &&(*(velha+4)==*jog) && (*(velha+5)==*jog)
           ||(*(velha+6)==*jog) &&(*(velha+7)==*jog) && (*(velha+8)==*jog)){
               return res;
        }
        //Verifica as colunas
        if((*(velha+0)==*jog) &&(*(velha+3)==*jog) && (*(velha+6)==*jog)
           ||(*(velha+2)==*jog) &&(*(velha+4)==*jog) && (*(velha+7)==*jog)
           ||(*(velha+3)==*jog) &&(*(velha+5)==*jog) && (*(velha+8)==*jog)){
               return res;
        }
        //Verifica as diagonais
        if((*(velha+0)==*jog) &&(*(velha+4)==*jog) && (*(velha+8)==*jog)
           ||(*(velha+2)==*jog) &&(*(velha+4)==*jog) && (*(velha+6)==*jog)){
               return res;
        }
return 0;
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
            mensagensJV(6);
            scanf("%c%*c", &escolha);
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
                mensagensJV(7);
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
