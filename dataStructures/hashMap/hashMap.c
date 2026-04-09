#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* hashTable[MAX];

int hashFunction(int key){
    return key % MAX;
}

void push(int value) {
    int index = hashFunction(value);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void pop(int value) {
    int index = hashFunction(value);
    if(hashTable[index]->data == value) {
        Node* del_node = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        free(del_node);
        return;
    }

    Node* temp = hashTable[index];
    while(temp!=NULL) {
        if(temp->next->data == value) {
            Node* del_node = temp;
            temp->next = temp->next->next;
            free(temp->next);
            return;
        }
    }

    printf("%d not exists", value);
}

void display() {
    for(int i = 0;i < MAX;i++) {
        Node* temp = hashTable[i];
        while(temp != NULL) {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for(int i = 0;i < MAX;i++) {
        hashTable[i] = NULL;
    }
    push(11);push(29);push(66);push(55);push(23);
    push(18);push(15);push(57);push(23);push(24);push(16);
    display();
    pop(66);
    pop(15);
    display();
    return 0;
}
