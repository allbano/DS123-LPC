/*  Prototype Funtions */
// Com retorno
int entradaInteiros();
int menu();

//Sem retorno
void mensagensJV(int num);

/*  Funtions */
//Com retorno


int entradaInteiros(int num){
    int res,retorno=-1;
    char letra;
    do{
        mensagensJV(num);
        retorno = scanf("%d",&res);
        do{
            letra=getchar();
        }while(letra !='\n');
    }while(retorno==0);
    return res;
}

int menu(){
    int escolha,erro=1;
    do {
        for (int i=0;i<4;i++){
            mensagensJV(i);
        }
        escolha = entradaInteiros(4);

        //printf("O valor da escolha é: %d", escolha);
        switch(escolha){
            case 0:{
                exit(0);
                break; }
            case 1:  {
                erro=0;
                break; }
            case 2:  {
                erro=0;
                break; }
            case 3:  {
                erro=0;
                break; }
            default:
                mensagensJV(5);
        }
    }while(erro==1);
return escolha;
}
//Sem retorno
void mensagensJV(int num){
    char mens[][200] = {
                    "\n====== MENU JOGO DA VELHA ======\n\n\n",//0
                    "(1) Jogar Jogo da Velha.\n",//1
                    "(2) Campeonato de Jogo da Velha.\n",//2
                    "(0) Se quiser sair.\n",//3
                    "\nEscolha uma das opções do Menu: ",//4
                    "\nDigite uma opção válida!!!\n",//5
                    "\nDigite qual caracter/símbolo o jogador '1' usará - 'X' ou 'O': ", //6
                    "Opção inválida! Favor digitar corretamente a opção 'X' ou 'O'!\n (maiúsculo ou minúsculo!)\n", //7
                    "\n Jogador X, digite uma posição de jogada de 1 à 9: ", //8
                    "\n Jogador O, digite uma posição de jogada de 1 à 9: " //9
                    };
    printf(mens[num]);
}
