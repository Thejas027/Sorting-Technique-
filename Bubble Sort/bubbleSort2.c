#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], const int n) {
    int flag;
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("Elements are already sorted\n");
            break;
        }
    }
}

void getUserInput(int A[], const int n) {
    printf("Enter %d elements to the array:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &A[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void printArray(const int A[], const int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }

    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    getUserInput(A, n);

    printf("Original array: ");
    printArray(A, n);

    bubbleSort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    free(A); // Free dynamically allocated memory

    return 0;
}
