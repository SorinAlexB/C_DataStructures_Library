#ifndef ListLib
#define ListLib
typedef struct Node{
    int data;
    struct Node *prev, *next;
}Node;
typedef struct DoubleLinkedList{
    Node *head;
    Node *tail;
}DoubleLinkedList;
void CreateList(DoubleLinkedList *list, int data);
void AddNodeAtBeginning(DoubleLinkedList *list, int data);
void AddNodeAtFinal(DoubleLinkedList *list, int data);
void AddNodeAtPosition(DoubleLinkedList *list, int data, int pos);
void DeleteVal(DoubleLinkedList *list, int data);
void DeletePosition(DoubleLinkedList *list, int pos);
void DeleteList(Node *NewNode, Node *tail);
void printList(DoubleLinkedList *list);
#endif