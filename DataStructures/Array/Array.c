#include <stdio.h>

#define MAX 10   // Maximum size of array

/* Insert value at given position */
void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX) {
        printf("Array Overflow!\n");
        return;
    }

    if (pos < 0 || pos > *n) {
        printf("Invalid Position!\n");
        return;
    }

    // Shift elements to right
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;  // Insert value
    (*n)++;            // Increase size
}

/* Delete element from given position */
void deleteElement(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array Underflow!\n");
        return;
    }

    if (pos < 0 || pos >= *n) {
        printf("Invalid Position!\n");
        return;
    }

    // Shift elements to left
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;   // Decrease size
}

/* Update value at given position */
void update(int arr[], int n, int pos, int value) {
    if (pos < 0 || pos >= n) {
        printf("Invalid Position!\n");
        return;
    }

    arr[pos] = value;
}

/* Display array elements */
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX] = {1, 2, 3, 4, 5};
    int n = 5;  // Actual number of elements

    insert(arr, &n, 2, 11);
    insert(arr, &n, 2, 12);
    display(arr, n);

    deleteElement(arr, &n, 2);
    display(arr, n);

    update(arr, n, 2, 100);
    display(arr, n);

    return 0;
}
