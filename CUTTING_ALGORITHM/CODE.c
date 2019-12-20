/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 09/30/19
ASSIGNMENT: PROBLEM 2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cutRacks (int * OriginalArray, int RacksLenght, int minRacks, int ArraySize);
int isEmptyArray(int * ArrayofRack,int spotArray);
int * CloneArray (int *, int ArraySize);
int main (void){
    int value;
    int Racks,i,Racks1,j,a;
    //PRINT A MESSAGE THAT WELCOME THE USER TO THE GAME
    printf("******************************************************\n");
    printf("|                  WELCOME TO OUR STORE              |\n");
    printf("******************************************************\n");
    printf("* THIS PROGRAM WILL HELP YOU SAVE MONEY BY PROVIDING *\n");
    printf("* THE MINIMUM OF RACKS YOU CAN PURCHASE. OUR STORE   *\n");
    printf("* ONLY PROVIDE RACKS OF SIZE 10 inches AT 10$ EACH.  *\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("*               HOW MANY RACKS DO YOU NEED           *\n");
    printf("------------------------------------------------------\n");
    scanf("%d",&Racks);
    //TREAT THE CASE WHERE THE USER ENTERED A NEGATIVE NUMBER AND TURN IT INTO POSITIF
    if(Racks <0){
        Racks *= -1;
        printf("######################################################\n");
        printf("This program cannot run negative; Therefore it treats\n");
        printf("as if it were a positive number.\n");
        printf("######################################################\n");
    }
    //CREATE AN ARRAY AND CLOWN ARRAY THAT IS GOING SAVE THE VALUE NEEDED BY THE USER
    int RacksNeeded[Racks];
    //ASK FOR THE NUMBER OF RACKS NEED 
    printf("------------------------------------------------------\n");
    printf("* ENTER THE NUMBER OF RACKS YOU NEED:                *\n");
    printf("------------------------------------------------------\n");
    //CREATE A LOOP THAT CREATE THE SAVE THE VALUE IN THE ARRAY
    for(i=0;i<Racks;i++){
        scanf("%d",&Racks1);
        //CHECK TO SEE IF THE USER ENTER A NUMBER LARGER THAN THE VALUE THAT STORE PROVIDE
        if(Racks1 > 10){
            //CRASH THE PROGRAM IF THE RACK OIS BIGGER THAN 10
            printf("######################################################\n");
            printf("##YOU ARE REQUESTING RACKS LARGER THAN WHAT WE OFFER##\n");
            printf("######################################################\n");
            return 0;
        }else if(Racks1 < 0 ){
             //CRASH THE PROGRAM IF THE RACK IS LESS THAN ZERO
            printf("######################################################\n");
            printf("##YOU ENTERED A NEGATIVE SIZE RACKS. RE-RUN IT AGAIN##\n");
            printf("######################################################\n");
            return 0;
        }
        RacksNeeded[i] = Racks1;
    }
    //SORT THE ARRAY IN DESCENDINBG ORDER
    for (i=0; i<Racks;++i) 
        {
            for (j =i+1; j<Racks;++j) 
            {
                if (RacksNeeded[i] < RacksNeeded[j]) 
                {
                    a = RacksNeeded[i];
                    RacksNeeded[i] = RacksNeeded[j];
                    RacksNeeded[j] = a;
                }
            }
        }
    
    //CALL THE RECURSIVE FUNCTION
    value = cutRacks (RacksNeeded,10,1,Racks);
    //PRINT THE VALUE
    printf("------------------------------------------------------\n");
    printf("* YOU CAN HAVE A MININUM OF %d RACKS WITH A TOTAL     \n",value);
    printf("* PRICES OF $%d.                                     \n",value*10);
    printf("******************************************************\n");
    printf("|             THANK YOU FOR SHOPPING WITH US!        |\n");
    printf("------------------------------------------------------\n");
    return 0;
}
//THIS RECURSIVE FUNCTION WILL TAKE EVERY ELEMENT IN THE RACKS ARRAY AND GROUP THEM UNTIL THERE IS NO MORE SPACE 
int cutRacks (int * OriginalArray, int RacksLenght, int minRacks, int ArraySize){
    //BASE CASE
  if(isEmptyArray (OriginalArray,ArraySize)){
      return minRacks;
  }
    //GLOBAL VARIABLE
    int i,k, constant =0;
    int LeastOfaTube = 10;
    int sizeOfTube;
    //FOR LOOP THAT IS TRAVELLING IN THE ARRAY AND GET THE EACH INDEX AT A TIME
    for(i=0;i<ArraySize;i++){
        //IF I ALREADY USE AN ELEMENT IN THE ARRAY JUST CONTINUE
        if(OriginalArray[i]==-2){continue;}
        //CREATE THE COPY OF THE ARRAY
        int * Clone= CloneArray (OriginalArray, ArraySize);
        //REPLACE IT BY -2 IF WE TAKE THE INDEX
        Clone[i]=-2;
        //IF IT CAN'T BE FIT, REQUEST A NEW RACK 
        if(OriginalArray[i]>RacksLenght){
            sizeOfTube = cutRacks(Clone,10-OriginalArray[i],minRacks+1,ArraySize);
        }
        //IF IT CAN BE FIT, KEEP ADDING RACK UNTIL YOU CANNOT
        else{
            sizeOfTube =cutRacks(Clone,RacksLenght-OriginalArray[i],minRacks,ArraySize);
        }
        //UPDATE THE VALUE OF RACK ALREADY USE AND RETURN IT.
        if(LeastOfaTube>sizeOfTube){
            LeastOfaTube = sizeOfTube;
        }
        //SINCE WE ALLOCATED MEMORIES, WE HAVE TO FREE THESE MEMORIES
        free(Clone);
    }
        //RETURN THE AMOUTF OF RACK USED
    return LeastOfaTube;
    
}
//CHECK TO SEE IF THE ARRAY IS EMPTY BY REPLACING ALL THE SPOT USED BY NEGATIVE 2
int isEmptyArray(int * ArrayofRack,int spotArray){
    int emptyValue= -2;
    int i;
    int count=0;
    //CHECK IT WITH A FOR LOOP
    for (i=0;i<spotArray;i++){
        if(ArrayofRack[i] == emptyValue){
            count++;
        }
    }
    //IF CONDITION IF THE ARRAY IS EMPTY
    if(count == spotArray){
        return 1;
    }else {
        return 0;
    }

}
//CREATE A CLONE ARRAY THAT IS GOING TO COPY EVERY TIME WHAT IS INSIDE THE ORIGINAL ARRAY
int * CloneArray(int * OriginalArray, int ArraySize){
    //ALLOCATING MEMORIES FOR THE ARRAYS
    int* copyArray = (int*)malloc(sizeof(int) * ArraySize);
    int i;
    //DO THE COPY WITH A FOR LOOP
     for(i=0;i<ArraySize;i++){
        copyArray[i] = OriginalArray[i];
    }
    return copyArray;
}