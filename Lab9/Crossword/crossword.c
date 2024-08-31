
#include "crossfunc.h"


int main(int argc, char *argv[]){
FILE *rfile;
FILE *ofile;
char wordbank [20][15] = {0};
char wordinput [20][15] = {0};
int wordpoints [20][4] = {0}; //stores coordinates of the word, horizontal vs vertical, and whether it was placed
char wordboard[width][width];
char hashboard[width][width];
int count = 0, placedcount = 0;
for (int i = 0 ; i < 15; i++){
    for (int j = 0; j< 15; j++){
        wordboard[i][j] = '.';
        hashboard[i][j] = '#';
    }
}
rfile = stdin;
ofile = stdout;
if (argc == 1){
printf("Anagram Crossword Puzzle Generator\n");
printf("--------------------------------\n");
printf("\nEnter a list of words:\n");
   
    count = readwords(wordinput, 20, rfile);
    
      
    

}
else if (argc == 2){
    rfile = fopen(argv[1], "r");
    
   if (rfile == NULL){ //display error 
        printf("Error opening file.\n");
    }
    else{
        count = readwords(wordinput, 20, rfile);
       


    }
}


else if (argc == 3){
    rfile = fopen(argv[1], "r");
    
   if (rfile == NULL){ //display error
        printf("Error opening file.\n");
    }
    else{
        count = readwords(wordinput, 20, rfile);
       


    }
    ofile = fopen(argv[2], "w");

}
else {

    printf("Too many arguements please try again \n"); //display error
    exit(0);

}


wordorganize(wordinput, 15, wordbank, 15, count); //sorts and capitalizes the word
placedcount = place(wordbank, 15, wordboard, 15, count, wordpoints);
fprintf(ofile, "\nSolution: \n");
display(wordboard, 15, ofile);

for (int i =0; i < 15; i++){
    for (int j = 0; j <15; j++){
        if (wordboard[i][j] != '.'){
            hashboard[i][j] = ' '; //prints the board 
        }
    }
}
fprintf(ofile, "\nCrossword: \n");
display(hashboard, 15, ofile);

fprintf(ofile, "\nClues: \n");

for (int i = 0; i< count; i++){
    if (wordpoints[i][2] == 0){
        fprintf(ofile, "Unable to print %s \n", wordbank[i]);
    }
}

for (int j = 0; j < 15; j++){

for (int i = 0; i < count; i++){
    if (wordpoints[i][0] == j && wordpoints[i][2] == 1){
    fprintf(ofile, "%2d, %2d", wordpoints[i][0], wordpoints[i][1]);
    if (wordpoints[i][3] == 1){ //displays clues
        fprintf(ofile, " horizontal ");
    }
    else{
        fprintf(ofile, " vertical   ");
    }
    fprintf(ofile, "%s \n", strfry(wordbank[i])); 
    }

}

}



}

