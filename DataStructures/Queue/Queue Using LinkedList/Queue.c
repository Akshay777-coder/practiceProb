#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

/* Enqueue - O(1) */
void enqueue(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* Dequeue - O(1) */
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued: %d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

/* Peek */
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n", front->data);
}

/* Display */
void display() {
    struct Node* temp = front;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Main Function */
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Queue after enqueue operations:\n");
    display();

    dequeue();
    dequeue();

    printf("Queue after dequeue operations:\n");
    display();

    peek();

    return 0;
}
