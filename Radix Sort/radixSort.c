#include <stdio.h>
#include <stdlib.h>

void getUserInput(int A[], const int n);
void printArray(int A[], const int n);
void radixSort(int A[], const int n);
int main()
{
  int n;
  printf("enter the size of an array \n");
  if (scanf("%d", &n) != 1 || n < 0)
  {
    printf("Invalid size of an arary. Please enter the proper size of an array\n");
    return EXIT_FAILURE;
  }

  int *A;
  A = (int *)malloc(n * sizeof(n));
  if (A == NULL)
  {
    printf("Memory Allocation failed..\n");
    return EXIT_FAILURE;
  }

  getUserInput(A, n);
  printf("Orginal Array : ");
  printArray(A, n);

  radixSort(A, n);

  printf("Sorted Array : ");
  printArray(A, n);
  free(A);
  return 0;
}

void getUserInput(int A[], const int n)
{
    printf("Enter %d elements for array need to be sorted : ", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &A[i]) != 1)
        {
            printf("Invalid input. Please enter integer value only \n");
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

// void radixSort(int A[], const int n)
// {
//   int *bin;
//   bin = (int *)malloc(sizeof(int) * 10);
//   if (bin == NULL)
//   {
//     printf("Memory Allocation Failed..\n");
//     exit(EXIT_FAILURE);
//   }

//   int max = A[0];
//   for (int i = 0; i < n; i++)
//   {
//     if (A[i] > max)
//     {
//       max = A[i];
//     }
//   }

//   for (int exp = 1; max / exp > 0; exp *= 10)
//   {
//     for (int i = 0; i < 10; i++)
//     {
//       bin[i] = 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//       bin[(A[i] / exp) % 10]++;
//     }
//     int i = 0;
//     for (int j = 0; j < 10; j++)
//     {
//       while (bin[j] > 0)
//       {
//         A[i++] = j;
//         bin[j]--;
//       }
//     }
//   }
//   free(bin);
// }

void radixSort(int A[], const int n)
{
    int *bin;
    bin = (int *)malloc(sizeof(int) * 10);
    if (bin == NULL)
    {
        printf("Memory Allocation Failed..\n");
        exit(EXIT_FAILURE);
    }

    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }

    for (int exp = 1; max / exp != 0; exp *= 10)
    {
        for (int i = 0; i < 10; i++)
        {
            bin[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            bin[(A[i] / exp) % 10]++;
        }

        int i = 0;
        for (int j = 0; j < 10; j++)
        {
            while (bin[j] > 0)
            {
                A[i++] = j * exp;  // Corrected line
                bin[j]--;
            }
        }
    }

    free(bin);
}

