/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 09/12/19
ASSIGNMENT: PROBLEM 3
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void ReadNumber(void);
void CompareValues(int *, int *, int *,int);
void printNumbers(int, int , int , int ,int,int);
void CompareValuesOccurence(int *fOccurence, int *sOccurence, int *tOccurence, int fValue, int sValue, int tValue, int Value);
int main(void){
    //CREATE A VARIABLE FOR THE RANDOM VALUE
    int rValue;
    //CREATE A VARIBALE THAT SAVE TEH NUMBER
    int Number;
    //CREATE A LOCAL VARIABLE
    int i;
    
    //CREATE THE FILE AND OPEN IT TO WRITE THE NUMBER
     FILE *inputFile = fopen ("input1.txt", "w");
    //CREATE A FOR LOOP THAT WRITE THE NUMBER IN THE FILE
        for (i=0 ; i<20; i++){
        //DO THE RANDOM VALUE
        rValue = rand();
        //SHIFT THE VALUE TO ONLY [0,100]
        Number = rValue % 100 ;
        //PRINT THE VALUE
        fprintf(inputFile,"%d\n",Number);
    }
    //CLOSE THE FILE  
    fclose(inputFile);
    //CALL THE FUNCTION THAT IS GOING TO READ NUMBER
    ReadNumber();
    return 0;
}

void ReadNumber(void){
    int fLoccurence = 0;
    int sLoccurence = 0;
    int tLoccurence = 0;
    int Value;\
    int firstLargestValue = 0;
    int secondLargestValue = 0;
    int thirdLargestValue = 0;
    
    
FILE *inputFile  = fopen ("input1.txt", "r");
    //CREARE A WHILE LOOP THAT IS READING FROM THE NUMBER
    while (fscanf(inputFile,"%d\n",&Value)!= -1){
        //printf("%d\n\n",Value);
     CompareValues (&firstLargestValue,&secondLargestValue,&thirdLargestValue,Value);
        }
    fclose(inputFile);
    //printf("%d %d %d ",firstLargestValue,secondLargestValue,thirdLargestValue);
    
    inputFile  = fopen ("input1.txt", "r");
     while (fscanf(inputFile,"%d\n",&Value)!= -1){
        //printf("%d\n\n",Value);
     CompareValuesOccurence (&fLoccurence,&sLoccurence,&tLoccurence,firstLargestValue,secondLargestValue,thirdLargestValue,Value);
        }
    fclose(inputFile);
    //printf("%d %d %d ",firstLargestValue,secondLargestValue,thirdLargestValue);
    printNumbers (firstLargestValue,fLoccurence,secondLargestValue,sLoccurence,thirdLargestValue,tLoccurence);
    
}
void CompareValues(int *fValue, int *sValue, int *tValue, int Value){ 
    if(Value>(*fValue)){
            *tValue = *sValue;
            *sValue = *fValue;
            *fValue = Value;
        }else if(Value > (*sValue) && Value != (*fValue)){
            *tValue = *sValue;
            *sValue = Value;
        }
        else if(Value>(*tValue) && Value != (*sValue) && Value != (*fValue)) {
            *tValue = Value;
        }
}
void CompareValuesOccurence(int *fOccurence, int *sOccurence, int *tOccurence, int fValue, int sValue, int tValue, int Value){
      if(fValue == Value){
        (*fOccurence)++;
    }
    if(sValue == Value){
        (*sOccurence)++;
    }
    if(tValue == Value){
        (*tOccurence)++;
    }
}

void printNumbers(int fLnumber, int fOccurence, int sLnumber, int sOccurence,int tLnumber, int tOccurence){
    //IF THE NUMBER DOESNT REPEAT JUST DISPLAY THE VALUE 
    if(fOccurence == 1){
        printf("The First Largest Number is: %d. And it is not repeated in the list.\n",fLnumber);
    }else if (fOccurence > 1 ){ //ELSE IF THE NUMBER IS REPEATED DISPLAY THE NUMBER OF OCCURECNE
        printf("The First Largest Number is: %d. And it is repeated %d time in the list.\n",fLnumber,fOccurence);
    }
    //IF THE NUMBER DOESNT REPEAT JUST DISPLAY THE VALUE 
    if(sOccurence == 1){
        printf("The Second Largest Number is: %d. And it is not repeated in list.\n",sLnumber);
    }else if (sOccurence > 1){ //ELSE IF THE NUMBER IS REPEATED DISPLAY THE NUMBER OF OCCURECNE
        printf("The Second Largest Number is: %d. And it is repeated %d time in the list.\n",sLnumber,sOccurence);
    }
    //IF THE NUMBER DOESNT REPEAT JUST DISPLAY THE VALUE 
    if(tOccurence == 1){
        printf("The Third Largest Number is: %d. And it is not repeated in list.\n",tLnumber);
    }else if (tOccurence > 1) { //ELSE IF THE NUMBER IS REPEATED DISPLAY THE NUMBER OF OCCURECNE
        printf("The Third Largest Number is: %d. And it is repeated %d time in the list.\n",tLnumber,tOccurence);
    }
}