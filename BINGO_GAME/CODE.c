/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 11/21/19
ASSIGNMENT: PROBLEM 1
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int randomNumber (int min, int max);
void play();
int ** CardGenerator(int Size);
int checkWin(int ** Array);
void CheckValue (int ** FirstCard,int ** SecondCard,int ** ThirdCard, int number);
int checkValue (int * Array, int value, int Size);
void Free(int **Array);
void PrintCard(int ** FirstPlayerCard,int ** SecondPlayer,int ** ThirdPlayer, char letter[]);
int main(void){
    play();
    return 0;
}
void play(){
    char c;
    int i,j;
    int drawBall;
    srand(time(NULL));
    int ** FirstPlayer = CardGenerator(5);
    int ** SecondPlayer = CardGenerator(5);
    int ** ThirdPlayer = CardGenerator(5); 
    char Letter[] = {
        "B"
        "I"
        "N"
        "G"
        "O"
    };
    PrintCard(FirstPlayer,SecondPlayer,ThirdPlayer,Letter);
    printf("The game has started.\n");
    int count=0;
    while (!count){
        printf("PLEASE DRAW A BALL BY PRESSING ENTER");
        scanf("%c",&c);
        drawBall = randomNumber(1,75);
        if(drawBall >0 && drawBall < 16){
            printf("You Draw: B-%d\n",drawBall);
        }else if(drawBall >15 && drawBall < 31){
            printf("You Draw: I-%d\n",drawBall);
        }else if(drawBall >30 && drawBall < 46){
            printf("You Draw: N-%d\n",drawBall);
        }else if(drawBall >45 && drawBall < 61){
            printf("You Draw: G-%d\n",drawBall);
        }else if(drawBall >60 && drawBall < 76){
            printf("You Draw: O-%d\n",drawBall);
        }
        //PRINT THE CARDS
        PrintCard(FirstPlayer,SecondPlayer,ThirdPlayer,Letter);
        //cleprintf("%d \n",drawBall);
        CheckValue(FirstPlayer,SecondPlayer,ThirdPlayer,drawBall);
        if(checkWin(FirstPlayer)){
            printf("BINGO!!! The First Player has won the game!!\n\n");
            printf("THE FINAL CARDS ARE:\n");
            PrintCard(FirstPlayer,SecondPlayer,ThirdPlayer,Letter);
            break;
        }else if(checkWin(SecondPlayer)){
            printf("BINGO!!! The Second Player has won the game!!\n\n");
            printf("THE FINAL CARDS ARE:\n");
            PrintCard(FirstPlayer,SecondPlayer,ThirdPlayer,Letter);
            break;
        }else if(checkWin(ThirdPlayer)){
            printf("BINGO!!! The Third Player has won the game!!\n\n");
            printf("THE FINAL CARDS ARE:\n");
            PrintCard(FirstPlayer,SecondPlayer,ThirdPlayer,Letter);
            break;
        }
    }
    Free(FirstPlayer);
    Free(SecondPlayer);
    Free(ThirdPlayer);
}

