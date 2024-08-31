//ndfootball.c    Derick Shi

#include <stdio.h>
#include <math.h>

int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4, 6, //array data for wins and losses
   7, 7, 6, 7, 8, 6, 3, 9, 9, 10, 8, 9,
   10, 7, 9, 7, 5, 9, 10, 6, 6, 3, 6, 7, 
   6, 6, 8, 7, 7, 8, 7, 9, 8, 7, 8, 9,
   9, 10, 4, 7, 7, 9, 9, 8, 2, 7, 6, 5, 
   2, 5, 5, 2, 9, 7, 9, 8, 7, 8, 10, 8, 
   8, 11, 10, 8, 9, 11, 9, 7, 9, 5, 6, 7, 
   7, 5, 5, 8, 12, 12, 9, 10, 10, 11, 6, 9, 
   8, 7, 9, 5, 9, 5, 10, 5, 6, 9, 10, 3, 
   7, 6, 8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 
   10, 11, 9, 10 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1, 0,
   0, 0, 2, 1, 1, 1, 1, 0, 0, 1, 1, 1,
   0, 2, 1, 1, 4, 0, 0, 2, 2, 5, 3, 1,
   2, 2, 1, 2, 2, 0, 2, 1, 2, 2, 0, 0,
   0, 0, 4, 2, 2, 0, 1, 2, 8, 3, 4, 5,
   8, 5, 5, 7, 1, 2, 0, 2, 2, 2, 1, 2,
   3, 0, 2, 3, 3, 1, 3, 4, 2, 6, 4, 5,
   5, 6, 6, 4, 0, 1, 3, 3, 1, 1, 5, 3,
   3, 6, 3, 7, 3, 6, 3, 7, 6, 3, 3, 9,
   6, 6, 5, 5, 1, 4, 5, 3, 8, 3, 1, 2,
   2, 2, 4, 3 };

int size = sizeof(wins)/sizeof(wins[0]);

int numwins(int [], int[], int);
int record(int [], int[], int); //prototypes function
int numloss(int[],int [], int); 
int winningper(int[], int[], int);
int gamesplay(int[], int [], int);
void display();

int main(){


   display();

   return 0;

}

void display(){

   int option = 0;
  
   while (option != 6){
      printf("\n\nWelcome to ND's football record analyzer. Please type and enter the number next to an option to perform it\n1: Show the record for a given year\n2: Show the years above \"n\" of wins\n3: Show the years above \"n\" of losses\n4: Show the years above \"n\" winning percentage\n5: Show the years above \"n\" games played\n6: Quit\n");
      scanf("%d", &option);

      switch(option){ //uses switch case to organize menu display
         case 1:
            record(wins, losses, size);
            break;
         case 2:
            numwins(wins, losses, size);
            break;
         case 3:
            numloss(wins, losses, size);
            break;
         case 4:
            winningper(wins, losses, size);
            break;
         case 5:
            gamesplay(wins, losses, size);
            break;
         case 6:
            printf("Have a nice day\n");
            break;  

      }

   }

}

int numwins(int a[], int b[], int c){
   int minwin;
   printf("Enter minimum number of wins\n"); //finds min win
   scanf("%d", &minwin);
    for (int i = 0; i < c; i++){
        if (a[i] >= minwin){
            printf("%d ", i+1900);

         }



     }
}

int record(int a[], int b[], int c){
   int year;
   printf("Enter which year\n"); //finds record for a year
   scanf("%d", &year);
   printf("%d wins and %d losses", a[year-1900], b[year-1900]);


}
   
int numloss(int a[],int b[], int c){
   int minloss;
   printf("Enter minimum number of losses\n"); //finds min losses
   scanf("%d", &minloss);
    for (int i = 0; i < c; i++){
        if (b[i] >= minloss){
            printf("%d ", i+1900);

         }



     }

   

}

int winningper(int a[], int b[], int c){
   float winper;
   printf("Enter a minimum winning perentage (ex. 75 for 75%)");
   scanf("%f", &winper);
   for (int i = 0; i< c; i++){
      if ((float) a[i]/(b[i]+a[i]) > winper/100){ //finds winning percentage after converting wins to float first
         printf("%d ", i+1900);

      }


   }

}

int gamesplay(int a[], int b[], int c){
   int gp;
   printf("Enter a minimum number of games played\n");
   scanf("%d", &gp);
   for (int i = 0; i<c; i++){
      if (a[i] + b[i] >= gp){ //finds number of games palyed
         printf("%d ", i+1900);
      }

   }


}

   

