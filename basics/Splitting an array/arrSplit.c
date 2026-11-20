#include<stdio.h>

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int arr1[5];
    int arr2[5];
    
    size_t length = sizeof(array) / sizeof(array[0]);
    
    printf("Size of Parent array:- %zu\n\n",length);
    
    printf("Parent Array:- ");
    for(int i = 0;i < length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    
    for(int i = 0;i < length/2;i++){
        arr1[i] = array[i];
    }
    printf("First Child Array:- ");
    for(int i = 0;i < length/2;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int i = length/2;i < length;i++){
        arr2[i] = array[i];
    }
    printf("Second Child Array:- ");
    for(int i = length/2;i < length;i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
    return 0;
}
