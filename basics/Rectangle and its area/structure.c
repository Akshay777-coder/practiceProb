#include<stdio.h>

//making a Class Using Structure
struct Rectangle{
    float length;
    float width;
};

//Initialising the value using "initialise_value" method with the help of pointers
void initialise_value(struct Rectangle *r,float l,float w){
    r->length = l;
    r->width = w;
}

//Displaying the values using "display" method
float Display(struct Rectangle *r){
    printf("Length is: %.2f\n",r->length);
    printf("Width is: %.2f\n",r->width);
    printf("Area is: %.2f\n\n",r->length * r->width);
}

int main()
{
    //defining the object for with our class
    struct Rectangle r1;
    
    //storing the values using "initialise_value" method
    initialise_value(&r1,15.22,9.67);
    
    //displaying the values using "Display" method
    Display(&r1);
    
    return 0;
}
