#include <stdio.h>
#include <math.h>


int main() {


float total, interest, minterest, mpay;

int month= 0, years, errors =1;
printf("How much is the value of the mortgage?\n");
scanf("%f", &total);


printf("How much is the interest rate of the mortgage? (Enter a number like 5 for 5%)\n"); //gets input for calculations
scanf("%f", &interest);

printf("How much are you paying each month?\n");
scanf("%f", &mpay);

interest = interest/1200 ; // calculates monthly interest rate from a number like 5 -> 0.42%

printf("Month     Payment     Interest     Balance\n");

while (total>0){ //cycles through the calculations until the total is gone
month++;
minterest =  total * interest;
if (minterest > mpay){
printf("The interest is higher than the monthly pay!"); //checks if the user is actually paying off the mortgage
errors = 0;
break;
}
if (total + minterest < mpay){
mpay = total + minterest; //calculates monthly interest

}
total = minterest + total - mpay; //Calculates the new total


printf("%5d,  %8.2f,  %8.2f,  %9.2f\n", month, mpay, minterest, total);// prints out everythign in a formatted fashion



}
years = month/12;
month -= years * 12; //figures out how long it takes for you t pay off 

if (errors =1){
printf("It took you %d years and %d months to pay off the mortgage\n", years, month);

}


}
