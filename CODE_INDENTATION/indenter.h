#include <stdio.h>
int indenter(const char* path){
	//LETS MODIFY INTO THE PATH
	//FIRST LETS COUNT HOW MANY CHARACTED
	int c_value =0;
	//DO A WHILE LOOP THAT IS GOING TO COUNT TEH PATH NAME
	while (path[c_value] != '.') {c_value++;}
	//CREATE A CHARACTER BUFFER 
	char buffer[128];
	//PRINT INTO THE BUFFER
	sprintf(buffer, "%.*s_indented.c",c_value,path);
	//OPEN THE INPUT FILE TO READ FROM IT
	FILE * inputFile = fopen(path,"r");
	if(!inputFile){
	  printf("The file does not exist\n");
		return 0;
	}
	//CREATE A CHARACTER VARIABLE
	char c;
	//CREATE A VARIABLE THAT COUNTS THE EXTRA SPACES
	int LastSpaces =0;
	//COUNT IF THERE IS MORE THAN 2 NEW LINE
	int newLine =0;
	//CREATE A COUNTER FOR THE BRACKETS
	int bracket =0;
	int i;
	//CREATE THE OUTPUT FILE
	FILE * outputFile = fopen(buffer, "w");
	//LETS START READING FROM THE FILE
	while ((c = fgetc(inputFile))!= EOF){
		//CREATE A SWITCH STATEMENT THAT TAKES CARE OF CHARACTER
		switch(c){
	//IF IT IS A TAB YOU WANT GET RID OF THE EXTRA SPACES OR EXTRA TAB
			case '\t':
			case ' ':{
				if(!LastSpaces){
					fputc(' ',outputFile);}
				LastSpaces = 1;
				break;}
	//IF IT IS A NEW LINE YOU WANT TO PRINT THE NEW LINE
			case '\n':{LastSpaces =1;
					if(!newLine){
						fputc('\n', outputFile);
						for (i =0;i<bracket;i++){
							fputc('\t',outputFile);
						}
					}
					break;
				}
	//IF IT IS A OPENING BRCAES INCREMENT THE NUMBER OF TAB 
			case '{': {
				fputc('{', outputFile);
				bracket ++; break;}
	//IF IT IS A CLOSING BRACES DRECREMENT AND SAVE THE LAST CHARACTER
			case '}':{
				if(LastSpaces){
					fseek(outputFile,-1,SEEK_CUR);
				}
				fputc('}', outputFile);
				bracket--; break;}
	//PRINT THE CHARACTER
			default: {fputc(c,outputFile);
				LastSpaces =0;}

	
		}
	}
}
