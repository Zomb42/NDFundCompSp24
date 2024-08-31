#include <stdio.h>

int get_gcd(int, int);


int a, b;
int main(){


        
printf("Enter 2 numbers. This program will find the gcd");
        scanf("%d %d", &a, &b);

        printf("The GCD is %d\n", get_gcd(a, b));


}

int get_gcd(int x, int y){
        int g, gcd;
        if (x >y){
                g = y;
        }else{
                g = x;
        }

        for (int i = g; i> 0; i--){
                if ((x % i == 0) && (y % i == 0)){
                        gcd = i;
                        break;

                }
                
        }
return gcd;
}
