#ifndef StackLib
#define StackLib
int* allocStack(int max);
void push(int *stack,  int *peak, int number);
void pop(int *peak);
int isEmpty(int peak);
int isFull(int peak, int max);
int TopStack(int *stack, int peak);
#endif

