//mysayings.c     Derick Shi



#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


#define maxnumsaying 50
#define length 257
void readdata(char sayings[][length], int count);//protoype functions 
void addsaying(char sayings[][length], int *count);
void phrasecontain(char sayings[][length], int count);
void newtxtfile (char sayings[][length], int count);
void sayinglen(char sayings[][length], int count);

int main(){

   FILE *file;
   char filename[31] ;
   char linesay[length];

   int response = 0; //opens specific file based on name
   printf("Enter the name of the text file: ");
   fgets(filename, 31, stdin); 
   if (filename[strlen(filename) - 1] == '\n') {
      filename[strlen(filename) - 1] = '\0'; //gets rid of newline character
   }
   //filename can be "startup.txt";
   file = fopen(filename, "r");
   if (file == NULL){ //display error
     printf("Error opening file.\n");
   
   }

   else{

      char sayings[maxnumsaying][length];
      char linesay[length];
      int count = 0;
   while(!feof(file)){
           fgets(linesay, length, file);
           if (linesay[strlen(linesay) -1] == '\n'){

               linesay[strlen(linesay)-1] = '\0';

                  }
           strcpy(sayings[count], linesay); //copies all of the sayings into a 2D array 
           count +=1; 
       } 
   while (response != 6){
  
      for (int i = 0; i < 20; i++){
         printf("-"); //makes formating nicer 
      }
      printf("\n1. Display all sayings in database\n2. Enter new saying into database\n3. List sayings that contain a given substring\n4. Save all sayings in a new text file\n5. Find the sayings that are greater than n charactesr\n6. Quit the program\n");
      scanf("%d", &response);
      switch (response){ //menu display. The function that performs each task are fairly intuitive. 
         case 1:
            readdata(sayings, count);  //actually prints the data 
         break;
         case 2:
            addsaying(sayings, &count); 
         break;
         case 3:
            phrasecontain(sayings, count);
         break;
         case 4:
            newtxtfile(sayings, count);
         break;
         case 5:
            sayinglen(sayings, count);
         break;
         case 6:
            printf("Have a nice day\n");
         break;
         default:
            printf("\nInvalid input. Please try again\n"); //default case
         break;

      }
      
}
}

}

void readdata(char sayings[][length], int count){

   for (int i = 0; i < count; i++){//prints out the sayings from the string
      printf("%s\n", sayings[i]);

   }
}
void addsaying(char sayings[][length], int  *count){

   char lineadd[length];
   int letters;
   getchar();
   printf("What saying would you like to add?\n");
      fgets(lineadd, length, stdin);
      if (lineadd[strlen(lineadd) -1] == '\n'){

            lineadd[strlen(lineadd)-1] = '\0';

      }
      strcpy(sayings[*count], lineadd); //adds a specific saying to the sayings string
      *count +=1; 

}


void phrasecontain(char sayings[][length], int count){

       int contain = 0;
       char linesearch[length];
       char specificsayings[maxnumsaying][length];
       getchar();
       printf("What phrase would you like the sayings to contain?\n");
       fgets(linesearch, length, stdin);
       if (linesearch[strlen(linesearch) -1] == '\n'){

          linesearch[strlen(linesearch)-1] = '\0';

      }
      for (int i = 0; i< count; i++){



         if (strstr(sayings[i], linesearch) !=NULL){ //If the saying is found it will be copied to a separate array that will then be printed
            strcpy(specificsayings[contain], sayings[i]);
            contain +=1;  

         }
      }
   
      for (int i = 0; i< contain; i++){ //prints out the sayings that fit the criteria 
         printf("%s\n", specificsayings[i]);

      }


}

void newtxtfile(char sayings[][length], int count){
      
   char nfilename[31];
   getchar();
   printf("What should the name of the new file be called? ");
   fgets(nfilename, 31, stdin); 
   if (nfilename[strlen(nfilename) - 1] == '\n') {
      nfilename[strlen(nfilename) - 1] = '\0'; //gets rid of newline character
   }
   FILE *nf = fopen(nfilename, "w"); //makes a new file with that file name

   for (int i = 0; i < count; i++){
        fprintf(nf, "%s\n", sayings[i]);//prints the sayings into the new file


   }
   fclose(nf); //makes sure nothing confusing is happening with different open files. 
}

void sayinglen(char sayings[][length], int count){
      
    int clen;
    printf("What is the minimum length in characters do you want the sayings to be? ");
    scanf("%d", &clen);
   
   for (int i = 0; i < count; i++){
      if (strlen(sayings[i]) >= clen){//only prints certain phrases that are above a character length 
         printf("%s\n", sayings[i]);
      }


   }


}
