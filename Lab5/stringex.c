//stringex.c
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert(char []);

int main(){

char line[80];

printf("enter a line: ");
fgets(line, 80 , stdin);
line[strlen(line) -1] = '\0';

convert(line);
printf("%s\n", line);



return 0;



}

void convert(char str[]){

int length = strlen(str);
for (int i = 0; i<length; i++){
   if (isupper(str[i])){
      str[i] += 32;

   }
   if (isspace(str[i])){
      str[i] = 95;
   }


}

}
