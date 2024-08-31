#include "pathfunc.h"


int readvalues(FILE *file, Point arr[])
{ 
  int i = 0;
  while(fscanf(file, "%f %f", &arr[i].x, &arr[i].y) == 2){
      i+=1;

   }//checks to see if there are 2 values and scans them into the point array 

  return i;
}

float calcdistance(Point arr[], int d){

float total;
    for (int i = 1 ; i < d; i ++){
        total += sqrt( pow(arr[i-1].x - arr[i].x, 2)+ pow(arr[i-1].y - arr[i].y, 2));
    //calculates distance based on the math function

    }
return total;

}

void printchart(Point arr[], int d){

    printf("   x   |   y   \n");
    printf("-------+-------\n"); 
    for (int i = 0; i < d; i++){ //displays the chart
        printf("%7.2f | %7.2f\n", arr[i].x, arr[i].y); //formats output 
    }

}