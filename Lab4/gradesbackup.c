//grades.c    Derick Shi


#include <stdio.h>
#include <math.h>

float average(int[], int); //prototypes the functions
float standarddeviation(int[], int);

int main(){

   int grades[] = 
      { 96, 73, 62, 87, 80, 63, 93, 79, 71, 99,
        82, 83, 80, 97, 89, 82, 93, 92, 95, 89,
        71, 97, 91, 95, 63, 81, 76, 98, 64, 86,
        74, 79, 98, 82, 77, 68, 87, 70, 75, 97, 
        71, 94, 68, 87, 79};

      int size = sizeof(grades)/sizeof(grades[0]); //gets size of array


      printf("The average of the grades is %5.2f", average(grades, size)); //output
      printf("\nThe standard deviation of the grades is %5.2f\n", standarddeviation(grades, size));





   return 0; 
}

float average(int a[], int b){
   int sum= 0;
   for (int i = 0; i< b; i++){
       sum += a[i];

   }  

   return sum/b; //finds the average after finding total sum
}

float standarddeviation(int a[], int b){
   float mean = average(a, b), difmean;
   for (int = 0 ; i< b; i++){
      difmean += fabs(mean - a[i]); //performs calculations to find standard deviation


   }
   difmean /= (b-1);
   return sqrt(difmean); //returns std

}
