/* Biblioteca do Jogo Forca  */

//Prototype Functions
void forca(int tentativa);
void escolhePalavra(int *num) ;




//Functions
void forca (int tentativa){

    switch (tentativa) {
        case 0 :
            printf("-----------------");
            printf("\n| |");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n__");
        break;
        case 1 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n|");
            printf("\n__");
        break;
        case 2 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n| |");
            printf("\n| |");
            printf("\n|");
            printf("\n|");
            printf("\n__");
        break;
        case 3 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n| -|");
            printf("\n| |");
            printf("\n|");
            printf("\n|");
            printf("\n__");
        break;
        case 4 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n| -|-");
            printf("\n| |");
            printf("\n|");
            printf("\n|");
            printf("\n__");
        break;
        case 5 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n| -|-");
            printf("\n| |");
            printf("\n| /");
            printf("\n|");
            printf("\n__");
        break;
        case 6 :
            printf("-----------------");
            printf("\n| |");
            printf("\n| 0");
            printf("\n| -|-");
            printf("\n| |");
            printf("\n| / \\");
            printf("\n|");
            printf("\n__ Você perdeu! :(");
        break;

    }
}

void escolhePalavra(int *num) {
        *num=0;
        srand((unsigned)time(NULL)); //biblioteca time.h
        *num = (rand()) % 10; //escolhe palavra aleatoria
        }

