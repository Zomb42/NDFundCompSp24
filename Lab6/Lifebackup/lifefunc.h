//lifefunc.h     Derick Shi


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> //needed for nano sleep
#include <time.h> 


#define size 40



void display (char s[][size], int count); //prototype function 
void place(char s[][size], int count, int add, int x, int y);

void nextsimulation(char mainboard[][size], int count);