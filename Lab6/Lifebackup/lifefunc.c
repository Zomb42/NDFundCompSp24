//lifefunc.c    Derick Shi  
#include "lifefunc.h"




void display (char s[][size], int count){ //simply displays the current main board

    for (int i = 0; i < count+2; i ++){
        for (int j = 0; j< count+2; j++){
            if (i == 0 || i == count+1){ //adds border
                printf("-");
            }
            else{
                if (j == 0|| j == count +1 ){
                    printf("|"); //adds border
                }
                else{
                    printf("%c", s[i-1][j-1]); //prints main board accounting for widths
                }

            }
        
        }
        printf("\n");
    }

}


void place(char s[][size], int count, int add, int x, int y){

    if (add == 1){ //adds a cell to the spot or removes it depending on add value
        s[count - y][x-1] = 'X';
    }
    else{
        s[count - y][x-1] = ' ';
    }

}



void nextsimulation(char mainboard[][size], int count){
//calculates next simulation for the board
    char tempboard[size+2][size+2];
    for (int i = 0; i < count+2; i ++){
//This program first copies the main board to the middle of a clean temporary board that is 42 x 42 to easily deal with the edge cases
        for (int j = 0; j< count+2; j++){
        if (i == 0 || i == count +1){
            tempboard[i][j] = ' ';
        } //adds blank spaces on the edges. 
        else if (j == 0 || j == count + 1) {
            tempboard[i][j] = ' ';    
        }
        else{
            tempboard[i][j] = mainboard[i-1][j-1];
                   
        }   
        
        }
    }

    for (int i = 1; i < count + 1; i++){
        for (int j = 1; j < count + 1; j ++){

            int neighbors = 0; //the program then checks the neighbors for each cell of the tempboard and retursn the value back to the main board. 
            for (int k = i -1; k < i+2; k++){
                for (int p = j - 1; p < j+2; p++){
                    if (k != i || p != j){ //doesn't include itself as a neigbor
                        if (tempboard[k][p] == 'X'){
                            neighbors +=1;
                        }
                    } 
                }
            }
            if (neighbors == 3){
                mainboard[i-1][j-1] = 'X'; //conditions for growth, staying alive, and death
            }
            else if(neighbors == 2 && mainboard[i-1][j-1] == 'X'){
                mainboard[i-1][j-1] = 'X';
            }
            else {

                mainboard[i-1][j-1] = ' ';
            }
        }
    }


}
