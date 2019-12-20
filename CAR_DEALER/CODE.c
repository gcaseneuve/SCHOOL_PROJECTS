/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 12/02/19
ASSIGNMENT: PROBLEM 1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//CREARE A STRUCTURE THAT TAKE THE CAR INFORMATION
typedef struct ADTCar{
    char CarName[256];
    int CarID;
    char CarColor[256];
    float CarPrice;
}Car;
//ALL THE FUNCTION THAT WE ARE GOING TO NEED FOR OUR PROGRAM
Car * GetArrayADT(int* NumberOfCar);
void QuickSort(Car ADTcar[], int start, int end);
int partition(Car ADTcar[],int start,int end);
void swap(Car *PreviousADT, Car *NextADT);
void PrintDatabase (Car *Data, int num);
void PurchaseOrders (Car *Data, int Size);
int SearchCarIndex (Car *Data, int CarSearch, int Size);
void PrintSingleCar(Car *Data,int Car_Index);
int main (void){
    int i,j,number;
    //INT THE NUMBER OF CAR YOU NEED 
    int NumberOfCar;
    //CREATE A BUFFER
    char buffer[256];
    char buffer1[256];
    char buffer2 [256];
    //CREATE A POINTER THAT READ FROM A FILE
    //GET A FUNCITON THAT IS GOING TO ALLOCATE MEMORY FOR THE STRUCTURES
    Car * RetrnADT = GetArrayADT(&NumberOfCar);
    Car * CpyADT = GetArrayADT (&NumberOfCar);
    //CREATE A VARIABLE THAT IS GOING TO HOLD THE USER INPUT
    int decision;
    printf("\nWELCOME TO OUR STORE. HERE ARE THE OPTION THAT WE HAVE\n\n");
    while(1){
        // PRINT THE MESSAGES AND THE DIFFRE
        printf("Option 1: PRINT INVENTORY AS IT WAS ENTERED IN THE SYSTEM\n");
        printf("Option 2: PRINT INVENTORY IN ASCENDING ORDER BASED ON THE PRICE\n");
        printf("Option 3: SEARCH FOR A CAR\n");
        printf("Option 4: PURCHASE A CAR\n");
        printf("Option 5: EXIT THE PROGRAM\n");
        printf("\nPLEASE ENTER YOUR OPTION NUMBER\n");
        scanf("%d", &decision);
        //CREATE A SWITCH STATEMENT THAT APPLY THE TASK MADE BY THE PROGRAM
        switch (decision){
                //PRINT THE INVENTORY
            case 1: printf("\n\n\t      *****THIS YOUR NON-SORTED INVENTORY*****\n");
                    PrintDatabase(CpyADT,NumberOfCar);
                    break;
                //PRINT THE SORTED INVENTORY
            case 2: printf("\n\n\t      *******THIS YOUR SORTED INVENTORY*******\n");
                    QuickSort(RetrnADT,0,NumberOfCar-1);
                    PrintDatabase(RetrnADT,NumberOfCar);
                    break; 
                //SEARCH FOR A CAR
            case 3:
                    printf("Enter the car ID you want to find:\n");
                    scanf("%d",&number);
                    number = SearchCarIndex(RetrnADT,number,NumberOfCar);
                    if(number < 0){
                        printf("\n\n*****We don't have this car in the inventory*****\n\n");
                    }else{
                        printf("\n\n\t\t   *****THIS IS THE CAR INFO*****\n");
                        PrintSingleCar(RetrnADT,number);
                    }
                    break;
                //PURCHASE A CAR
            case 4: printf("\n");
                    printf("\t      *******THIS YOUR SORTED INVENTORY*******\n");
                    PrintDatabase(RetrnADT,NumberOfCar);
                    PurchaseOrders (RetrnADT,NumberOfCar);
                    break;
                //STOP THE PROGRAM
            case 5: printf("\n***THANK YOU FOR VISITING OUR PROGRAM***\n\n");
                    exit(0);
            default: printf("\nYou have entered the wrong option!\n\n");
        }
        printf("\n");
    }
    free(RetrnADT);
    return 0;
}
//READ FROM THE FILE
Car * GetArrayADT(int* NumberOfCar){
    int i;
    char buffer[256];
    char buffer1[256];
    FILE *inputFile = fopen("car.txt", "r");
    fgets(buffer,256,inputFile);
    sscanf(buffer,"%d", NumberOfCar);
    Car * Array = (Car *) malloc(sizeof(Car)* (*NumberOfCar));
      
    //NOW LET'S ADD THE INFO IN THE STRUCTURES
    for(i=0;i<(*NumberOfCar);i++){
        fgets(Array[i].CarName,50,inputFile);
        Array[i].CarName[strlen(Array[i].CarName)-2] = 0;
        fgets(buffer,256,inputFile);
        sscanf(buffer,"%d", &(Array[i].CarID));
        fgets(Array[i].CarColor,50,inputFile);
        Array[i].CarColor[strlen(Array[i].CarColor)-2] = 0;
        fgets(buffer1,256,inputFile);
        sscanf(buffer1,"%f", &(Array[i].CarPrice));
    }
    //CLOSE THE FILE AFTER READING IT
    fclose(inputFile);
    return Array;
}
//FUNCTION THAT DO THE SORT THE ELEMETS USING QUICK SORT
void QuickSort(Car ADTcar[], int start, int end){
    int PartitionIndex,i;
    if(start >= end){
        return;
    }
    //GET THE FIRST PARTITION
    PartitionIndex = partition(ADTcar,start,end);
    //SORT TEH LEFT SIDE OF THE PIVOT
    QuickSort (ADTcar,start,PartitionIndex-1);
    //SORT THE RIHGT SIDE OF THE PIVOT
    QuickSort(ADTcar,PartitionIndex+1,end);
}
//PARTITION  THE VALUE TO THE LEFT
int partition(Car ADTcar[],int start,int end){
    int i;
    int pivot = ADTcar[end].CarPrice;
    int pIndex = start;
    //PUT ALL THE ELEMENT THAT ARE LESS THAN THE PIVOT ON THE LEFT 
    for(i=start;i<end;i++){
        if(ADTcar[i].CarPrice<= pivot){
            swap(&ADTcar[i],&ADTcar[pIndex]);
            pIndex++;
        }
    }
    //SWAP THE PIVOT AT THE END
    swap(&ADTcar[pIndex],&ADTcar[end]);
    return pIndex;
}
//SWAP TWO ELEMENTS
void swap(Car *PreviousADT, Car *NextADT){
    Car temp = *PreviousADT;
    *PreviousADT = *NextADT;
    *NextADT = temp;
}
//PRITNT THE STRUCTURE
void PrintDatabase (Car *Data, int num){
	int i,j,k;
    //PRINT THE TOP BORDER
    for(i=0;i<66;i++){
         if(i==16 || i==32 || i==48){
            printf("┬");
        }else if (i==0){
            printf("┌");
        }else if (i==65){
            printf("┐");
        }else{
            printf("─");   
        }  
    }
    //PRINT THE MIDDLE BORDERS
    printf("\n");
    //NOW IT IS TIME TO PRINT OUT THE REPORT IN A FILE
    printf("│NAME\t\t│ID\t\t│COLOR\t\t│PRICE\t\t │\n");
    for(i=0;i<66;i++){
        if(i==16 || i==32 || i==48){
            printf("┼");
        }else if (i==0){
            printf("├");
        }else if (i==65){
            printf("┤");
        }else{
            printf("─");   
        }   
    }
    printf("\n");
    //PRINT THE INFORMATION THAT ARE INSIDE THE STRUCTURES
    for(i=0;i<num;i++){
        printf("│%-9s\t│\t", Data[i].CarName);
        printf(" %7d│\t", Data[i].CarID);
        printf(" %7s│\t", Data[i].CarColor);
        printf("$%-5.2f│\n", Data[i].CarPrice);
    }
    
    //PRINT THE BOTTOM BORDERS
    //NOW IT IS TIME TO PRINT OUT THE REPORT IN A FILE
    for(i=0;i<66;i++){
        if(i==16 || i==32 || i==48){
            printf("┴");
        }else if (i==0){
            printf("└");
        }else if (i==65){
            printf("┘");
        }else{
            printf("─");   
        }   
    }
    printf("\n");
}
//PURCHASE CARS THT AERE IN THE INVENTORY
void PurchaseOrders (Car *Data, int Size){
    int i,Car_Index, number_car;
    double subtotal=0.0, total = 0.0;
    double tax = 6.8;
    int CAR_SEARCH;
    //ASK THE USER FOR THE AMOUNT OF CARS HE/SHE WANTS TO BUY 
    printf(">How many car do you want to buy? ENTER THE CAR ID PLEASE.\n");
    scanf("%d",&number_car);
    //CREATE A NEW ARRAY THAT IS GOING TO TAKE ALL TEH CARS THAT THE USER WANTS TO BUY 
    Car *CpyADT = malloc(sizeof(Car)*number_car);
    for(i=0;i<number_car;i++){
        printf(">Please enter card ID number %d:\n",i+1);
        scanf("%d",&CAR_SEARCH);
        //GET THE INDEX OF THE CAR
        Car_Index  = SearchCarIndex(Data,CAR_SEARCH,Size);
        //TAKE THE TOTAL
        subtotal += Data[Car_Index].CarPrice;
        //ADD IT IN THE CPY ARRAY
        CpyADT[i] = Data[Car_Index];
    }
    printf("\n\t     ***********HERE'S YOUR INVOICE************\n");
    //PRINT A LIST OF TCARS THAY THE USER WANTS TO BUY
    PrintDatabase(CpyADT,number_car);
    //GET THE TOTAL AND BELOW PRIN THE SUBTOTAL/TAX AND TOTAL IN GENERAL
    total = subtotal + ((subtotal * tax)/100);
    printf("\t\t\t\tSUBTOTAL\t\t$%7.2f\n",subtotal);
    printf("\t\t\t\tTAX\t\t\t$%8.2f\n",((subtotal * tax)/100));
    printf("\t\t\t\tTOTAL\t\t\t$%7.2f\n",total);
    //FREE TEH CPT ARRAY
    free (CpyADT);
    
}
//PRINT ONE CAR AFTER THE SEARCH
void PrintSingleCar(Car *Data,int Car_Index){
    	int i,j,k;
    //PRINT THE TOP BORDER
    for(i=0;i<66;i++){
         if(i==16 || i==32 || i==48){
            printf("┬");
        }else if (i==0){
            printf("┌");
        }else if (i==65){
            printf("┐");
        }else{
            printf("─");   
        }  
    }
    //PRINT THE MIDDLE BORDERS
    printf("\n");
    //NOW IT IS TIME TO PRINT OUT THE REPORT IN A FILE
    printf("│NAME\t\t│ID\t\t│COLOR\t\t│PRICE\t\t │\n");
    for(i=0;i<66;i++){
        if(i==16 || i==32 || i==48){
            printf("┼");
        }else if (i==0){
            printf("├");
        }else if (i==65){
            printf("┤");
        }else{
            printf("─");   
        }   
    }
    printf("\n");
    //PRINT THE INFORMATION
        printf("│%-7s\t│\t", Data[Car_Index].CarName);
        printf(" %7d│\t", Data[Car_Index].CarID);
        printf(" %7s│\t", Data[Car_Index].CarColor);
        printf("$%-5.2f│\n", Data[Car_Index].CarPrice);
    //PRINT THE BOTTOM BORDERS
    //NOW IT IS TIME TO PRINT OUT THE REPORT IN A FILE
    for(i=0;i<66;i++){
        if(i==16 || i==32 || i==48){
            printf("┴");
        }else if (i==0){
            printf("└");
        }else if (i==65){
            printf("┘");
        }else{
            printf("─");   
        }   
    }
    printf("\n");
}
//FUNCITON THAT IS SUPPOSED TO RETURN THE INDEX OF A PARTICULAR SEARCH
int SearchCarIndex (Car *Data, int CarSearch, int Size){
    int i, count=0;
    for (i=0;i<Size; i++){
        if(Data[i].CarID != CarSearch){
            count++;
        }else{
            return count;
        }
    }
    return -1;
}