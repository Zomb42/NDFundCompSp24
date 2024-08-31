//usastates.c    Derick Shi

#include "statesfunc.h"

int main(){

char filename[30];
 
int numstates;

    State st_array[maxstates];

    printf("Name of text file to open "); //reads textfile name
    fgets(filename, 30, stdin);
    
    if (filename[strlen(filename) - 1] == '\n') {
        filename[strlen(filename) - 1] = '\0'; //gets rid of newline character
    }

    
    FILE *file = fopen(filename, "r"); //file pointer

    if (file == NULL){
        printf("Error opening file.\n"); //can't open file
    }
    else{
        numstates = readstates(file, st_array); //collects data
        
        menu(st_array, numstates); //displays menu

    }




}
