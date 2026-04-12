/*
 * Hash Table with Chaining (Separate Chaining via Linked List)
 *
 * How it works:
 *   - An array of size MAX acts as the hash table.
 *   - Each slot in the array holds the head of a linked list (chain).
 *   - When two keys hash to the same index → they share a chain (collision handling).
 *
 * Operations:
 *   push(value)   → Insert a value into the hash table
 *   pop(value)    → Delete a value from the hash table
 *   display()     → Print all chains in the table
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10  /* Number of slots (buckets) in the hash table */

/* ─── Node Structure ──────────────────────────────────────────────────────── */

typedef struct Node {
    int data;           /* The actual value stored */
    struct Node* next;  /* Pointer to the next node in the chain */
} Node;

/* Global hash table: array of MAX linked list heads, all start as NULL */
Node* hashTable[MAX];

/* ─── Hash Function ───────────────────────────────────────────────────────── */

/*
 * hashFunction(key)
 * Maps any integer key to a valid index in [0, MAX-1]
 * using the modulo (%) operator.
 *
 * Example: key=23, MAX=10 → index = 23 % 10 = 3
 */
int hashFunction(int key) {
    return key % MAX;
}

/* ─── Push (Insert) ───────────────────────────────────────────────────────── */

/*
 * push(value)
 * Inserts `value` at the FRONT of the chain at its hash index.
 * Inserting at front is O(1) — no need to traverse the chain.
 *
 * Steps:
 *   1. Compute hash index
 *   2. Create a new node
 *   3. Point new node's next → current head of chain
 *   4. Update head of chain → new node
 */
void push(int value) {
    int index = hashFunction(value);

    /* Allocate memory for the new node */
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data  = value;
    newNode->next  = hashTable[index]; /* Point to current chain head */
    hashTable[index] = newNode;        /* New node becomes the new head */
}

/* ─── Pop (Delete) ────────────────────────────────────────────────────────── */

/*
 * pop(value)
 * Removes the FIRST occurrence of `value` from its chain.
 *
 * Cases:
 *   Case 1 → Value is at the head of the chain (easy removal)
 *   Case 2 → Value is somewhere in the middle/end (traverse to find it)
 *   Case 3 → Value not found → print message
 */
void pop(int value) {
    int index = hashFunction(value);
    Node* current = hashTable[index];

    /* Chain is empty at this index */
    if (current == NULL) {
        printf("%d not found\n", value);
        return;
    }

    /* Case 1: The head node itself holds the value */
    if (current->data == value) {
        hashTable[index] = current->next; /* Move head to next node */
        free(current);                    /* Free the old head */
        return;
    }

    /* Case 2: Traverse the chain to find the node BEFORE the target */
    while (current->next != NULL) {
        if (current->next->data == value) {
            Node* toDelete = current->next;        /* Node to remove */
            current->next  = toDelete->next;       /* Bypass it */
            free(toDelete);                        /* Free memory */
            return;
        }
        current = current->next;
    }

    /* Case 3: Value was not found in the chain */
    printf("%d not found\n", value);
}

/* ─── Display ─────────────────────────────────────────────────────────────── */

/*
 * display()
 * Prints every chain in the hash table in the format:
 *   index | val1 -> val2 -> NULL
 *
 * Empty chains show just "NULL".
 */
void display() {
    printf("\n--- Hash Table State ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%2d] | ", i);          /* Print the bucket index */
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    printf("------------------------\n");
}

/* ─── Main ────────────────────────────────────────────────────────────────── */

int main() {
    /* Step 1: Initialize all slots to NULL (empty chains) */
    for (int i = 0; i < MAX; i++) {
        hashTable[i] = NULL;
    }

    /* Step 2: Insert some values */
    push(11); push(29); push(66); push(55); push(23);
    push(18); push(15); push(57); push(23); push(24); push(16);

    printf("After insertions:");
    display();

    /* Step 3: Delete some values */
    pop(66);
    pop(15);

    printf("\nAfter deleting 66 and 15:");
    display();

    return 0;
}
