//menucalc.c      Derick Shi
#include <stdio.h>
#include <math.h>



void multiplication(int, int); //prepares functions
void division(double, double);
void addition(int, int);
void subtraction(int, int);




int main() {


        int response = 0, num1, num2;
        while (response != 5){ //loops until quit
                printf("What would you like to do? Type and enter the number next to the action.\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Quit\n");
                scanf("%d", &response);
                if(response != 5){ 
                        printf("\nEnter two numbers. The operation will be treated as if its respective sign is between the two numbers\n");
                        scanf("%d %d", &num1, &num2);
                }
                switch(response){ //different outcome based on response in an easy way to see
                        case 1:
                                addition(num1, num2);
                                break;
                        case 2:
                                subtraction(num1, num2);
                                break;
                        case 3:
                                multiplication(num1, num2);
                                break;
                        case 4: 
                                division(num1, num2);
                                break;
                        case 5:
                                printf("Have a nice day"); //quit option does nothing except you're leaving 
                                break;




                }



        }

}

void addition(int x, int y){
        printf("%d + %d = %d\n", x, y, x+y); //functions that does the action with print output
}

void subtraction(int x, int y){
        printf("%d - %d = %d\n", x, y, x-y);
}

void multiplication(int x, int y){
        printf("%d * %d = %d\n", x, y, x*y);
}


void division(double x, double y){
        if (y == 0){
                printf("You can't divide by 0\n"); //checks that you aren't dividing by 0 
        }
        else{
                double quotient = x / y;
                printf("%0.2lf / %0.2lf = %0.2lf\n", x, y, quotient); //format to 2 decimal points 

        }

}

