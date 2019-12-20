#include  <stdio.h>
#include <time.h>
/*
Name: Guy Marvens Caseneuve
Date Friday 4th October 2019


*/


//CREATE A FUNCTION THAT GIVES YOU A RANDOM VALUE BETWEEN 1 -13
int drawCard (){
	int rValue = rand() % 13 + 1;
	return rValue;
}

char getUserInput(){
	//CREATE A LOCAL CHAR 
	char c;
	//PRINT OUT THE STATEMENT 
	printf("Would you like to draw another card? [y/n]\n");
	//TAKE THE USER INPUT
	scanf("%c", &c);
	//CLEAR THE BUFFER
	while (getchar() != '\n');
	return c;
}

int userTurn(){
	//CREATE A LOCAL VARIABLE
	int maxPoint = 21;
	int Sum;
	int tryValue;
	//CREATE A LOCAL CHAR 
	char c;
	//CREATE A VARIABLE THAT SAVES THE USER VALUE
	int value1, value2;
	//CREATE THE RANDOM VALUE
	value1 = drawCard();
	value2 = drawCard();
	Sum = value1+value2;
	//PRINT OUT THE SUM OF THE SUM
	printf("Your card sum is: %d\n",Sum);
	//ASK THE USER IF THEY WANT TO KEEP PLAYING IF THE SUM IS LESS THAN 21
	//IF STATEMENT TO SEE IF THE SUM IUS LESS THAN 21 
	if (Sum <21){
		while (Sum < maxPoint){
			//ASK THE USER IF HE WANTS TO PLAY 
			c = getUserInput();
			if(c == 'n'){
				break;
			}
			//GET THE NEW RANDAM CARD
			tryValue = drawCard();
			//ADD IT TO THE SUM
			Sum = Sum + tryValue;
			//PRINT THE SUM EVERYTIME THAT THE PLAYER 
			printf("Your card Sum is: %d\n", Sum);
		}
	}
	//RETURN SUM
	return Sum;

}



int dealerTurn(int UserSum){
	int tryValue2;
	int value1, value2;
	//TAKE THE SUM OF THE DEALER PLAYER
	int Sum2;
	//CREATE THE RANDOM VALUE
	value1 = drawCard();
	value2 = drawCard();
	Sum2 = value1+value2;
	//TAKE THE SUM OF THE DEALER PLAYER

	while (Sum2 < UserSum && Sum2 < 21){

		//GET THE NEW RANDAM CARD
		tryValue2 = drawCard();
		//ADD IT TO THE SUM
		Sum2 = Sum2 + tryValue2;
	}
	return Sum2;
}
void playGame(){
	//CREATE A VARTIABLE THAT STORE THE SUER SUM 
	int SumPlayer;
	int SumDealer;
	SumPlayer = userTurn();
	//CHECK TO SEE IF THE USER WIN OR NOT
	if (SumPlayer < 21){
		SumDealer = dealerTurn(SumPlayer);
		if (SumDealer > 21){
			printf("Dealer's card sum is: %d\n",SumDealer);
			printf("Dealer Bust!\n");
			printf("Player wins!\n");
		}else if (SumDealer > SumPlayer){
				printf("Dealer's card sum is: %d\n",SumDealer);
				printf("Bust!\n");
				printf("Dealer wins!\n");
		}else {
					printf("Dealer's card sum is: %d\n",SumDealer);
					printf("Dealer Bust!\n");
					printf("Player wins!\n");	
		}
	}else{
		printf("Player's card sum is: %d\n",SumPlayer);
		printf("Bust!\n");
		printf("Dealer wins!\n");
		
	}	


}

int main (void){
	srand(time (NULL));
	playGame();
	return 0;

}
