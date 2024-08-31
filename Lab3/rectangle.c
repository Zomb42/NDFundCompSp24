//rectangle.c
#include <stdio.h>

float perim(float, float);
float area(float , float );


float len, wid;

int main(){



        printf("Enter a rectangle's length and width: ");
        scanf("%f %f", &len, &wid);

        printf("The area is %f. The perimeter is %f\n", area(len, wid), perim(len, wid));






}

float perim(float x, float y){

        return(2 * (len+wid));
}
float area(float x, float y){

        return(len * wid);
}
