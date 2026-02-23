#include<stdio.h>
#define MAX 5

int Stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX - 1) {
        printf("OverFlow\n");
    }
    else{
        Stack[++top] = value;
    }
}

void pop() {
    if(top == -1){
        printf("UnderFlow\n");
    }
    else {
        printf("Popped %d\n",Stack[top--]);
    }
}

void display() {
    for(int i = top;i >= 0;i--) {
        printf("%d ",Stack[i]);
    }
    printf("\n");
}
int main() {
    push(10);push(20);push(30);
    display();
    pop();
    display();
    return 0;
}
