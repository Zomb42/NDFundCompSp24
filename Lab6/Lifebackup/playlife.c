//playlife.c     Derick Shi

#include <stdio.h>
#include "lifefunc.h"

int main(int argc, char *argv[]) {

    struct timespec start, end = {0, 200000000};  //makes it so there is a 0.2 second delay for simulation.
    //Apparently usleep is bad practice. 


    int count = size;
    int count1 = size; //size parameters to feed into functions
    char mainboard[size][size] = {};
    char tempboard [size][size] = {};
    for (int i = 0; i < size; i ++){
        for (int j = 0; j< size; j++){
            mainboard[i][j] = ' ';
        }
    }
    char response = 'b';
    int x, y, add, time = 0;

if (argc == 1){ //no arguments opens up the interactive mode. 

while (response != 'q'){//menu system 
    system("clear");
    display(mainboard, count); //display. I made them each separate lines for greater readability. 
    printf("Welcome to a simulation of Conway's Game of Life. Type and enter the followng character to do its action. \nFor this game, the bottom left most empty square is has coordinate 1 1 while the top right square has coordinates 40 40 \n");
    printf("a followed by two integer (no comma): to a add a live cell. Please enter x value then y value\n");
    printf("r followed by two integers:  to remove a cell from those coordinates\n");
    printf("n: to advance the simulation to the next phase by applying the rules of this game\n");
    printf("q: to quit the game\n");
    printf("p :  play the game continuously. You can press control C to stop the program\n");
    scanf("%c", &response);
    switch(response){
        case ('a'):
            scanf("%d %d", &x, &y); //scans integers
            if (x > 40 || x < 1 || y > 40 || y < 1){
            goto badinput; //prevents weird input from happening. 
            }
            add  = 1;
            place(mainboard, count, add, x , y);
        break;
        case ('r'):
            scanf("%d %d", &x, &y); 
            if (x > 40 || x < 1 || y > 40 || y < 1){
                goto badinput;
            }
            add =0;
            place(mainboard, count, add, x , y); //places or removes a dot

        break;
            case ('n'): //demonstrates next simulation 
            nextsimulation(mainboard, count);
            break;
        case ('q'):
            printf("Have a nice day\n");
        break;
        case ('p'):
            while (1){
                nextsimulation(mainboard, count);
                system("clear");
                display(mainboard, count); //infinite simulation
                printf("\nRemember to press control C to stop the simulation\n");
                if (nanosleep(&end, &start) == -1) { //time delay 
                printf("An error has occurred for the time delay");
                }
            }
        break;
        default:
        badinput:



        break;
    }

    
    
}


}
else if (argc == 2){ //if they added some txt file after the executable
    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL){ //display error
        printf("Error opening file.\n");
    }
    while (fscanf(file, " %c %d %d", &response, &x, &y) == 3) {
        // Adds the points from the file
        add  = 1;
        x +=1; 
        y +=1;
        place(mainboard, count, add, x , y);
    }
    display(mainboard, count);//Lets them first see the board placement before continuing the simulation
    printf("Press enter to start the simulation");
    getchar();
    while (1){
            nextsimulation(mainboard, count);
            system("clear");
            display(mainboard, count); //
            printf("\nRemember to press control C to stop the simulation\n");
            if (nanosleep(&end, &start) == -1) {
            printf("An error has occurred for the time delay");
            }
    }


}
else{ //too many arguements

printf("INVALID INPUT please try again\n");

}

}
