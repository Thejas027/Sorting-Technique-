#include <stdio.h>
#include <stdlib.h>
void insertionSort(int A[], const int n)
{
  for (int i = 0; i < n; i++)
  {
    int j = i - 1;
    int x = A[i];
    while (j > -1 && A[j] > x)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = x;
  }
}

void getUserInput(int A[], const int n)
{
  printf("Enter %d elements to be sorted : \n", n);
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &A[i]) != 1)
    {
      printf("Invalid Input.please enter integer value only..\n");
      exit(EXIT_FAILURE);
    }
  }
}

void printArray(const int A[], const int n)
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
  printf("Enter the size of an array :");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid array size . Please Enter the positive array size\n");
    return EXIT_FAILURE;
  }

  int *A = (int *)malloc(n * sizeof(int));
  if (A == NULL)
  {
    printf("memory Allocation Failed...\n");
    return EXIT_FAILURE;
  }

  getUserInput(A, n);
  printf("Orginal Array : ");
  printArray(A, n);

  insertionSort(A, n);

  printf("Sorted Array : ");
  printArray(A, n);

  free(A);
  return 0;
}