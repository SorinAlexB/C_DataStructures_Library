#ifndef MatrixLib
#define MatrixLib
int* InitVectorMatrix(int *n, int *m);
int** Init2DMatrix(int *n, int *m);
int firstDsumVector(int *a, int n, int m);
int firstDsum2D(int **a, int n, int m);
void printVectorMatrix(int *a, int n, int m);
void print2DMatrix(int **a, int n, int m);
#endif