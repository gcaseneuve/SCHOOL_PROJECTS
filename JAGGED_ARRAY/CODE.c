/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 09/25/19
ASSIGNMENT: PROBLEM 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float **CreateArray(int size[],int SizeArray);
int * ReturnJSize (int JaggedArraySize[]);
float FLOAT_RAND( float min, float max );
void fill2DArray(float** Array,int *Row, int JagSize);
void print2DArray(float** Array,int *Row, int JagSize);
float ** CreateColumnJArray(float ** Array, int *JaggedArraySize, int *CloanArray);
void swap(float *PreviousValue, float *NextValue);
int partition(float JArray[],int start,int end);
void QuickSort(float JArray[], int start, int end);
float ** GetOriginalSortedJA(float **Array, int *JaggedArraySize, float ** ColumnJA);
int main(void){
    //CREATE A GLOBAL ARRAY
    int GlobalArray[]= {10,5,2,7,6};
    srand(time(0));
    int i;
    //ALLOCATE MEMORY TO TRANSFORM THE ARRAY INTO POINTER
    int *JaggedArraySize = malloc(sizeof(int)*5);
    //FILL THE ARRAY WITH ELEMENT 
    for(i=0;i<5;i++){
        JaggedArraySize[i] = GlobalArray[i];
    }
    //ALLOCATE MEMORY FOR THE JAGGED ARRAY
    float ** OriginalJaggedArray = CreateArray(JaggedArraySize,5);
    //RETURN THE SIZE OF THE ORIGNAL JAGGED ARRAY SO WE CAN MAKE THE OTHER VERSION OF THE JAGGED ARRAY
    int * NewJaggedArraySize = ReturnJSize (JaggedArraySize);
    //CREATE THE SECOND VERSION OF THE JAGGED ARRAY
    float ** NewJaggedArray;
    //FILL THE ORIGINAL JAGGED ARRAY WITH RANDOM FLOAT NUMBER
    fill2DArray(OriginalJaggedArray,JaggedArraySize,5);
    //PRINT IT
    printf("\nTHE JAGGED ARRAY FILLED WITH RANDOM NUMBERS IS:\n");
    print2DArray(OriginalJaggedArray,JaggedArraySize,5);
    printf("\n\n");
    //CREATE THE SECOND VERSION OF THE JAGGED ARRAY
    NewJaggedArray= CreateColumnJArray(OriginalJaggedArray,JaggedArraySize,NewJaggedArraySize);
    for(i=0;i<10;i++){
        QuickSort(NewJaggedArray[i],0,NewJaggedArraySize[i]-1);
    }
    OriginalJaggedArray = GetOriginalSortedJA(OriginalJaggedArray,GlobalArray,NewJaggedArray);
    //PRINT IT
    printf("THE NEW JAGGED ARRAY SORTED BY COLUMN FILLED WITH RANDOM NUMBERS IS:\n");
    print2DArray(OriginalJaggedArray,JaggedArraySize,5);
    printf("\n");
    return 0;
}
//RETURN THE SIZE OF THE ARRAY IN TERM OF COLUMN. IT TELLS YOU HOW MANY ELEMENTS ARE IN THE COLUMN OF THE JAGGED ARRAY 
int * ReturnJSize (int *JaggedArraySize){
    int *RowSize = malloc(sizeof(int)*10);
    int i,j,count;
    for(i=0; i<10;i++){
        count=0;
        for(j=0;j<5;j++){
            if(JaggedArraySize[j] >= i+1){
                count++;
            }
        }
        RowSize[i] = count;
    }
    return RowSize;
}
//FUNCTION TO ALLOCATE MEMORY FOR THE JAGGED ARRAY
float **CreateArray(int *size,int SizeArray){
    int i;
    float ** JaggedArray = (float **) malloc((SizeArray+1) * sizeof(float *));
    for(i=0;i<SizeArray;i++){
        JaggedArray[i] = (float *) malloc(size[i] * sizeof(float));
    }
    JaggedArray[SizeArray] = NULL;
    return JaggedArray;
    
}
//FUNCTION THAT FILLS THE JAGGED ARRAY WITH RANDOM FLOAT
void fill2DArray(float** Array,int *Row, int JagSize){
    int i,j;
    for(i=0;i<JagSize;i++){
        for(j=0;j<Row[i];j++){
            Array[i][j] = FLOAT_RAND(1,10);
        }
    }
}
//FUNCTION THAT GENERATE THE RANDOM NUMBERS
float FLOAT_RAND( float min, float max ){
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );      
}
//FUNCTION THAT PRINT THE JAGGED ARRAY
void print2DArray(float** Array,int *Row, int JagSize){
    int i,j;
    for(i=0;i<JagSize;i++){
        for(j=0;j<Row[i];j++){
            printf("%.2f ",Array[i][j]);
        }
        printf("\n");
    }
}
//CREATE A NEW JAGGED ARRAY WITH ALL THE ELMENT THAT ARE THE COLUMN OF THE ORIGINAL JAGGED ARRAY 
float ** CreateColumnJArray(float **Array, int *JaggedArraySize, int *CloanArray){
    int i,j,count;
    float **CloanJag = CreateArray(CloanArray,10);
    for(i=0; i<10;i++){
        count=0;
        for(j=0;j<5;j++){
            if(JaggedArraySize[j] >= i+1){
                CloanJag[i][count] = Array[j][i];
                count++;
            }
        }
    }
    return CloanJag;
}
//FUNCTION THAT DO THE SORT THE ELEMETS USING QUICK SORT
void QuickSort(float JArray[], int start, int end){
    int PartitionIndex,i;
    if(start >= end){
        return;
    }
    PartitionIndex = partition(JArray,start,end);
    QuickSort (JArray,start,PartitionIndex-1);
    QuickSort(JArray,PartitionIndex+1,end);
}
//PARTITION  THE VALUE TO THE LEFT
int partition(float JArray[],int start,int end){
    int i;
    float pivot = JArray[end];
    int pIndex = start;
    for(i=start;i<end;i++){
        if(JArray[i]<= pivot){
            swap(&JArray[i],&JArray[pIndex]);
            pIndex++;
        }
    }
    swap(&JArray[pIndex],&JArray[end]);
    return pIndex;
}
//SWAP TWO ELEMENTS
void swap(float *PreviousValue, float *NextValue){
    float temp = *PreviousValue;
    *PreviousValue = *NextValue;
    *NextValue = temp;
}
//REWRITE THE JAGGED ARRAY BACK TO WHAT IT WAS BEFORE
float ** GetOriginalSortedJA(float **Array, int *JaggedArraySize, float ** ColumnJA){
    int i,j,count;
    for(i=0; i<10;i++){
        count=0;
        for(j=0;j<5;j++){
            if(JaggedArraySize[j] >= i+1){
                Array[j][i] = ColumnJA[i][count];
                count++;
            }
        }
    }
    return Array;
}