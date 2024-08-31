#include "crossfunc.h"



void display(char array[][width], int count, FILE* file){
    for (int i = 0; i < count+2; i ++){
        for (int j = 0; j< count+2; j++){
            if (i == 0 || i == count+1){ //adds border
                fprintf(file, "-");
            }
            else{
                if (j == 0|| j == count +1 ){
                    fprintf(file, "|"); //adds border
                }
                else{
                    fprintf(file, "%c", array[i-1][j-1]); //prints main board accounting for widths
                }

            }
        
        }
        fprintf(file, "\n");
    }


}

void wordorganize(char input[][width], int c, char bank [][width], int c2, int c3){

for (int i = 0; i < c3; i++){
        for (int j = 0; j <15; j++){
            if (input[i][j] >= 97){
                input[i][j] -= 32; //capitalizes words
            }
        }
    }
    for (int i = 0; i < c3; i++){
        int index = 20;
        char maxlenword[15];
        int maxlen = 0;
        for (int j = 0; j< 20; j++){ //sorts it by decsending length 
            if (strlen(input[j]) > maxlen && strcmp(input[j], ".")){
                maxlen = strlen(input[j]);
                index = j;
                strcpy(maxlenword, input[j]);
            }
        }
        if (index <20){
            strcpy(input[index], ".");
        }
        
        strcpy(bank[i], maxlenword);

    }


}

int readwords(char array[][width], int c, FILE* file){
        char oneword[16]; //one more length than max length to check for words that are to long
        
        int flag;
        int count = 0;
        while(1){
            flag = 0;
            fscanf(file, "%s", oneword);


            if (strlen(oneword) < 2 || strlen(oneword) > 15) { //checks for proper length
                
                flag = 1;
            }
            for (int i =0; i<strlen(oneword); i++){
                if (isalpha(oneword[i]) == 0){ //checks for letters
                    flag = 1;
                }
            }
            
            if (oneword[0] == '.'){
                break;
            }

            if (flag == 0){
                strcpy(array[count], oneword); //if the word doesn't break the above conditions, it accepts it 
                count+=1;
            }
            else{
                printf("Couldn't accept the word starting with %s\n", oneword); 
            }

            if (count == 20){
                break;
            }
            
        }

    return count;
}



int place(char array[][width], int c, char board[][width], int c1, int count, int wordpoints[20][4]){
    
    
    int len = 0, valid =1, placer = 0, placed =0, totalplaced = 0, secondtime = 0, doublecheck = 0;
    rewindtime:
    for (int i = 0; i < count; i++){

        if (wordpoints[i][2] == 0){ //only checks words that aren't placed for more efficiency

        valid = 0;
        len = strlen(array[i]);
        if (i == 0){
            
            for (int j = 0; j< len; j++){
                board[7][(15 - len )/2+j] = array[i][j];
            }
            wordpoints[i][0] = (15 - len )/2;
            wordpoints[i][1] = 7;
            wordpoints[i][2] = 1;
        }
        else{
        for (int n =0; n < len; n++){ //iterates over characters of a specific word
            placed = 0;
            for (int m = 0; m < 15; m++){   //iterates over the board 
                for (int k = 0; k < 15; k++){
                    if (array[i][n] == board[m][k]){
                        
                        valid = 1;
                        placer = 0;
                        if (board[m][k+1] == '.' && board[m][k-1] == '.'){ //will check word horizontally
                           
                            for (int b = -1; b < len +1 ; b++){
                                if (b == n){
                                    continue;
                                }
                                if (b > -1 && b < len){ //checks for . to make sure there is open space. 
                                    if (k-n + b > 14 || k-n + b < 0){//won't check the word that it's intersecting however
                                        valid = 0;
                                        break;
                                    }
                                }
                                if (board[m-1][k -n + b] != '.' || board[m][k -n + b] != '.' || board[m+1][k -n + b] != '.'){
                                    valid = 0;
                                    break;
                                }

                            }
                            if (valid == 1){ //places word horizontally 
                                
                                for (int b = 0; b < len ; b++){
                                    board[m][k-n + b] = array[i][placer];
                                    placer +=1;
                                }
                                wordpoints[i][0] = k;
                                wordpoints[i][1] = m-n;
                                wordpoints[i][3] = 1; //marks 1 for horizontal, 0  or nothing for vertical 
                                placed = 1;
                                totalplaced +=1;
                            }
                        }
                        else{ //check word vertically 
                            
                            for (int a = - 1; a < len + 1; a++){
                                if (a == n){
                                    continue;
                                }
                                if (a > -1 && a < len){
                                    if (m-n + a > 14 || m-n + a < 0){
                                        valid = 0;
                                        break;
                                    }
                                }
                                if (board[m-n + a][k-1] != '.' || board[m-n + a][k] != '.' || board[m-n + a][k+1] != '.'){
                                    valid = 0; //checks to see if there is a 3 x len + 2 area around the word that allows it to be placed. 
                                    break;
                                }
                            }
                            if (valid == 1){ //places word vertically 
                                
                                for (int a = 0; a < len ; a++){
                                    board[m-n + a][k] = array[i][placer];
                                    placer +=1;
                                }
                                wordpoints[i][0] = k-n;//stores coordinates of the word 
                                wordpoints[i][1] = m;
                                placed = 1;
                                totalplaced += 1;
                            }

                        }


                    }

                    if (placed == 1){

                        k = 15;
                        m = 15; //if it's placed, it skips to the net iteration while breaking out of 3 for loops. 
                        n = len;
                    }


                }
            }
            if (placed == 1){ //if the word fits on the board, it marks another array that has a data on each word.
                wordpoints[i][2] = 1;
                break;
            } 


        }

      
        



        }

    }
    

    }
    if(doublecheck < 3){ //tries to place words that couldn't fit initially.
        doublecheck += 1;
        goto rewindtime;
    }
    
   

return totalplaced;

}
