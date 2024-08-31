#include <stdio.h>
#include <math.h>



int main() {


float x= 0, y,ymin = 1000, ymax, xmin = 0, xmax = 0;

printf("This program will print the equation sin(x+2) + 2ln(x+2) over the domain of x = 0 to x = 20\n");
printf("  X     Y\n"); //Lets the user know what numbers are coming up and formats the title

while(x < 20.2){ //Cycles through the X axis


y = sin(x+2) + 2* log(x+2);
printf("%5.2f  %5.2f  ", x, y); //formats and gets the x and y values
if (y>ymax){
   ymax = y;
   xmax = x;
}
if (y <ymin){
   ymin = y;
   xmin = x;

}

while (y > 0){
printf("#");

y -= 0.25;//Prints # for the y value based on 0.25 increments. 
}

x += 0.2; //Increments for X so that program will touch a lot more x values. 
printf("\n");

}

printf("The maximum of %.2f was at %.2f\n", ymax, xmax);
printf("The minimum of %.2f was at %.2f\n", ymin, xmin);



}
