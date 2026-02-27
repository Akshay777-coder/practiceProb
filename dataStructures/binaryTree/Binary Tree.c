#include <stdio.h>
#include <stdlib.h>

/* 
   Structure of a Binary Tree Node
   - data  : stores integer value
   - left  : pointer to left child
   - right : pointer to right child
*/
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* 
   Function to create a new node
   Allocates memory dynamically
*/
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/* 
   Global index variable used while building tree
   It moves forward in preorder array
*/
static int idx = -1;

/* 
   Function to build tree using preorder traversal
   -1 represents NULL node
*/
struct Node* buildTree(int preorder[]) {
    idx++;

    // If current value is -1 → no node here
    if (preorder[idx] == -1)
        return NULL;

    // Create node with current value
    struct Node* root = createNode(preorder[idx]);

    // Recursively build left subtree
    root->left = buildTree(preorder);

    // Recursively build right subtree
    root->right = buildTree(preorder);

    return root;
}

/* Preorder Traversal
   Root → Left → Right
*/
void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

/* Inorder Traversal
   Left → Root → Right
*/
void inOrder(struct Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

/* Postorder Traversal
   Left → Right → Root
*/
void postOrder(struct Node* root) {
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

/* 
   Level Order Traversal (Breadth First Search)
   Uses Queue (FIFO)
*/
void levelOrder(struct Node* root) {

    if (root == NULL)
        return;

    // Array-based queue (can store up to 100 nodes)
    struct Node* queue[100];
    int front = 0;
    int rear = 0;

    // Step 1: Insert root into queue
    queue[rear++] = root;

    // Step 2: Process nodes until queue becomes empty
    while (front < rear) {

        // Remove node from front of queue
        struct Node* current = queue[front++];

        // Print current node data
        printf("%d ", current->data);

        // Insert left child into queue (if exists)
        if (current->left != NULL)
            queue[rear++] = current->left;

        // Insert right child into queue (if exists)
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

/* -------------------- MAIN FUNCTION -------------------- */

int main() {

    /* 
       Preorder array representation of tree
       -1 means NULL
    */
    int preorder[] = {1,2,-1,3,-1,-1,4,-1,5,-1,-1};

    // Build the tree
    struct Node* root = buildTree(preorder);

    printf("PreOrder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("InOrder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("PostOrder Traversal: ");
    postOrder(root);
    printf("\n");

    printf("LevelOrder Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
