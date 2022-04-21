/*  Prototype Funtions */
// Com retorno
int mensagensJV(int num);
int entradaInteiros();
int menu();





/*  Funtions */
//Com retorno
int mensagensJV(int num){
    char mens[][200] = {
                    "\n====== MENU JOGO DA VELHA ======\n\n\n",//0
                    "(1) Jogar contra o computador.\n",//1
                    "(2) Jogar contra outro usuário.\n",//2
                    "(3) Campeonato de Jogo da Velha.\n",//3
                    "(0) Se quiser sair.\n",//4
                    "\nEscolha uma das opções do Menu: ",//5
                    "\nDigite uma opção válida!!!\n"//6
                    };
    printf(mens[num]);

    return 0;
}
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
        for (int i=0;i<5;i++){
            mensagensJV(i);
        }
        escolha = entradaInteiros(5);

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
                mensagensJV(6);
        }
    }while(erro==1);
return escolha;
}
