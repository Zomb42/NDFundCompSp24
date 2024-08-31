#include <stdio.h>
typedef struct {
int dollar;
int cent;
} Money;
int readAmounts(FILE *, Money[]);
void displayOneAmount(Money);
void displayAllAmounts(Money *, int);
Money findSum(Money *, int);
int main()
{
Money theamounts[20];
FILE *fp = fopen("amounts.txt", "r");
int count = readAmounts(fp, theamounts);
printf("There are %d amount values\n", count);
printf("They are:\n");
displayAllAmounts(theamounts, count);
Money *p = theamounts;
Money thesum = findSum(p, count);
printf("The sum of the amounts is:\n");
displayOneAmount(thesum);
return 0;
}

int readAmounts(FILE *fp, Money arr[]){
  int count = 0;
    while (fscanf(fp, "%d %d", &arr[count].dollar, &arr[count].cent) == 2){
        
        count +=1;
    }
  return count;

}

void displayAllAmounts(Money *p, int count)
{
  for (int i = 0; i< count; i++){
    displayOneAmount(p[i]);
  }
}


void displayOneAmount(Money m)
{
  printf("$%d.%d\n", m.dollar, m.cent);
}

Money findSum(Money *p, int count)
{
  Money result;
  int placement;
  result.dollar =0;
  result.cent =0;
    for (int i = 0; i< count; i++){
        result.dollar += p[i].dollar;
        result.cent += p[i].cent;
    }
    result.dollar += result.cent/100;
    result.cent = result.cent % 100;
  return result;
}