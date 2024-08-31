#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
  float x; //struct definition
  float y;
} Point;

int readvalues(FILE *, Point []);
float calcdistance(Point [], int d); //prototypes function
void printchart(Point [], int d);
