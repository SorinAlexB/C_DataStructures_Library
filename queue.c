#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void CreateQueue(DoubleLinkedListQueue *Queue)
{
    Queue->head = (NodeQueue*)malloc(sizeof(NodeQueue));
    Queue->tail = (NodeQueue*)malloc(sizeof(NodeQueue));
    Queue->head->next = Queue->tail;
    Queue->head->prev = NULL;
    Queue->tail->prev = Queue->head;
    Queue->tail->next = NULL;
}
void pushQueue(DoubleLinkedListQueue *Queue, int data)
{
    NodeQueue *NewNode = (NodeQueue*)malloc(sizeof(NodeQueue));
    NewNode->data = data;
    Queue->tail->prev->next = NewNode;
    NewNode->prev = Queue->tail->prev;
    Queue->tail->prev = NewNode;
    NewNode->next = Queue->tail;
}
void popQueue(DoubleLinkedListQueue *Queue)
{
    NodeQueue *delete = Queue->head->next;
    Queue->head->next = delete->next;
    delete->next->prev = Queue->head;
    free(delete);
}
int backQueue(DoubleLinkedListQueue *Queue)
{
    return Queue->tail->prev->data;
}
int frontQueue(DoubleLinkedListQueue *Queue)
{
    return Queue->head->next->data;
}
int sizeQueue(DoubleLinkedListQueue *Queue)
{
    int ct = 0;
    NodeQueue *current = Queue->head->next;
    while(current != Queue->tail)
    {
        ct++;
        current = current->next;
    }
    return ct;
}
int isEmptyQueue(DoubleLinkedListQueue *Queue)
{
    if(Queue->head->next == Queue->tail)
        return 1;
    return 0;
}