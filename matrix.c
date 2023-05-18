#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
int* InitVectorMatrix(int *n, int *m)
{
    printf("Give two numbers for [rows] and [columns] : ");
    scanf("%d %d", n, m);
    int *a = (int*)calloc((*n)*(*m), sizeof(int));
    printf("\nNow give us %d * %d numbers to form the matrix\n", *n, *m);
    for(int i = 0; i < (*n)*(*m); i++)
        scanf("%d", (a+i));
    return a;
}
void printVectorMatrix(int *a, int n, int m){
    for(int i = 0; i < n * m; i++)
        { 
          printf("%d ", a[i]);
          if((i+1) % m == 0)
            printf("\n");  
        }
}
int** Init2DMatrix(int *n, int *m)
{
  printf("Give two numbers for [rows] and [columns] : ");
  scanf("%d %d", n, m);
  int **a = (int**)malloc((*n) * (*m) * sizeof(int*));
  for(int i = 0; i < *n; i++)
    a[i] = (int*)malloc((*m) * sizeof(int));
  printf("\nNow give us %d * %d numbers to form the matrix\n", *n, *m);
  for(int i = 0; i < *n; i++)
    for(int j = 0; j < *m; j++)
        scanf("%d", &a[i][j]);
  return a;
}

void print2DMatrix(int **a, int n, int m){
    for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
}

int firstDsumVector(int *a, int n, int m){
    int s = 0;
    if(n!=m)
        return 0;
    for(int i = 0; i < n * m; i+=n+1)
        s += a[i];
    return s;
}

int firstDsum2D(int **a, int n, int m)
{
    int s = 0;
    if(n == m)
        return 0;
    for(int i = 0; i < n*m; i++)
        s+=a[i][i];
    return s;
}