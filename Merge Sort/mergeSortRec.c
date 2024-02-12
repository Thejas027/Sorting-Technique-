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
  int B[h + 1];

  while (i <= mid && j <= h)
  {
    if (A[i] <= A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }
  while (i <= mid)
    B[k++] = A[i++];
  while (j <= h)
    B[k++] = A[j++];

  for (i = l; i <= h; i++)
    A[i] = B[i];
}

void RMergeSort(int A[], int l, int h)
{
  int i = l, j = h;
  if (i < j)
  {
    int mid = (l + h) / 2;
    RMergeSort(A, l, mid);
    RMergeSort(A, mid + 1, h);
    merge(A, l, mid, h);
  }
}

int main()
{
  int n;
  printf("enter the size of an array : ");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid size of an array.Please enter the positive array size\n");
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

  RMergeSort(A, 0, n);

  printf("Sorted Array: ");
  printArray(A, n);

  free(A);
  return 0;
}