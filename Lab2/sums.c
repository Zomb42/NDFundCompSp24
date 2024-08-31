#include <stdio.h>
#include <math.h>


int main() {

int num, fsum = 0;
float ssum = 0;

printf("Enter num\n");

scanf("%d", &num);

for (int i = 1; i <= num; i++){
fsum = fsum + (i*i);
ssum = ssum + sqrt(i);

}

printf("%d is the sum of squares, %f is the sum of roots\n", fsum, ssum);


}
