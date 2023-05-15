#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void CreateList(DoubleLinkedList *list, int data)
{
    list->head = (Node*)malloc(sizeof(Node));
    list->tail = (Node*)malloc(sizeof(Node));
    list->head->prev = NULL;
    list->tail->next = NULL;
    Node* NewNode = (Node*)malloc(sizeof(Node*));
    list->head->next = NewNode;
    list->tail->prev = NewNode;
    NewNode->prev = list->head;
    NewNode->next = list->tail;
    NewNode->data = data;
}


void printList(DoubleLinkedList *list)
{
    Node* current = list->head->next;
    while(current != list->tail)
        {
            printf("%d\n", current->data);
            current = current->next;
        }
}

void AddNodeAtBeginning(DoubleLinkedList *list, int data)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->prev = list->head;
    NewNode->next = list->head->next;
    list->head->next = NewNode;
}

void AddNodeAtFinal(DoubleLinkedList *list, int data)
{
   Node* NewNode = (Node*)malloc(sizeof(Node));
   NewNode->data = data;
   NewNode->next = list->tail;
   NewNode->prev = list->tail->prev;
   list->tail->prev = NewNode;
}

void AddNodeAtPosition(DoubleLinkedList *list, int data, int pos)
{
    Node* current = list->head->next;
    for(int i=0; i<pos; i++)  
        {
            if(current == list->tail)
                {

                    printf("%s", "I can't place a node here\n");
                    return;
                }
        }
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->next = current->next;
    NewNode->prev = current;
    current->next = NewNode;
    if( list->tail->prev == current )
        list->tail->prev = NewNode;

}

void DeleteVal(DoubleLinkedList *list, int data)
{
    Node *current = list->head->next, *pr = list->head, *trash;
    while ( current != list->tail )
    {
        if( current->data == data )
            {
                pr->next = current->next;
                current->next->prev = pr;
                trash = current;
                current = current->next;
                free(trash);
                pr = pr->next;
            }
        else
        {
            current = current->next;
            pr = pr->next;
        }
    }


}

void DeletePosition(DoubleLinkedList *list, int pos)
{
    int i = 0;
    Node *current = list->head->next, *pr = list->head, *trash;
    while ( current != list->tail && i<pos)
    {
        if( i == pos-1 )
            {
                pr->next = current->next;
                current->next->prev = pr;
                trash = current;
                current = current->next;
                free(trash);
                pr = pr->next;
                i++;
            }
        else
        {
            current = current->next;
            pr = pr->next;
            i++;
        }
    }

}


void DeleteList(Node *NewNode, Node *tail)
{
    if(NewNode != tail)
    {
        DeleteList(NewNode->next, tail);
        free(NewNode);
    }
    return;

}




