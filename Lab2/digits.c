#include <stdio.h>
#include <math.h>



int main() {

int num, displaynum;

printf("Enter a number\n");
scanf("%d", &num);

while (num>0){

displaynum = num%10;
printf("%d", displaynum);
num = (num-displaynum)/10;



}




}
