//letterfreq.c Derick Shi

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define alphabet 26


int main(){

int letterlist[alphabet] = {};

char filename[30];
FILE *file;
char c;
int ccount = 0, lettercount = 0, formatcount = 0; //count variables
float percents;

printf("Enter the name of the text file: ");
fgets(filename, 30, stdin); 
if (filename[strlen(filename) - 1] == '\n') {
      filename[strlen(filename) - 1] = '\0'; //gets rid of newline character
 }
//filename = "ndfightsong.txt";
file = fopen(filename, "r");
if (file == NULL){ //display error
   printf("Error opening file.\n");
   
}
else{
   while (!feof(file)){
      ccount +=1; 
      c = getc(file);
         if ((c <= 90) & (c>= 65)){
            c += 32;
         }
         if ((c <= 122) & (c>= 97)){
            c -=97;
            lettercount +=1; 
            letterlist[c] +=1; //checks for letters and adds them to array
         }
   }
       
}

printf("Summary for %s\n", filename); //output
printf("There were %d characters and %d letters", ccount, lettercount);
printf("Letter counts:\n");
c = 97;
for (int i = 0; i<alphabet; i++){
      printf("%c: %8d  ", c, letterlist[i]);
      formatcount +=1; //prints freq of letter
      c++;
      if (formatcount == 8) {
            printf("\n"); 
            formatcount = 0;
        }
      

   }

c = 97;
formatcount = 0;
printf("\nLetter percentages: \n");
for (int i = 0; i<alphabet; i++){
      percents = (float)letterlist[i] / lettercount * 100;
      printf("%c: %5.2f%%  ", c, percents); //prints percent of letters
      formatcount +=1;
      c++;
      if (formatcount == 8) {
            printf("\n");
            formatcount = 0;
        }
      

   }
printf("\n");

return 0;
}
