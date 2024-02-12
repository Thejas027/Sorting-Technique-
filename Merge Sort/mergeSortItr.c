#include <stdio.h>
#include <stdlib.h>

void getUserInput(int A[], const int n)
{
  printf("Enter %d elements to be sorted:\n", n);
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &A[i]) != 1)
    {
      printf("Invalid Input. Please enter integer value only.\n");
      exit(EXIT_FAILURE);
    }
  }
}

void printArray(int A[], const int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void merge(int A[], int l, int mid, int h)
{
  int i = l, j = mid + 1, k = l;
  int B[100];

  while (i <= mid && j <= h)
  {
    if (A[i] <= A[j])  // Change the condition from < to <=
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }

  while (i <= mid)  // Copy the remaining elements from the left subarray
    B[k++] = A[i++];

  while (j <= h)  // Copy the remaining elements from the right subarray
    B[k++] = A[j++];

  for (i = l; i <= h; i++)
    A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
  int i, p, l, mid, h;
  for (p = 2; p <= n; p = p * 2)
  {
    for (i = 0; i + p - 1 <= n; i = i + p)
    {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;
      merge(A, l, mid, h);
    }
  }
  if (p / 2 < n)
    merge(A, 0, p / 2, n - 1);
}

int main()
{
  int n;
  printf("Enter the size of an array: ");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid array size. Please enter a non-negative integer.\n");
    return EXIT_FAILURE;
  }

  int *A = (int *)malloc(n * sizeof(int));
  if (A == NULL)
  {
    printf("Memory Allocation Failed.\n");
    return EXIT_FAILURE;
  }

  getUserInput(A, n);
  printf("Original Array: ");
  printArray(A, n);

  IMergeSort(A, n);

  printf("Sorted Array: ");
  printArray(A, n);

  free(A);

  return 0;
}
