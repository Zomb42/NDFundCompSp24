#include <stdio.h>
#include <math.h>


int main() {
float aTerm;
float bTerm;
float cTerm;
float discriminate;
float root1;
float root2;

float testt;

printf("This is a non-imaginary quadratic roots calculator for a quadratic of the form ax^2 + bx + c. Enter a: \n");
scanf("%f", &aTerm);
printf("Enter b: \n");
scanf("%f", &bTerm);
printf("Enter c: \n");
scanf("%f", &cTerm);
discriminate = ( bTerm*bTerm) - (4 * aTerm * cTerm);

printf("%f", discriminate);
if (discriminate < 0){
   printf("\nThere are imaginary roots. Please enter different numbers next time \n ");
}
else{
   root1 = (0 -  bTerm - sqrt(discriminate))/(2 * aTerm);
   
   root2 = (0 -  bTerm + sqrt(discriminate))/(2 * aTerm);
   testt = (0 - bTerm - discriminate);
   printf("\n%f" , testt);



   printf("\nOne root is %f and the other root is %f\n", root1, root2);


}

}

