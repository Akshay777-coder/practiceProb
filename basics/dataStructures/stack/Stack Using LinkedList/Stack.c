#include <stdio.h>
#include <stdlib.h>

/* 
   Stack implementation using Linked List
   - Push  : Insert at beginning (O(1))
   - Pop   : Delete from beginning (O(1))
   - Peek  : View top element
*/

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;   // Points to top of stack
static int length = 0;     // Maintains stack size in O(1)

/* Create a new node */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

/* Push element onto stack */
void push(int value) {
    struct Node* newNode = createNode(value);

    if (newNode == NULL)  // Safety check
        return;

    newNode->next = top;  // New node points to current top
    top = newNode;        // Update top
    length++;             // Increase size
}

/* Pop element from stack */
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    top = top->next;  // Move top to next node
    free(temp);       // Free memory
    length--;         // Decrease size
}

/* View top element */
void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

/* Check if stack is empty */
int isEmpty() {
    return (length == 0);
}

/* Return stack size */
int size() {
    return length;
}

/* Display stack elements */
void display() {
    struct Node* temp = top;

    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Driver Code */
int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    display();

    pop();
    display();

    peek();

    printf("Size of stack: %d\n", size());

    if (isEmpty())
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");

    return 0;
}
