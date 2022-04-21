/*  Prototype Funtions */
// Com retorno
int mensagensJV(int num);
int entradaInteiros();
int menu();





/*  Funtions */
//Com retorno
int mensagensJV(int num){
    char mens[][200] = {
                    "\n====== MENU JOGO DA VELHA ======\n\n\n",
                    "(1) Jogar contra o computador.\n",
                    "(2) Jogar contra outro usuário.\n",
                    "(3) Campeonato de Jogo da Velha.\n",
                    "(0) Se quiser sair.\n",
                    "Escolha uma das opções do Menu: ",

                    };
    printf(mens[num]);

    return 0;
}
int entradaInteiros(int num){
    int num,retorno=-1;
    char letra;
    do{
        mensagensJV(num);
        retorno = scanf("%d",&num);
        do{
            letra=getchar();
        }while(letra !='\n');
    }while(retorno==0);
    return num;
}

int menu(){
    int escolha,erro=1;
    do {
        for (int i=0;i<5;i++){
            mensagensJV(i);
        }
        escolha = entradaInteiros();

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
