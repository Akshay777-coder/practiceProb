#include<stdio.h>
#include<stdlib.h>

/* 
   Structure definition for a Node
   Each node contains:
   - data  → stores integer value
   - next  → pointer to next node
*/
struct Node {
    int data;
    struct Node* next;
};

/* 
   Global pointers:
   head   → points to first node
   tail   → points to last node
   length → stores size of list (O(1) access)
*/
struct Node* head = NULL;
struct Node* tail = NULL;
int length = 0;

/*
   Creates a new node dynamically
   Returns pointer to the created node
*/
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;   // assign data
    newNode->next = NULL;    // initially next is NULL

    return newNode;
}

/*
   Insert node at beginning
   Time Complexity: O(1)
*/
void push_front(int value) {
    struct Node* newNode = createNode(value);

    // If list is empty
    if(head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;  // new node points to old head
        head = newNode;        // head updated
    }

    length++;  // increase size
}

/*
   Insert node at end
   Time Complexity: O(1) because of tail pointer
*/
void push_back(int value) {
    struct Node* newNode = createNode(value);

    // If list is empty
    if(head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;  // old tail points to new node
        tail = newNode;        // update tail
    }

    length++;
}

/*
   Remove first node
   Time Complexity: O(1)
*/
void pop_front() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;   // store current head
    head = head->next;          // move head forward

    // If list becomes empty
    if(head == NULL)
        tail = NULL;

    free(temp);   // free memory
    length--;
}

/*
   Remove last node
   Time Complexity: O(n)
*/
void pop_back() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If only one node exists
    if(head == tail) {
        free(head);
        head = tail = NULL;
    } 
    else {
        struct Node* temp = head;

        // Traverse to second last node
        while(temp->next != tail)
            temp = temp->next;

        free(tail);        // free last node
        tail = temp;       // update tail
        tail->next = NULL; // last node points to NULL
    }

    length--;
}

/*
   Search element in list
   Returns index if found
   Returns -1 if not found
   Time Complexity: O(n)
*/
int search(int key) {
    struct Node* temp = head;
    int index = 0;

    while(temp != NULL) {
        if(temp->data == key)
            return index;

        temp = temp->next;
        index++;
    }

    return -1;
}

/*
   Returns size of linked list
   Time Complexity: O(1)
*/
int size() {
    return length;
}

/*
   Insert element at specific position
   Position starts from 0
   Time Complexity: O(n)
*/
void insert(int value, int pos) {

    // Check invalid position
    if(pos < 0 || pos > length) {
        printf("Invalid Position\n");
        return;
    }

    // Insert at beginning
    if(pos == 0) {
        push_front(value);
        return;
    }

    // Insert at end
    if(pos == length) {
        push_back(value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = head;

    // Traverse to (pos-1) node
    for(int i = 0; i < pos - 1; i++)
        temp = temp->next;

    // Adjust pointers
    newNode->next = temp->next;
    temp->next = newNode;

    length++;
}

/*
   Update value at specific position
   Time Complexity: O(n)
*/
void update(int value, int pos) {

    // Validate position
    if(pos < 0 || pos >= length) {
        printf("Invalid Position\n");
        return;
    }

    struct Node* temp = head;

    // Traverse to desired position
    for(int i = 0; i < pos; i++)
        temp = temp->next;

    temp->data = value;   // update data
}

/*
   Display entire linked list
*/
void display() {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/*
   Driver Code
*/
int main() {

    push_front(10);
    push_front(20);
    push_back(30);
    push_back(40);

    display();

    pop_front();
    insert(22,2);

    display();

    printf("Index of 30 is: %d\n", search(30));
    printf("Index of 67 is: %d\n", search(67));
    printf("Size of Linked list is: %d\n", size());

    update(99,3);
    display();

    return 0;
}
