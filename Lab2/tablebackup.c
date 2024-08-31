#include <stdio.h>
#include <math.h>

int main(){

        int x, y, xpro;


        printf("Enter the size of the multiplication table, X size first and then Y\n");

        scanf("%d %d", &x, &y);


        for (int j = -1; j <=(y); j++) { //Cycles through the y dimension

                if (j>0){
                        printf("%2d|", j);//Adds row titles on the side for rows displaying content

                }
                else{
                        printf("   "); //Adds spacing for the very top
                }

                for (int i = 1; i <= x; i++){ //Cycles through the x dimension

                        if (j == -1){
                                printf("%4d", i); //Formats the top of the table

                        }
                        else if (j == 0){//formats
                                printf("----");

                        }
                        else{
                                xpro = (i*j); // Finds the values in the multiplication table
                                printf("%4d", xpro);

                        }



                }
                printf("\n");






        }






}
