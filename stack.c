#include <stdlib.h>
#include <stdio.h>  
#include "stack.h"

void push(int *stack, int *peak, int number)
{
   stack[*peak] = number;
   *peak = *peak + 1;
}

void pop(int *peak)
{
    *peak = *peak - 1;
}

int isEmpty(int peak)
{
    if( peak == -1 )
        return 0;
    return 1;
} 

int isFull(int peak, int max)
{
    if( peak == max)
        return 1;
    return 0;

}

int TopStack(int *stack, int peak)
{
    if(peak != 0)
        return stack[peak-1];
    exit(1);
}

int* allocStack(int max)
{
    int *stack = (int*)calloc(max, sizeof(int));
    return stack;
}