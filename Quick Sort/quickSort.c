#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int A[], int l, int h)
{
  int pivot = A[l];
  int i = l;
  int j = h;

  do
  {
    do
    {
      i++;
    } while (A[i] <= pivot);

    do
    {
      j--;
    } while (A[j] > pivot);

    if (i < j)
    {
      swap(&A[i], &A[j]);
    }
  } while (i < j);

  swap(&A[l], &A[j]);
  return j;
}

void quickSort(int A[], int l, int h)
{
  if (l < h)
  {
    int pivotIndex = partition(A, l, h);
    quickSort(A, l, pivotIndex);
    quickSort(A, pivotIndex + 1, h);
  }
}

void getUserInput(int A[], int n)
{
  printf("Enter %d elements to array: ", n);
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &A[i]) != 1)
    {
      printf("Invalid Input. Please enter integer values only.\n");
      exit(EXIT_FAILURE);
    }
  }
}

void printArray(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  int n;
  printf("Enter the size of an array: ");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid size of an array. Please enter a non-negative integer.\n");
    return EXIT_FAILURE;
  }

  int *A = (int *)malloc(n * sizeof(int));
  if (A == NULL)
  {
    printf("Memory Allocation failed\n");
    return EXIT_FAILURE;
  }

  getUserInput(A, n);
  printf("Original Array: ");
  printArray(A, n);

  quickSort(A, 0, n);

  printf("Sorted Array: ");
  printArray(A, n);

  free(A);

  return 0;
}
