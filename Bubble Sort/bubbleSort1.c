#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int A[], int n)
{
  int flag;
  for (int i = 0; i < n - 1; i++)
  {
    flag = 0;
    for (int j = 0; j < n - 1 - i; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(&A[j], &A[j + 1]);
        flag = 1;
      }
    }
    if (flag == 0)
      break;
  }
}

int main()
{
  int n;
  printf("Enter the size of an array : ");
  scanf("%d", &n);
  int A[n];

  printf("Enter %d elements to be sorted in a array : ", n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &A[i]);
  }
  bubbleSort(A, n);

  printf("The sorted Array elements : ");
  bubbleSort(A, n);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  return 0;
}