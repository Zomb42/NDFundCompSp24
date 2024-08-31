//polar.c      Derick Shi

#include <stdio.h>
#include <math.h>

int get_quadrant(double, double);   //prototype functions
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);


double x, y;
int main(){


        printf("Enter the X and Y coordinates of a point in a normal cartesian plane\n");
        scanf("%lf %lf", &x , &y);//input

        show_info(get_quadrant(x,y), x, y); //displays information 



        return 0;
}


int get_quadrant(double a, double b){
        if (a<-1){
                if (b<-1){
                        return 3;

                }else{
                        return 2; //conditionals to find quadrant

                }
        }else{
                if (b<-1){
                        return 4;
                }
                return 1;

        }
}


double get_radius(double a, double b){

        return sqrt(a* a + b * b); //radius formula



}


double get_angle(double a, double b){

        return (atan2(a, b) * 180 )/M_PI; //get degrees in radians then convert to degrees



}

void show_info(int c, double a, double b){
        printf("Quadrant is %d\n", get_quadrant(a,b)); //prints useful information
        printf("Radius is %0.2lf\n", get_radius(a, b));
        printf("Angle is %0.2lf in degrees\n", get_angle(a, b));


}