int ** CardGenerator(int Size){
    
    //CREATE A RANDOM GENERATOR
    int value;
    int index=0;
    //CREATE THE ARRAY
    int **Card = malloc (sizeof(int*)*Size);
    for(index =0; index<Size; index++){
        Card[index]= (int*) malloc(Size * sizeof(int));
    }
    //ADD THE NUMBER IN THE ARRAY IN THE FIRST ROW
    for(index =0; index<Size; index++){
        value = randomNumber(1,15);
        while(checkValue(Card[0],value,Size)){
            value = randomNumber(1,15);
        }
        Card[0][index] = value;
    }
    //ADD THE NUMBER IN THE ARRAY IN THE FIRST ROW
    for(index =0; index<Size; index++){
        value = randomNumber(16,30);
        while(checkValue(Card[1],value,Size)){
            value = randomNumber(1,15);
        }
        Card[1][index] = value;
    }
    //ADD THE NUMBER IN THE ARRAY IN THE FIRST ROW
    for(index =0; index<Size; index++){
        value = randomNumber(31,45);
        while(checkValue(Card[2],value,Size)){
            value = randomNumber(1,15);
        }
        Card[2][index] = value;
    }
    for(index =0; index<Size; index++){
        value = randomNumber(46,60);
        while(checkValue(Card[3],value,Size)){
            value = randomNumber(1,15);
        }
        Card[3][index] = value;
    }
    for(index =0; index<Size; index++){
        value = randomNumber(61,75);
        while(checkValue(Card[4],value,Size)){
            value = randomNumber(1,15);
        }
        Card[4][index] = value;
    }
    //RETURN THE 2D ARRAY
    //Free(Card);
    return Card;
}
//FUNCTION THAT GENERATE NEW RANDOM NUMBER
int randomNumber (int min, int max){
    return min + rand() % (max+1 - min);
}
//FUNCTION THAT CHECK IF A PLAYER WIN THE GAME
int checkWin(int ** Array){
    int i,j,count=0, count1 =0, count2 =0, count3 =0;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(Array[i][j] == 0){
                count++;
            }
        }
        if(count == 5){
            return 1;
        }
        count = 0;
    }
   for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(Array[j][i] == 0){
                count1++;
            }
        }
        if(count1 == 5){
            return 1;
        }
        count1 = 0;
    } 
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==j){
                if(Array[i][j] == 0){
                    count2++;
                }
            }
        }
    }
    if(count2 == 5){
        return 1;
    }
    for(i=0;i<5;i++){
        for(j=5;j>0;){
            if(Array[i][j-i-1] == 0){
                count3++;
            }
            j=0;
        }
    }
    if(count3 == 5){
        return 1;
    }
    return 0;
}
//FUNCTION THAT CHECK IF THE CARD HAS THE DRAW NUMBER
void CheckValue (int ** FirstCard,int ** SecondCard,int ** ThirdCard, int number){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(FirstCard[i][j] == number){
                FirstCard[i][j] = 0;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(SecondCard[i][j] == number){
                SecondCard[i][j] = 0;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(ThirdCard[i][j] == number){
                ThirdCard[i][j] = 0;
            }
        }
    }
    
}
void Free(int **Array){
    int i;
     for(i=0;i<5;i++){
        free(Array[i]);
    }
    free(Array);
}
//ARRAY THAT PREVENT THE NUMBERS TO BE REPEATED
int checkValue (int * Array, int value, int Size){
    int i;
    for(i=0; i<Size;i++){
        if(Array[i] == value){
            return 1;
        }
    }
    return 0;
}
//FUNCITON THAT PRINTS THE CARD OF THE PLAYER
void PrintCard(int ** FirstPlayer,int ** SecondPlayer,int ** ThirdPlayer, char letter[]){
    int i,j;
    printf("\n");
    printf("Player 1 Bingo Card:\n");
    printf("______________________________\n");
    for(i=0;i<5;i++){
        printf("||%c|| ",letter[i]);
        //printf("---------------\n");
        for(j=0;j<5;j++){
             if(FirstPlayer[i][j] == 0){
                printf("< X> ");
            }else{
                printf("<%2d> ",FirstPlayer[i][j]);
             }
        }
        printf("\n");
        printf("------------------------------\n");
    }
    printf("\n");
    printf("Player 2 Bingo Card:\n");
    printf("______________________________\n");
    for(i=0;i<5;i++){
        printf("||%c|| ",letter[i]);
        //printf("----------letter-----\n");
        for(j=0;j<5;j++){
            if(SecondPlayer[i][j] == 0){
                printf("< X> ");
            }else{
                printf("<%2d> ",SecondPlayer[i][j]);
            }
        }
        printf("\n");
        printf("------------------------------\n");
    }
    printf("\n");
    printf("Player 3 Bingo Card:\n");
    printf("______________________________\n");
    for(i=0;i<5;i++){
        printf("||%c|| ",letter[i]);
        //printf("---------------\n");
        for(j=0;j<5;j++){
            if(ThirdPlayer[i][j] == 0){
                printf("< X> ");
            }else{
                printf("<%2d> ",ThirdPlayer[i][j]);
            }
        }
        printf("\n");
        printf("------------------------------\n");
    }
    printf("\n");
}