#include <stdio.h>
#include <math.h>


int main() {

 double a, b, c, disc;
 double x1, x2;



  printf("Enter the coefficients (a,b,c) of a quadratic equation: ");
  scanf("%lf %lf %lf", &a, &b, &c);

disc = ( b*b) - (4 * a * c);

if (disc < 0){//tests if there is imaginary solutions
   printf("\nThere are imaginary roots. Please enter different numbers next time \n ");
}
else{
   x1 = (0 -  b - sqrt(disc))/(2 * a);
  //applies the quadratic formula 
   x2 = (0 -  b + sqrt(disc))/(2 * a);


//prints roots
   printf("\nOne root is %lf and the other root is %f\n", x1, x2);


}

}

