#define _GNU_SOURCE
#include <stdio.h>

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h> 

#define width 15


void display(char array[][width], int, FILE*); //function prototypes
void wordorganize(char input[][width], int, char bank[][width], int, int);
int readwords(char array[][width], int, FILE*);
int place(char array[][width], int, char board[][width], int, int count, int points[20][4]);
