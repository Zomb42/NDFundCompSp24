//finalgame.c     Derick Shi


#define _GNU_SOURCE
#include <stdio.h>
#include "gfx2.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h> 
#include <math.h>

typedef struct{

XPoint arr[8]; //Makes an L shape with points?? 150 len. 
//arr0 is the far corner, and it goes clockwise??
int direction; // 1- 4, 1 means that one side is the the west sside and one side is to the south side
//2 mans that one side is to the north and one side is to the west. 

int placement;
int xmid, ymid;


} Wall;

typedef struct{

int x, y, xpast, ypast, distance, dx, dy ; 
float direction;
bool exist, alive; //exist is just for the bullet, alive is for the player

} object;

//This is a 1v1 tank shooter game 
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void Wallblock(object *x, Wall y[], int size);
void makebullet(object *x, object *y);
void checkhit (object *x, object *y); //prototype functions


int main(){
    int count, rannum, winner =0; 
    gfx_open(800, 800, "Bouncing Ball");
    srand(time(NULL));
    object p1b1, p2b1, p1b2, p2b2, p1, p2; 
    p1.exist = false, p1.x = 50, p1.y = 50, p1.direction = 1, p1.alive = true;
    p2.exist = false, p2.x= 750, p2.y = 750, p2.direction = 1, p2.alive = true;
    p1b1.exist = false, p1b1.dx = 0, p1b1.dy = 0, p1b2.exist = false, p1b2.dx = 0, p1b2.dy = 0;
    p2b1.exist = false, p2b1.dx = 0, p2b1.dy = 0, p2b2.exist = false, p2b2.dx = 0, p2b2.dy = 0;
    char c; //initializees some variables. A function could be used but since there isn't that many characters, I thought it was uncessary

    const char redwin[8] = "RED WINS";
    const char bluewin[9] = "BLUE WINS";


    Wall barriers[7]; //going to change the amount of wall barriers 
    int markers[16] = {0};
    while (count <7){
        rannum = rand() % 15;
        if (markers[rannum] == 0){
            barriers[count].placement = rannum;
            markers[rannum] = 1;
            count +=1;
        }


    }
    for (int i = 0; i< 7; i++){
        rannum = rand()% 4  + 1;
        barriers[i].direction = rannum;
        

        switch (barriers[i].placement % 4){
            case 1:
            barriers[i].xmid = 175; 
            break;

            case 2:
            barriers[i].xmid = 325; 
            break;
            case 3:
            barriers[i].xmid = 475; 
            break;
            case 0:
            barriers[i].xmid = 625; 
            break;

        }
        switch (barriers[i].placement/4){
            case 0:
                barriers[i].ymid = 175; 
            break;
            case 1:
            barriers[i].ymid = 325; 
            break;
            case 2:
            barriers[i].ymid = 475; 
            break;
            case 3:
            barriers[i].ymid = 625; 
            break;


        }
        
        switch(barriers[i].direction){
            case 1:

            barriers[i].arr[0].x = barriers[i].xmid -75; 
            barriers[i].arr[0].y = barriers[i].ymid + 75; 
            
            barriers[i].arr[1].x = barriers[i].xmid -75; 
            barriers[i].arr[1].y = barriers[i].ymid - 75;

            barriers[i].arr[2].x = barriers[i].xmid -65; 
            barriers[i].arr[2].y = barriers[i].ymid - 75;

            barriers[i].arr[3].x = barriers[i].xmid -65; 
            barriers[i].arr[3].y = barriers[i].ymid + 65;

            barriers[i].arr[4].x = barriers[i].xmid +75; 
            barriers[i].arr[4].y = barriers[i].ymid + 65;

            barriers[i].arr[5].x = barriers[i].xmid + 75; 
            barriers[i].arr[5].y = barriers[i].ymid + 75;
            break;
            case 2:
            
            barriers[i].arr[0].x = barriers[i].xmid - 75; 
            barriers[i].arr[0].y = barriers[i].ymid - 75;  // 
            
            barriers[i].arr[1].x = barriers[i].xmid + 75;  //
            barriers[i].arr[1].y = barriers[i].ymid - 75;

            barriers[i].arr[2].x = barriers[i].xmid + 75; 
            barriers[i].arr[2].y = barriers[i].ymid - 65;

            barriers[i].arr[3].x = barriers[i].xmid - 65; 
            barriers[i].arr[3].y = barriers[i].ymid -  65;

            barriers[i].arr[4].x = barriers[i].xmid - 65; 
            barriers[i].arr[4].y = barriers[i].ymid + 75;

            barriers[i].arr[5].x = barriers[i].xmid - 75; 
            barriers[i].arr[5].y = barriers[i].ymid + 75;


            break;
            case 3:
            barriers[i].arr[0].x = barriers[i].xmid + 75; 
            barriers[i].arr[0].y = barriers[i].ymid - 75;  // 
            
            barriers[i].arr[1].x = barriers[i].xmid + 75;  //
            barriers[i].arr[1].y = barriers[i].ymid + 75;

            barriers[i].arr[2].x = barriers[i].xmid + 65; 
            barriers[i].arr[2].y = barriers[i].ymid + 75;

            barriers[i].arr[3].x = barriers[i].xmid + 65; 
            barriers[i].arr[3].y = barriers[i].ymid -  65;

            barriers[i].arr[4].x = barriers[i].xmid - 75; 
            barriers[i].arr[4].y = barriers[i].ymid - 65;

            barriers[i].arr[5].x = barriers[i].xmid - 75; 
            barriers[i].arr[5].y = barriers[i].ymid - 75;

            break;
            case 4:
            barriers[i].arr[0].x = barriers[i].xmid + 75; 
            barriers[i].arr[0].y = barriers[i].ymid + 75;  // 
            
            barriers[i].arr[1].x = barriers[i].xmid - 75;  //
            barriers[i].arr[1].y = barriers[i].ymid + 75;

            barriers[i].arr[2].x = barriers[i].xmid - 75; 
            barriers[i].arr[2].y = barriers[i].ymid + 65;

            barriers[i].arr[3].x = barriers[i].xmid + 65; 
            barriers[i].arr[3].y = barriers[i].ymid +  65;

            barriers[i].arr[4].x = barriers[i].xmid + 65; 
            barriers[i].arr[4].y = barriers[i].ymid - 75;

            barriers[i].arr[5].x = barriers[i].xmid + 75; 
            barriers[i].arr[5].y = barriers[i].ymid - 75;

            break;



        }


        barriers[i].arr[6].x = (barriers[i].arr[0].x + barriers[i].arr[1].x + barriers[i].arr[2].x + barriers[i].arr[3].x)/4;
        barriers[i].arr[6].y = (barriers[i].arr[0].y + barriers[i].arr[1].y + barriers[i].arr[2].y + barriers[i].arr[3].y)/4;
        barriers[i].arr[7].x = (barriers[i].arr[0].x + barriers[i].arr[4].x + barriers[i].arr[5].x + barriers[i].arr[3].x)/4;
        barriers[i].arr[7].y = (barriers[i].arr[0].y + barriers[i].arr[4].y + barriers[i].arr[5].y + barriers[i].arr[3].y)/4;
        


    }

    
    bool loop = true;
    float nouse = 1, directionx = 90, directiony = 50; 


while(loop){
    //draws the main characters.

    if (winner != 1){
        gfx_clear(); 
    }
    gfx_color(255,0,0);

    if (p1.alive == true){
        gfx_fill_circle(p1.x, p1.y, 40);}
    else{
        winner = 1;
        gfx_clear_color(255, 255, 255);
        gfx_text(400, 400, "BLUE WINS");
        usleep(800000);


    }

    if (p1b1.exist == true){
        p1b1.x += p1b1.dx;
        p1b1.y += p1b1.dy;
        gfx_fill_circle(p1b1.x , p1b1.y, 10);
    }
    if (p1b2.exist == true){
        p1b2.x += p1b2.dx;
        p1b2.y += p1b2.dy;
        gfx_fill_circle(p1b2.x , p1b2.y, 10);
    }

    gfx_color(0, 0, 255);
    if (p2.alive == true){
        gfx_fill_circle(p2.x, p2.y, 40);}
    else{
        winner = 1;
        gfx_clear_color(255, 255, 255);
        gfx_text(400, 400, "RED WINS");
        usleep(800000);
    }
    if (p2b1.exist == true){
        p2b1.x += p2b1.dx;
        p2b1.y += p2b1.dy;
        gfx_fill_circle(p2b1.x , p2b1.y , 10);
    }
    if (p2b2.exist == true){
        p2b2.x += p2b2.dx;
        p2b2.y += p2b2.dy;
        gfx_fill_circle(p2b2.x , p2b2.y , 10);
    }


    //draws the borders
     gfx_color(255, 255, 255);
     for (int i = 0; i < 7; i ++){
         gfx_fill_polygon(barriers[i].arr, 6);      
     }

    if (gfx_event_waiting()) {
      c = gfx_wait(); //quits if early
        p1.xpast = p1.x;
        p1.ypast = p1.y;
        p2.xpast = p2.x;
        p2.ypast = p2.y;
        switch(c){
            case 'q':
                loop = false;
            break;


            case 'w': //turn this into a function later
                if (p1.y >= 50){
                    p1.direction = 1;
                    p1.y -= 20;
                }
            break;
            case 'a':
                if (p1.x >= 50 ){
                    p1.direction  = 2;
                    p1.x -= 20;
                }
            break;
            case 's':
                if (p1.y <= 750){
                    p1.direction = 3;
                    p1.y+= 20;
                }
            break;
            case 'd':
                if (p1.x <= 750 ){
                    p1.x += 20;
                    p1.direction = 4; 
                }
            break;


            case 'e':
                if (p1b1.exist == false){
                    makebullet(&p1b1, &p1);
                }
                else{
                    if (p1b2.exist == false){
                        makebullet(&p1b2, &p1);
                    }
                }
                
            break;
            case 'o': //turn this into a function later
                if (p2.y >= 50){
                    p2.direction = 1;
                    p2.y -= 20;
                }
            break;
            case 'k':
                if (p2.x >= 50 ){
                    p2.direction = 2;
                    p2.x -= 20;
                }
            break;
            case 'l':
                if (p2.y <= 750){
                    p2.direction = 3; 
                    p2.y+= 20;
                }
            break;
            case ';':
                if (p2.x <= 750 ){
                    p2.x += 20;
                    p2.direction = 4; 
                }
            break;
            case 'p':
                if (p2b1.exist == false){
                    makebullet(&p2b1, &p2);
                }
                else{
                    if (p2b2.exist == false){
                        makebullet(&p2b2, &p2);
                    }
                }

            break;
            default:

            

            break;
            

            }

    }


    
    Wallblock(&p1, barriers, 7);
    Wallblock(&p2, barriers, 7);
    Wallblock(&p1b1, barriers, 7);
    Wallblock(&p2b1, barriers,7);
    Wallblock(&p1b2, barriers, 7);
    Wallblock(&p2b2, barriers,7);
    checkhit(&p1b1, &p2);
    checkhit(&p2b1, &p1);
    checkhit(&p1b2, &p2);
    checkhit(&p2b2, &p1);


    gfx_flush();
    usleep(80000);

    // if (winner == 1){
    //     gfx_clear();
    //     gfx_text(400, 50, redwin);
    // }
    // else if (winner == 2){
    //     gfx_text(400, 50, bluewin);
    // }

    }

    

}


