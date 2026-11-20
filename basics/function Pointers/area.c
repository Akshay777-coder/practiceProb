#include<stdio.h>
#include<math.h>
#define PI 3.1415
float dx;
float dy;
float dist;

float Edistance(float x1,float y1,float x2,float y2){
    dx = (x2 - x1) * (x2 - x1);
    dy = (y2 - y1) * (y2 - y1);
    return dist = sqrt(dx + dy);
}

void AreaOfCircle(float x1,float y1,float x2,float y2,float (*fptr)(float,float,float,float)){
    float area = PI * fptr(x1,y1,x2,y2) * fptr(x1,y1,x2,y2);
    printf("Radius is: %.2f Units\n",fptr(x1,y1,x2,y2));
    printf("Area is: %.2f sq Units",area);
}

int main()
{
    printf("***Euclidian_distance to Circle_Area***\n\n");
    float x1,y1,x2,y2;
    printf("Enter the value for x1 and y1: ");
    scanf("%f %f",&x1,&y1);
    
    printf("Enter the value for x2 and y2: ");
    scanf("%f %f",&x2,&y2);
    
    printf("\n");
    
    float (*ptr)(float,float,float,float);
    ptr = &Edistance;
    AreaOfCircle(x1,y1,x2,y2,ptr);
    printf("\n");
    return 0;
}
