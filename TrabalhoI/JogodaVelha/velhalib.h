/*  Prototype Funtions */
// Com retorno
int menu();
int jogada_usuario(int lin,int col,char jog);
int verifica_ganhador(char jog);

// Sem retorno
void inicializa_velha(char *jogv);
void jogada_computador(char jog,int nivel);
void escolha_simb(char *jog1, char *jog2);


/*  Funtions */
int menu(){
    int escolha,erro=1;
    do {
        printf("\n====== MENU JOGO DA VELHA ======\n\n\n");
        printf("(1) Se quiser jogar contra o computador.\n");
        printf("(2) Se quiser jogar contra outro usuário.\n");
        printf("(0) Se quiser sair.\n");
        printf("Escolha uma das opções do Menu: ");
        scanf("%d",&escolha);

        //printf("O valor da escolha é: %d", escolha);
        switch(escolha){
            case 0:{
                exit(0);
                break;
                }
            case 1:  {
                erro=0;
                break; }
            case 2:  {
                erro=0;
                break; }
            default:
                printf("\nDigite uma opção válida!!!");
        }
    }while(erro==1);
return escolha;
}

void inicializa_velha(char *jogv) {
        int l;
        for (l=0;l<9;l++){
                *(jogv+l)=' ';

        }
}

/* void escolha_simb(char *jog1, char *jog2) {
        char escolha;
        do{
            printf("\nSelecione qual caracter/símbolo o jogador '1' usará - 'X' ou 'O': ");
            scanf("%c%*c", &escolha);
            escolha = toupper(escolha);
            if ((escolha == 'X') || (escolha == 'O')) {
                break;
                } else {
                    printf("Opção inválida! Favor digitar corretamente a opção 'X' ou 'O' (maiúsculo ou minúsculo!)\n");
                }
        }while((escolha != 'X') || (escolha != 'O'));
        if(escolha=='X') {
            *jog1=escolha;
            *jog2='O';
            } else {
                *jog1=escolha;
                *jog2='X';
                }
} */


void escolha_simb(char *jog1, char *jog2) {
        char escolha;
        int valor=0;
        do{
            printf("\nSelecione qual caracter/símbolo o jogador '1' usará - 'X' ou 'O': ");
            scanf("%*c%c", &escolha);
            escolha = toupper(escolha);

            //printf("\nO valor da escolha é: %c", escolha);
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
