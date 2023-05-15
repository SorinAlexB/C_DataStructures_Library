#ifndef QueueLib
#define QueueLib
typedef struct NodeQueue{
    int data;
    struct NodeQueue *prev, *next;
}NodeQueue;
typedef struct DoubleLinkedListQueue{
    NodeQueue *head;
    NodeQueue *tail;
}DoubleLinkedListQueue;
void CreateQueue(DoubleLinkedListQueue *Queue);
void pushQueue(DoubleLinkedListQueue *Queue, int data);
void popQueue(DoubleLinkedListQueue *Queue);
int backQueue(DoubleLinkedListQueue *Queue);
int frontQueue(DoubleLinkedListQueue *Queue);
int sizeQueue(DoubleLinkedListQueue *Queue);
int isEmptyQueue(DoubleLinkedListQueue *Queue);
#endif