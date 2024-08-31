//symbol.c     Derick Shi


#include <stdio.h>
#include <unistd.h>
#include "gfx.h"
#include <math.h>
#include <stdlib.h>

#define SIZE 50  //macro
#define PI 3.14159265

void triangle(int, int); //prototypes function 
void square(int, int);
void polygon (int, int, char);

int main(){

    char c; 
    int x = 400, y = 300; 
    gfx_open(2 * x, 2 * y, "Symbolic Typewriter"); //opens screen

    while(1){
    
    if (gfx_event_waiting()){ //collects input
        c = gfx_wait();
    x = gfx_xpos(); //places x and y pos at mouse
    y = gfx_ypos();
    if (c == 'q'){
        break;//quit
    }
    
    if (c == 1){
        square(x, y);  //draws square
    }
    else if(c < 58 && c > 48){
        polygon(x, y, c); //draws polygon 
    }
    else{
    switch(c){
        case 27:
            gfx_clear(); //clears
        break;
        case 'c':
        //circle
        gfx_color(255,255,255);
        gfx_circle(x, y, SIZE/2); //draws circle

        break;
        case 't': //draws triangle
            triangle(x, y);
        break;
       
        default:
           //Kinda pointless to have one as the user can't see anything until they quit the program
        break;//asks for 
        

    }

    }

    gfx_flush(); //display colors
    }

    }

    return 0;
}

void triangle(int x, int y){ 
    gfx_color(0,255, 0);
    gfx_line(x -SIZE/2, y - SIZE/2, x + SIZE/2 , y - SIZE/2);
    gfx_line(x + SIZE/2, y - SIZE/2, x , y + SIZE/2);
    gfx_line(x, y + SIZE/2, x - SIZE/2 , y - SIZE/2); //draws iso triangle around mouse point
}


void square(int x, int y){
    gfx_color(0,0,255);
    gfx_line(x -SIZE/2, y - SIZE/2, x + SIZE/2 , y - SIZE/2);
    gfx_line(x + SIZE/2, y - SIZE/2, x + SIZE/2 , y + SIZE/2);
    gfx_line(x + SIZE/2, y + SIZE/2, x - SIZE/2 , y + SIZE/2); //draws square around point
    gfx_line(x - SIZE/2, y + SIZE/2, x - SIZE/2 , y - SIZE/2); 

}
void polygon(int x, int y, char s){
    gfx_color(255, 0, 255);

    int numside;
    numside = s - '0'; //gets number from char
 
    for (int i =0; i < numside; i++ ){
            //uses polar coordianates to draw polygon around shape
        gfx_line(SIZE/2 * cos(i* (2 * PI/numside)) + x, SIZE/2 * sin(i* (2 * PI/numside)) + y, SIZE/2 * cos((i+1)* (2 * PI/numside)) + x, SIZE/2 * sin((i+1)* (2* PI/numside)) + y);
    }

}