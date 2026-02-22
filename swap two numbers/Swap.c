#include <stdio.h>

void swap(int* x,int* y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a,b;
    printf("Enter the value of a and b: ");
    scanf("%d %d",&a,&b);
    
    printf("Before Swapped: a: %d, b: %d\n",a,b);
    swap(&a,&b);
    printf("After Swapped: a: %d, b: %d\n",a,b);
    
    return 0;
}
