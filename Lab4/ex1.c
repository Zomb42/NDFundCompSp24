#include <stdio.h>


int main(){

int nums[5] = {};

printf("Enter 5 numbers\n");

for (int i = 0; i<5; i++){
   scanf("%d", &nums[i]);
}

printf("\n\n");
for (int i = 4; i>= 0; i--){
printf("%d ", nums[i]);
}





return 0;
}
