//fractals.c       Derick Shi
#include "gfx.h"
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


// function prototypes
void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );
void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 );
void drawSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void spiralsquare(double, double, double, int, int);
void shrinkSquares(int, int, int); //protoypes functions
void circlelace(int, int, int);
void snowflake(int, int, int);
void tree(int, int, int, double);
void fern(int, int, int, double);
void spiralOfSpiral(int, int, double, double);
#define PI 3.14159265358979323846
int main() 
{
  char c;
  bool loop = true;

  gfx_open(700, 700, "Fractals Assignment");

  while (loop) {
    c = gfx_wait(); //switch case to manage squares 
    gfx_clear();

    switch (c) {
      case '1': // Sierpinski Triangle   
        
        sierpinski(150, 150, 450, 150, 300, 450);
        break;
      case '2': // Shrinking Squares  
        shrinkSquares(350, 350, 300);
        
        break;
      
      case '3': 
        spiralsquare(0, 1, 1, 350, 350);
        break;
      case '4': 
      
        circlelace(350, 350, 200);
        break;
      case '5': 
     
        snowflake(350, 350, 200);
        break;
      case '6': 
    
        tree(350, 690, 150, PI/2);
        break;
      case '7': 
     
        fern(350, 690, 450, PI/2);
        break;
      case '8': // Spiral of Spirals 
     
        spiralOfSpiral(350, 350, 400, 0);
        break;
      case 'q':
        loop = false; //quits program
      default:
       
        break;
    }
  }

 

  return 0;
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case. 
   if( abs(x2-x1) < 5 ) return;

   // Draw the triangle
   drawTriangle( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
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



void shrinkSquares(int xcenter, int ycenter, int len) {
    // Calculate the coordinates of the corners of the large square
    int halfSide = len / 2;
    int x1 = xcenter - halfSide;
    int y1 = ycenter - halfSide;
    int x2 = xcenter + halfSide;
    int y2 = ycenter - halfSide;
    int x3 = xcenter + halfSide;
    int y3 = ycenter + halfSide;
    int x4 = xcenter - halfSide;
    int y4 = ycenter + halfSide;

    // Draw the large square
    drawSquare(x1, y1, x2, y2, x3, y3, x4, y4);

    // Base case: stop recursion 
    if (len <= 3) return;
    
    int newSide = len * 0.45;


    // Recursively draw smaller squares at the corners of the large square
    shrinkSquares(x1,y1, newSide); // Top-left corner
    shrinkSquares(x2, y2, newSide); // Top-right corner
    shrinkSquares(x3 , y3, newSide); // Bottom-right corner
    shrinkSquares(x4, y4, newSide); // Bottom-left corner
}

void spiralsquare(double degree, double halfside, double radius, int xcenter, int ycenter){
  
  if (halfside > 150){
    return;
  }
  drawSquare(xcenter - halfside, ycenter - halfside, xcenter - halfside, ycenter + halfside,xcenter + halfside, ycenter + halfside , xcenter + halfside, ycenter - halfside);

  halfside *= 1.11 ;
  degree += PI/5;
  radius *= 1.15;
  radius += 0.2; //sets spiral center and draws square based on that
  xcenter = 350+radius * cos(degree);
  ycenter = 350 + radius * sin(degree);
  spiralsquare(degree, halfside, radius, xcenter, ycenter);


}


void circlelace(int xcenter, int ycenter, int radius){
gfx_circle(xcenter, ycenter, radius);
   // Base case. 
   if( radius < 4 ) return;
int newradius = radius /3; 
circlelace(radius* cos (0)+ xcenter, radius * sin(0) + ycenter, newradius);
circlelace(radius* cos (PI/3)+ xcenter, radius * sin(PI/3) + ycenter, newradius);
circlelace(radius* cos (2*PI/3)+ xcenter, radius * sin(2* PI/3) + ycenter, newradius); //places circle at certain area
circlelace(radius* cos (PI)+ xcenter, radius * sin(PI) + ycenter, newradius);
circlelace(radius* cos (4 * PI/3)+ xcenter, radius * sin(4*PI/3) + ycenter, newradius);
circlelace(radius* cos (5*PI/3)+ xcenter, radius * sin(5*PI/3) + ycenter, newradius);

}


void snowflake(int xcenter, int ycenter, int len){
if( len < 2 ) return;

gfx_line(xcenter, ycenter, xcenter + len * cos(2*PI/5), ycenter + len * sin(2*PI/5));
gfx_line(xcenter, ycenter, xcenter + len * cos(4*PI/5), ycenter + len * sin(4*PI/5));
gfx_line(xcenter, ycenter, xcenter + len * cos(6*PI/5), ycenter + len * sin(6*PI/5));
gfx_line(xcenter, ycenter, xcenter + len * cos(8*PI/5), ycenter + len * sin(8*PI/5));
gfx_line(xcenter, ycenter, xcenter + len * cos(10*PI/5), ycenter + len * sin(10*PI/5));  //draws snowflake


int newlen =  len *0.35;


snowflake( xcenter +len * cos(2 *PI/5), ycenter + len * sin(2 * PI/5), newlen);
snowflake( xcenter + len * cos(4 *PI/5), ycenter +len * sin(4 * PI/5), newlen);
snowflake( xcenter +len * cos(6 *PI/5), ycenter +len * sin(6 * PI/5), newlen); //calls for more snowflakes
snowflake( xcenter +len * cos(8 *PI/5), ycenter +len * sin(8 * PI/5), newlen);
snowflake( xcenter + len * cos(10 *PI/5), ycenter + len * sin(10 * PI/5), newlen);
}

void tree(int xstart, int ystart, int branch, double degree){
    //tree(350, 690, 120, 0);

if( branch < 1 ) return;
gfx_line(xstart, ystart, xstart+branch*cos(degree), ystart - branch*sin(degree));
gfx_line(xstart+branch*cos(degree), ystart - branch*sin(degree), xstart+ branch*cos(degree)+ 0.5 * branch*cos(degree + 7 * PI/36), ystart - branch*sin(degree) - 0.5 * branch*sin(degree+ 7 * PI/36));
gfx_line(xstart+branch*cos(degree), ystart - branch*sin(degree), xstart+ branch*cos(degree) + 0.5 * branch*cos(degree - 7 * PI/36), ystart - branch*sin(degree) - 0.5* branch*sin(degree -7 * PI/36));

tree(xstart+ branch*cos(degree) + 0.5 * branch*cos(degree + 7 * PI/36), ystart - branch*sin(degree) - 0.5 * branch*sin(degree+ 7 * PI/36),2 * branch/3 , degree + 7 * PI/36);
tree(xstart+ branch*cos(degree)+ 0.5 * branch*cos(degree - 7 * PI/36), ystart- branch*sin(degree) - 0.5 * branch*sin(degree -7 * PI/36),2 * branch /3, degree  - 7 * PI/36);


}



void fern(int xstart, int ystart, int branch, double degree){
if( branch < 8 ) return;

gfx_line(xstart, ystart, xstart+branch*cos(degree), ystart - branch*sin(degree));
int xp1, xp2, xp3, xp4, yp1, yp2, yp3, yp4;
xp1 = 0.25 * branch*cos(degree) + xstart;
xp2 = 0.5 * branch*cos(degree) + xstart;
xp3 = 0.75 * branch*cos(degree)+ xstart;
xp4 = 1 * branch*cos(degree)+ xstart; //finds the spot to put the leaves
yp1 = -0.25 * branch*sin(degree) + ystart ;
yp2 = -0.5 * branch*sin(degree)+ ystart;
yp3 = -0.75 * branch*sin(degree)+ ystart;
yp4 = -1 * branch*sin(degree)+ ystart;

gfx_line(xp1, yp1,  xp1 + 0.35 * branch*cos(degree + 7 * PI/36), yp1 - 0.35 * branch*sin(degree+ 7 * PI/36));
gfx_line(xp1, yp1 , xp1 + 0.35 * branch*cos(degree -7 * PI/36),  yp1 - 0.35* branch*sin(degree -7 * PI/36)); //draws the leaves

gfx_line(xp2, yp2 , xp2 + 0.35 * branch*cos(degree + 7 * PI/36), yp2  - 0.35 * branch*sin(degree+ 7 * PI/36));
gfx_line(xp2, yp2 , xp2 + 0.35 * branch*cos(degree  -7 * PI/36), yp2  - 0.35* branch*sin(degree -7 * PI/36));

gfx_line(xp3, yp3 , xp3 + 0.35 * branch*cos(degree + 7 * PI/36), yp3  - 0.35 * branch*sin(degree+ 7 * PI/36));
gfx_line(xp3, yp3 , xp3 + 0.35 * branch*cos(degree  -7 * PI/36), yp3  - 0.35* branch*sin(degree -7 * PI/36));

gfx_line(xp4, yp4 , xp4 + 0.35 * branch*cos(degree + 7 * PI/36), yp4  - 0.35 * branch*sin(degree+ 7 * PI/36));
gfx_line(xp4, yp4 , xp4 + 0.35 * branch*cos(degree  -7 * PI/36), yp4   -  0.35* branch*sin(degree -7 * PI/36));


fern(xp1 , yp1 ,   branch * 0.35,  degree + 7 * PI/36);
fern(xp1 , yp1  ,   branch* 0.35, degree - 7 * PI/36); //recursively calls for more leaves

fern(xp2 , yp2  ,  branch* 0.35, degree + 7 * PI/36);
fern(xp2, yp2  ,  branch* 0.35, degree  - 7 * PI/36);

fern(xp3 , yp3 ,  branch* 0.35, degree + 7 * PI/36);
fern(xp3 , yp3   , branch* 0.35 , degree  - 7 * PI/36);

fern(xp4, yp4   ,  branch* 0.35 , degree + 7 * PI/36);
fern(xp4 , yp4   ,  branch* 0.35 , degree - 7 * PI/36);


}


void spiralOfSpiral(int xstart, int ystart, double len, double degree){

if (len < 0.5) return;

gfx_point(xstart, ystart);

double distance = len;

    while( distance > 1){ //spirals for each spiral. 
        spiralOfSpiral(xstart + distance * cos(degree), ystart+ distance * sin(degree), distance/3.5, degree);
        degree += PI/6;
        distance /= 1.08;

    }

}

