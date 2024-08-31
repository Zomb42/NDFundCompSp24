#include <stdio.h>

int main(){
int touchdowns;
int extraPoint;
int fieldGoal;
int safety;
int totalPoint;
/* Sets each way of attaining point and the total sum as variables    */


printf("The Irish Scored:\nHow many touchdowns?: \n");

scanf("%d", &touchdowns); 

printf("How many extra points?: \n");

scanf("%d", &extraPoint); //Asks for the specific value for each of the ways to score points.

printf("How many field goals?: \n");

scanf("%d", &fieldGoal);

printf("How many safeties?: \n");

scanf("%d", &safety);

/* Gets input for each variable type and then calculates the total point value before printing it back   */

totalPoint = safety*2 + fieldGoal*3  + extraPoint + touchdowns*6;

printf("\nTotal points scored by the Irish is: %d\n", totalPoint);



}





