//bounce.c      Derick Shi
#include <stdio.h>
#include "gfx.h"
#include <unistd.h>
#include <stdlib.h> //prototypes functions
#include <time.h>
#include <math.h>

void click(float *dx, float *dy, float  *xc, float *yc);

int main()
{
  srand(time(NULL));
  int wid = 800, ht = 600;
  int radius = 20;
  gfx_open(wid, ht, "Bouncing Ball");
  float xc = 400, yc = 300;
  char c = 0; //opens screen
  float dx = 2;
  float dy = 2;

  while(1) {
    if (gfx_event_waiting()) {
      c = gfx_wait(); //quits if early
      if (c == 'q'){
        break;
      }
    if (c == 1){
      click(&dx, &dy, &xc, &yc);
        
      }
    }
    gfx_clear();
    gfx_circle(xc, yc, radius);
    gfx_flush();
    usleep(30000);
    xc += dx;
    yc += dy;
        // detect collision with the walls
    if (xc + radius >= wid || xc - radius <= 0) {
        dx = -dx;
    }
    if (yc + radius >= ht || yc - radius <= 0) {
          dy = -dy; 
      }
    


    }
  return 0;
}

void click(float *dx, float *dy, float *xc, float *yc){
        *dx = (rand()%80 / 10) - 4 ; //sets random speed
        *dy = (rand()%80 / 10) - 4 ;
        *xc = gfx_xpos(); //places x and y pos at mouse
        *yc = gfx_ypos();
}


