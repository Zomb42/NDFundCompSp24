//primes.c    Derick Shi

#include <stdio.h>
#include <math.h>


int main(){


   int nums[1000] = {};
   int size = 1000, counter = 0; //can be calculated with sizeof for other size arrays
   for (int i = 0; i<size; i++){
      nums[i] = 1;

}
   for (int i = 2; i<size; i++){ 
        
      if (nums[i] == 1){
         for (int j = i * 2; j<size; j +=i){
            nums[j] = 0; //marks the numbers that are composite as 0 as it cycles through the array
      }  
         }

   }  
   printf("Prime numbers from 1 - 1000:\n");
   


   for (int i = 2; i<size; i++){
      if (nums[i] == 1){
         printf("%3d ", i); //if the value is not marked, it prints the index
         counter +=1; 
      }
      if (counter == 10){ //makes there be a maximum of 10 numbers per line
         counter = 0;
         printf("\n");
      }
   }
   return 0;
}
