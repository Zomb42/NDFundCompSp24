#include <stdio.h>
#include <math.h>
//quadratics.c  Derick Shi 

float discriminate (float, float, float); //prototype function

float a , b, c, disc, x1, x2; //declares variables 

int main(){

              printf("Enter the coefficients (a,b,c) of a quadratic: ");//allows the program to start

              scanf("%f %f %f", &a, &b, &c); //input
        while (a!= 0){



                disc = discriminate(a,b,c);
                if (disc < 0){//checks to see if disc is negative 
                        printf("\nThere are imaginary roots. Please enter different numbers");

                }else{

                        x1 = (-b-sqrt(disc))/(2* a);
                        x2 = (-b+sqrt(disc))/(2 * a);//finds roots


                        printf("\nOne root is %f and the other root is %f\n", x1, x2);
                }





                printf("Enter the coefficients (a,b,c) of a quadratic: ");//sees if the program keeps looping

                scanf("%f %f %f", &a, &b, &c); //input
        }

}
float discriminate (float x, float y, float z){

        return ((y*y) - (4 * x * z));

//finds discriminate 
}


