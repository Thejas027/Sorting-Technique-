#include <stdio.h>
#include <stdlib.h>

void getUserInput(int A[], const int n);
void printArray(const int A[], const int n);
int findMax(const int A[], int n);
void countSort(int A[], int n);

int main()
{
  int n;

  printf("Enter the size of an array: ");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid array size. Please enter a positive array size.\n");
    return EXIT_FAILURE;
  }

  int *A = (int *)malloc(n * sizeof(int));
  if (A == NULL)
  {
    printf("Memory allocation failed.\n");
    return EXIT_FAILURE;
  }

  getUserInput(A, n);
  printf("Original Array: ");
  printArray(A, n);

  countSort(A, n);

  printf("Sorted Array: ");
  printArray(A, n);

  free(A);

  return 0;
}

void getUserInput(int A[], const int n)
{
  printf("Enter %d elements to be sorted:\n", n);
  for (int i = 0; i < n; i++)
  {
    if (scanf("%d", &A[i]) != 1)
    {
      printf("Invalid Input. Please enter integer values only.\n");
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

int findMax(const int A[], int n)
{
  int max = -1;
  for (int i = 0; i < n; i++)
  {
    if (A[i] > max)
    {
      max = A[i];
    }
  }
  return max;
}

void countSort(int A[], int n)
{
  int max = findMax(A, n);
  int *C = (int *)malloc((max + 1) * sizeof(int));

  if (C == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }

  // Initialize count array C
  for (int i = 0; i < max + 1; i++)
    C[i] = 0;

  // Count occurrences of each element in the input array
  for (int i = 0; i < n; i++)
    C[A[i]]++;

  // Update the original array using the count array
  int i = 0, j = 0;
  while (i < n && j <= max)
  {
    while (C[j] > 0)
    {
      A[i++] = j;
      C[j]--;
    }
    j++;
  }

  // Free the memory allocated for the count array
  free(C);
}
