#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


#define maxnumsaying 50
#define length 257
void readfile(FILE *file, sayings[][length], count);
void addsaying(FILE *file, sayings[][length]);
void phrasecontain(sayings[][length], count);
void newtxtfile (sayings[][length], count);
void sayinglen( sayings[][length], count);

int main(){

FILE *file;
char filename[31] ;
char linesay[length];

int response = 0;
printf("Enter the name of the text file: ");
fgets(filename, 31, stdin); 
if (filename[strlen(filename) - 1] == '\n') {
      filename[strlen(filename) - 1] = '\0'; //gets rid of newline character
 }
//filename can be "startup.txt";
file = fopen(filename, "w");
if (file == NULL){ //display error
   printf("Error opening file.\n");
   
}

else{
   while (response != 6){

      char sayings[maxnumsaying][length];
      char linesay[length];
      int count = 0;
      while(!feof(file)){
           fgets(linesay, length, file);
           if (linesay[strlen(linesay) -1] == '\n'){

               linesay[strlen(linesay)-1] = '\0';

                  }
           strcpy(sayings[count], linesay);
           count +=1; 
       }

       printf("\n1. Display all sayings in database\n2. Enter new saying into database\n3. List sayings that contain a given substring\n4.Save all sayings in a new text file\n5. Find the sayings that are greater than n charactesr\n6. Quit the program\n");
      scanf("%d", &response);
      switch (response){
         case 1:
         readfile(file, sayings, count);         

         break;
         case 2:
         addsaying(file, sayings);
         


         break;
         case 3:
         phrasecontain(sayings, count);

         break;

         case 4:
         newtxtfile(sayings, count);
         break;
         case 5:
            sayinglen(
         break;
         case 6:
            printf("Have a nice day\n");
         break;
         default:
            printf("\nInvalid input. Please try again\n");
         break;
         

      }
      
}
}

}

void readfile(FILE *file, sayings[][length], count){

   for (int i = 0; i < count; i++){
      printf("%s\n", sayings[i]);

   }
}
void addsaying(FILE *file, sayings[][length]){

char lineadd[length];
int letters;
   printf("What saying would you like to add?\n");
      fgets(lineadd, length, stdin)'
      if (lineadd[strlen(lineadd) -1] == '\n'){

            lineadd[strlen(lineadd)-1] = '\0';

      }

      fseek(file, 0, SEEK_END);
      if (ftell(file) > 0){
         printf(file, "\n");
      }
      fprintf(file, "%s", lineadd);
      printf("Added: %s\n", lineadd);

}


void phrasecontain(sayings[][length], count){

int contain = 0;
char linesearch[length];
char specificsayings[maxnumsayings][length];
      printf("What phrase would you like the sayings to contain?\n");
      fgets(linesearch, length, stdin);
      if (linesearch[strlen(linesearch) -1] == '\n'){

      linesearch[strlen(linesearch)-1] = '\0';

      }
      for (int i = 0; i< count; i++){

         bool linecontain = false;
         for (int j = 0; j = strlen(sayings[i]) ; j++){
            if(linesearch[0] = sayings[i][j]){
                  linecontain = true;
                 for (int k = j; k < strlen(linesearch)+ j; k++){
                     if (sayings[i][k] != linesearch[k-j]){
                        linecontain = false;
                     }
                  }
            }
         }
         if (linecontain){
            strcpy(specificsayings[contain], sayings[i]);
            contain +=1; 
         }
      }
   
      for (int i = 0; i< contain; i++){
         printf("%s\n", specificsayings[i];

      }


}

void newtxtfile(sayings[][length], count){
      
char nfilename[31];
printf("What should the name of the new file be called? ");
   fgets(nfilename, 31, stdin); 
   if (nfilename[strlen(nfilename) - 1] == '\n') {
      nfilename[strlen(nfilename) - 1] = '\0'; //gets rid of newline character
   }
//filename can be "startup.txt";
FILE *nf = fopen(nfilename, "w");

   for (int i = 0; i < count; i++){
        fprintf(nf, "%s\n", sayings[i]);


   }
}


