/*
NAME: GUY MARVENS CASENEUVE
STARTING DATE: 11/08/19
ASSIGNMENT: PROBLEM 2
*/
#include <stdio.h>
static int counter;
int Visited (int vist[], int cities);
int PrintAllPath(int Graph[17][17],int start, int end, int visited[], int Distance);
int main (void){
    int i,Distance =0;
    int Visited [17];
    int check;
    int startCity, endCity;
    for(i=0;i<17;i++){
        Visited[i] = -1;
    }
    printf("Welcome to your GPS manual. This is the list of cities that we provide:\n\n");
    printf("0-Cherbourg\n");
    printf("1-Brest\n");
    printf("2-Nantes\n");
    printf("3-San Sebastian\n");
    printf("4-Madrid\n");
    printf("5-Barcelona\n");
    printf("6-Nice\n");
    printf("7-Gen.\n");
    printf("8-Milan\n");
    printf("9-Genoa\n");
    printf("10-Rome\n");
    printf("11-Flor.\n");
    printf("12-Venice\n");
    printf("13-Mun\n");
    printf("14-Frank\n");
    printf("15-Zurich\n");
    printf("16-Paris\n\n");
    printf("Please provide the city you are by entering the number associated with it:\n");
    scanf("%d",&startCity);
    printf("Please provide the city you want to go by the number associated with it:\n");
    scanf("%d",&endCity);
    //THE GRAPH OF MY FUNCTION
    int Graph [17][17] = {
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	55},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100},
        {0,	0,	0,	100,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	80},
        {0,	0,	100,	0,	75,	70,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	110},
        {0,	0,	0,	75,	0,	120,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	70,	120,	0,	130,	125,	0,	0,	0,	0,	0,	0,	0,	0,	140},
        {0,	0,	0,	0,	0,	130,	0,	110,	45,	35,	0,	0,	0,	0,	0,	0,	125},
        {0,	0,	0,	0,	0,	125,	110,	0,	100,	0,	0,	0,	0,	0,	0,	90,	125},
        {0,	0,	0,	0,	0,	0,	45,	100,	0,	20,	0,	55,	40,	0,	0,	80,	0},
        {0,	0,	0,	0,	0,	0,	35,	0,	0,	0,	65,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	65,	0,	50,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	55,	0,	50,	0,	50,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	40,	0,	0,	50,	0,	100,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	100,	0,	110,	90,	155},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	110,	0,	125,	145},
        {0,	0,	0,	0,	0,	0,	0,	90,	80,	0,	0,	0,	0,	90,	125,	0,	150},
        {55,	100,	80,	110,	0,	140,	125,	125,	0,	0,	0,	0,	0,	155,	145,	150,	0}
    };
    check = PrintAllPath(Graph,startCity,endCity,Visited,Distance);
    if(counter == 0){
        printf("I am sorry, but there is no path to go from ");
        switch(startCity){
                case 0:printf("Cherbourg");
                    break;
                case 1:printf("Brest");
                    break;
                case 2:printf("Nantes");
                    break;
                case 3:printf("San Sebastian");
                    break;
                case 4:printf("Madrid");
                    break;
                case 5:printf("Barcelona");
                    break;
                case 6:printf("Nice");
                    break;
                case 7:printf("Gen.");
                    break;
                case 8:printf("Milan");
                    break;
                case 9:printf("Genoa");
                    break;
                case 10:printf("Rome");
                    break;
                case 11:printf("Flor.");
                    break;
                case 12:printf("Venice");
                    break;
                case 13:printf("Mun");
                    break;
                case 14:printf("Frank");
                    break;
                case 15:printf("Zurich");
                    break;
                case 16:printf("Paris");
                    break;
        }
        printf(" to ");
        switch(endCity){
                case 0:printf("Cherbourg.");
                    break;
                case 1:printf("Brest.");
                    break;
                case 2:printf("Nantes.");
                    break;
                case 3:printf("San Sebastian.");
                    break;
                case 4:printf("Madrid.");
                    break;
                case 5:printf("Barcelona.");
                    break;
                case 6:printf("Nice.");
                    break;
                case 7:printf("Gen.");
                    break;
                case 8:printf("Milan.");
                    break;
                case 9:printf("Genoa.");
                    break;
                case 10:printf("Rome.");
                    break;
                case 11:printf("Flor.");
                    break;
                case 12:printf("Venice.");
                    break;
                case 13:printf("Mun.");
                    break;
                case 14:printf("Frank.");
                    break;
                case 15:printf("Zurich.");
                    break;
                case 16:printf("Paris.");
                    break;
        }
        printf("\n");
    }
    printf("\nWe thank you for taking part of our manual GPS.\n");
    return 0;
}
int PrintAllPath(int Graph[17][17],int start, int end, int visited[], int Distance){
    //N.B: START = i; END = j;
    int i,j=0,l=0,count;
    //IF YOU REACH DESTINATION 
    if(start == end){
        counter++;
        if(counter == 1){
            printf("\nThese are all the path that you can travel to make your destination:\n");
        }
        for(l=0;visited[l]!=-1&&l<17;l++){
            //PRINT THE LAST CITY
            switch(visited[l]){
                case 0:printf("Cherbourg -> ");
                    break;
                case 1:printf("Brest -> ");
                    break;
                case 2:printf("Nantes -> ");
                    break;
                case 3:printf("San Sebastian -> ");
                    break;
                case 4:printf("Madrid  -> ");
                    break;
                case 5:printf("Barcelona -> ");
                    break;
                case 6:printf("Nice -> ");
                    break;
                case 7:printf("Gen. -> ");
                    break;
                case 8:printf("Milan -> ");
                    break;
                case 9:printf("Genoa -> ");
                    break;
                case 10:printf("Rome -> ");
                    break;
                case 11:printf("Flor. -> ");
                    break;
                case 12:printf("Venice -> ");
                    break;
                case 13:printf("Mun -> ");
                    break;
                case 14:printf("Frank -> ");
                    break;
                case 15:printf("Zurich -> ");
                    break;
                case 16:printf("Paris -> ");
                    break;
                default:;
            }
        }
        //PRINT THE LAST CITY
         switch(end){
                case 0:printf("Cherbourg");
                    break;
                case 1:printf("Brest");
                    break;
                case 2:printf("Nantes");
                    break;
                case 3:printf("San Sebastian");
                    break;
                case 4:printf("Madrid");
                    break;
                case 5:printf("Barcelona");
                    break;
                case 6:printf("Nice");
                    break;
                case 7:printf("Gen.");
                    break;
                case 8:printf("Milan");
                    break;
                case 9:printf("Genoa");
                    break;
                case 10:printf("Rome");
                    break;
                case 11:printf("Flor.");
                    break;
                case 12:printf("Venice");
                    break;
                case 13:printf("Mun");
                    break;
                case 14:printf("Frank");
                    break;
                case 15:printf("Zurich");
                    break;
                case 16:printf("Paris");
                    break;
                default:;
            }
        printf(". The distance is %d miles.\n",Distance);
        return 0;
    }
    while (visited[j] != -1){
            j++;
    }
    for(i=0;i<17;i++){
        //IF THERE IS A DISTANCE BETWEEN TWO PLACES THAT MEANS THERE CONNECTED
        if(Graph[start][i] && !(Visited(visited,i))){
            //UPDATE THE START
            visited[j]=start;
            //DO THE RECURSICE CALL
            PrintAllPath(Graph,i,end,visited, Distance + Graph[start][i]);
        }
    }
   visited[j]=-1;
    return 0;
}
//ARRAY TO CHECK IF MY CITY WAS VISITED
int Visited (int vist[], int cities){
    int i;
    for (i=0;i<17;i++){
        if(vist[i] == cities){
            return 1;
        }
    }
        return 0;
}