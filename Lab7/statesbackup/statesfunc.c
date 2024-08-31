//statesfunc.c      Derick Shi

#include "statesfunc.h"



int readstates(FILE* file, State arr[]){

    int i = 0;
    char oneline[100];
    
    while (1){
        char oneline[100];
        fgets(oneline, 100, file); //collects data. 
        if (feof(file)){
            break;
        }
        strcpy(arr[i].abbre, strtok(oneline, ","));
        strcpy(arr[i].name, strtok(NULL, ","));
        strcpy(arr[i].capital, strtok(NULL, ","));
        arr[i].year = atoi(strtok(NULL, "\n"));

        i+= 1;

    }
    
    return i;
}

void menu(State arr[], int numstates){

int response = 0; 
int year;
char cresp;
char sresp[20];


    while (response != 6){ //menu section
        printf("\n------------------------------\n");
        printf("Type and enter the following numbers to do an action: \n");
        printf("1 to print out all of the information \n");
        printf("2 to print out the states that joined after certain year \n");
        printf("3 to print out the states with a specific letter in their abbreviation:\n");
        printf("4 to list a state's capital based on its abbreviation or name\n");
        printf("5 to list the states that were founded in a specific year\n");
        printf("6 to quit the program ");

    
    scanf("%d", &response);
    switch(response){ //switch case for menu
        case 1:
        printeverything(arr, numstates);
        break;

        case 2:
        printf("\nAfter what year should the state be founded? ");
        scanf("%d", &year);
        printyear(arr, numstates, year);
        break;


        case 3:
        printf("\nWhat character should the abbreviation contain? ");
        getchar();
        scanf("%c", &cresp);
        printabbre(arr, numstates, cresp);
        break;

        case 4:
        getchar();
        printf("\nWhat state name or state abbreviation is this capital in? ");
        
        fgets(sresp, 20, stdin);
        if (sresp[strlen(sresp) - 1] == '\n') {
        sresp[strlen(sresp) - 1] = '\0'; //gets rid of newline character
        }        
        printcapital(arr, numstates, sresp, strlen(sresp));
        break;
        case 5:
        printf("\nWhat year do you want to look at? ");
        scanf("%d", &year);
        yearjoin(arr, numstates, year);
        break;
        case 6:
            printf("Have a nice day\n");
        break;

        default:
            printf("Your response was invalid. Please try again\n");
    } 
    }
}

void printeverything(State arr[], int count){
    for (int i = 0; i < count; i++){
        printf("%s %s %s %d\n", arr[i].abbre, arr[i].name, arr[i].capital, arr[i].year);
    } //prints everything as recorded

}
void printyear(State arr[], int count, int postyear){

    for (int i = 0; i < count; i++){
        if (arr[i].year > postyear){ //prints information only if the year is after input year
        printf("%s %d\n",  arr[i].name, arr[i].year);
        }
    }

}


void printabbre(State arr[], int count, char c){
    
    printf("\n");
    for (int i = 0; i < count; i++){
        int  flag = 0;
        for (int j = 0; j < 20; j++){
            if (arr[i].abbre[j] == c || arr[i].name[j] == c ){
                flag = 1;
                break;
            }
        }
        if (flag == 1){
        printf("%s %s\n", arr[i].abbre, arr[i].name );
        }
        
    }


}
void printcapital(State arr[], int count, char input[], int len){

    for (int i = 0; i < count; i++){
        if (strcmp(input, arr[i].name) == 0 || strcmp(input, arr[i].abbre ) == 0){
        printf("%s \n",  arr[i].capital);
        }
    }   



}

void yearjoin(State arr[], int count, int year){
    int exists =0;
    for (int i = 0; i < count; i++){
        if (arr[i].year == year){
        exists = 1;
        printf("%s %d\n",  arr[i].name, arr[i].year);
        }
    }
    if (exists == 0){
        printf("No states were founded in this year\n ");
    }

}