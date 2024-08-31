
#include <stdio.h>
#include "pathfunc.h"


int main(){

  Point point_array[30]; //struct array
  char filename[30];
  FILE *file;
  int count = 0;
  float distance;

  printf("Name of text file to open "); //reads textfile name
  gets(filename, 30, stdin);
  if (filename[strlen(filename) - 1] == '\n') {
    filename[strlen(filename) - 1] = '\0'; //gets rid of newline character
  }
  file = fopen(filename, "r");
  if (file == NULL){
    printf("Error opening file.\n"); //can't open file
  }
  
  else{ //opens file

    count = readvalues(file, point_array);
    distance = calcdistance(point_array, count);

    printf("There are %d points:\n\n");
    printchart(point_array, count); //prints out the useful information
    printf("The length of the path through the points is %.2f\n", distance);
  }




    return 0;
}

