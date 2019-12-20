#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 256

void sort(float array[], int len);
void scramble(float array[], int len);
void concatinate(float array1[], int len1, float array2, int len2);

int globalVar1;
float globalVar2;

int main(){
	int i;
	
	srand(time(NULL)); //seed rand
	
	int array1Length = rand()%25 + 50; //randomize the length of array 1
	int array2Length = rand()%25 + 50; //randomize the length of array 2
	int array3Length = array2Length + array1Length; //set array 3 length to the sum of both arrays
	
	float array1[array1Length]; //initialize array 1 to an array of floats of random length
	float array2[array2Length]; //initialize array 2 to an array of floats of random length
	float array3[array3Length]; //initialize array 3 to an array of floats.
	
	array1[0] = (rand()%100)/10.0; //sets the first value of array 1
	array2[0] = (rand()%100)/10.0; //sets the first value of array 2
	
	for(i=1; i<array1Length; i++){array1[i] = (rand()%100)/10.0+array1[i-1];} //fills array 1 with random values (ascending, no duplicates)
	for(i=1; i<array2Length; i++){array2[i] = (rand()%100)/10.0+array2[i-1];} //fills array 2 with random values (ascending, no duplicates)
	scramble(array1, array1Length); //scrambles array 1 so the values aren't sorted
	scramble(array2, array2Length); //scrambles array 2 so the values aren't sorted
	
	printf("\n\n");
	for(i=0; i<array1Length; i++){printf("%.1f ", array1[i]);}
	
	sort(array1, array1Length); //sorts array 1 so the values are in ascending order
	sort(array2, array2Length); //sorts array 2 so the values are in ascending order
	
	printf("\n""\n");
	for(i=0; i<array1Length; i++){
		printf("%.1f ", array1[i]);
	}
	return 0;
}

void sort(float array[], int len){ //insertion sort algorithm
	int i,j; float tmp;for(i=1; i<len; i++){
		tmp = array[i];
		for(j=i-1; j>=0; j--){
			if(tmp<array[j]){
				array[j+1] = array[j];
				if(j==0){
					array[0] = tmp;
					break;
				}
			}else{
				array[j+1] = tmp;
				break;
			}
		}
	}
}




void scramble(float array[], int len){
	int i,j,k ;
	float tmp ;
	for(i=0; i<len*2; i++) {
		j=rand()%len ;
		k=rand()%len ;
		tmp = array[j] ;
		array[j] = array[k] ;
		array[k] = tmp ;
	}
}

void concatinate(float array1[], int len1, float array2, int len2){}