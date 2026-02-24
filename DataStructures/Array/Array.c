#include <stdio.h>

void insert(int arr[],int n, int pos, int value) {
    for(int i = n-1;i >= pos;i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = value;
}

void delete(int arr[],int n, int pos) {
    for(int i = pos;i <= n;i++) {
        arr[i] = arr[i+1];
    }
}

void update(int arr[],int n, int pos,int value) {
    arr[pos] = value;
}

void display(int arr[], int n) {
    for(int i = 0;i < n;i++) {
        if(arr[i] == 0) {
            break;
        }else{
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

int main() {    
    int arr[10] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    insert(arr, n, 2, 11);
    insert(arr, n, 2, 12);
    display(arr, n);
    delete(arr, n, 2);
    display(arr, n);
    update(arr, n, 2, 100);
    display(arr, n);
    return 0;
}