void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 ) //functions used for other functions
{
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x1,y1);
}

void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
  gfx_line(x1,y1,x2,y2);
  gfx_line(x2,y2,x3,y3);
  gfx_line(x3,y3,x4,y4);
  gfx_line(x4, y4, x1, y1);


}




void Wallblock(object *xt, Wall y[], int size){
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 8; j++){
            xt->distance = sqrt(pow((y[i].arr[j].x - xt->x),2) + pow((y[i].arr[j].y - xt->y),2));

            // if (j == 6 || j == 7){
            //     p1distance -=3;
            //     p2distance -=3;
            // }
            
            if (xt->distance < 45 ){
                xt->x = xt->xpast;
                xt->y = xt->ypast;
                xt->exist = false;
            }
        }
    

    }
    if (xt->x > 800 || xt->x < 0 || xt->y > 800 || xt-> y < 0){\
        xt->exist = false;
    }
}



void makebullet(object *x, object *y){ //spawns in a bullet in a certain direciton based on the last moved direction of the player
    x->exist = true;
    x->x = y->x;
    x->y = y->y;
    x->xpast = y->xpast;
    x->ypast = y->ypast;

    int dir = y->direction;
    switch (dir){

        case 1:
            x->dx = 0;
            x->dy = -40;
        break;
        case 2:
            x->dx = -40;
            x->dy = 0;
        break;
        case 3:

            x->dx = 0;
            x->dy = 40;
        break;
        case 4:
            x->dx = 40;
            x->dy = 0;
        break;


    }
}


void checkhit(object *x, object *y){ //checks if a bullet hits a character
    if (x->exist == true){
    x->distance = sqrt( pow(y->y - x->y, 2) + pow(y->x - x->x, 2));
    
    if (x->distance <50){
        y->alive = false;
    }
    }
}
