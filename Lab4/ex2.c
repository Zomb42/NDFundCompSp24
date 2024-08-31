#include <stdio.h>


int main(){

int nums[21] = {};
int i = 0, length;
printf("Enter some numbers followed by -1 when done\n");

while (nums[i-1] != -1){
   scanf("%d", &nums[i]);
   i++;
}

printf("\n");
for (int j = i-2; j>= 0; j--){

   printf("%d ", nums[j]);
}





return 0;
}
