//funanim.c      Derick Shi
#include <stdio.h>
#include "gfx.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.141592
void gun (int, int);

int main(){

  srand(time(NULL));
  int wid = 800, ht = 600;
  int radius = 20;
  gfx_open(wid, ht, "funanim");
  float xc = 200, yc = 300;
  char c = 0;
  float dx = 2;
  float dy = 2;
  float rotate =0; 
  int key = 0; 

while (1){

    gfx_clear();
    gfx_circle(600, 300, 100);
    gfx_circle(550, 250, 25);
    gfx_circle(650, 250, 25);
    gfx_line(550, 350, 650, 350);
    for (int i =0; i < 5; i++ ){
            //uses polar coordianates to draw pentagron around point
    gfx_line(25 * cos(i* (2 * PI/5) + rotate) + xc + 20 * rotate, 25 * sin(i* (2 * PI/5) + rotate) + yc + 10 * sin(rotate), 25 * cos((i+1)* (2 * PI/5) + rotate) + xc + 20* rotate, 25 * sin((i+1)* (2* PI/5) + rotate) + yc+ 10 * sin(rotate) );
    } //pentagon with sin curve 
    rotate += 0.1;
    if (key == 1){
      gun(xc, yc); //creates a gun in the area that "shoots" the pentagon
    }
    gfx_flush();
    usleep(60000);

  if(gfx_event_waiting()){
    c = gfx_wait();
  if (c == 'q') {
    break;
  }
  if (c == 1){
      key = 1;
      rotate = 0;
      xc = gfx_xpos();
      yc = gfx_ypos();
    }

  }
    
}

    
}

void gun (int xc, int yc){
    xc -= 50;
    yc += 50; //makes a "gun"
    gfx_line(xc-25, yc+25, xc + 25, yc + 25);
    gfx_line(xc-25, yc+25, xc - 25, yc - 50);
    gfx_line(xc+25, yc+25, xc + 25, yc - 25);
    gfx_line(xc-25, yc- 50, xc + 25, yc -50);
    gfx_line(xc+25, yc-25, xc + 50, yc - 25);
    gfx_line(xc+25, yc- 50 , xc + 50, yc - 50);
    gfx_line(xc + 50, yc - 25, xc + 50, yc - 50);


}