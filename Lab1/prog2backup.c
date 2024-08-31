#include <stdio.h>
#include <math.h>


int main() {
float aTerm;
float bTerm;//declares the variables. They are float because there might be decimal roots or quadratic terms. 
float cTerm;
float discriminate;
float root1;
float root2;


printf("This is a non-imaginary quadratic roots calculator for a quadratic of the form ax^2 + bx + c. Enter a: \n");
scanf("%f", &aTerm);
printf("Enter b: \n");//collects input
scanf("%f", &bTerm);
printf("Enter c: \n");
scanf("%f", &cTerm);
discriminate = ( bTerm*bTerm) - (4 * aTerm * cTerm);

if (discriminate < 0){//tests if there is imaginary solutions
   printf("\nThere are imaginary roots. Please enter different numbers next time \n ");
}
else{
   root1 = (0 -  bTerm - sqrt(discriminate))/(2 * aTerm);
  //applies the quadratic formula 
   root2 = (0 -  bTerm + sqrt(discriminate))/(2 * aTerm);


//prints roots
   printf("\nOne root is %f and the other root is %f\n", root1, root2);


}

}

