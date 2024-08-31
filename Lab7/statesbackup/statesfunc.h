//statesfunc.h   Derick Shi


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxstates 100

typedef struct State{

    char abbre[20];
    char name[20]; //struct declaration
    char capital[20];
    int year;
} State;

int readstates(FILE*, State[]);
void menu(State[], int);

void printeverything(State[], int);
void printyear(State[], int, int); //prototypes function. One for each menu option
void printabbre(State[], int, char);
void printcapital(State[], int, char[], int);
void yearjoin(State[], int, int);