#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include <limits.h>
#define INF INT_MAX
//Matrix
Graph* createGraph(){
    int i, j, oriented;
    Graph *g = (Graph*)malloc(sizeof(Graph));
    if(g==NULL)
        {
            printf("Error while allocation graph\n");
            return NULL;
        }
    printf("How many vertices do the graph have? ");
    scanf("%d", &(g->V));
    printf("\n");
    g->a = (int**)malloc(g->V*sizeof(int));
    for(i = 0; i < g->V; i++) 
        g->a[i] = (int*)calloc(g->V, sizeof(int));
    if(g->a==NULL){
        printf("Error while allocation matrix");
        return NULL;
    }
    g->E = 0;
    printf("Is the graph oriented ? 1/0 [Yes/No]\n");
    scanf("%d", &oriented);
    if(oriented == 0)
    {
        for(i = 0; i < g->V; i++)
            for(j = 0; j < i; j++)
                {
                    printf("Is there edge between %d and %d ? 1/0 [Yes/No] ",i ,j);
                    scanf("%d", &(g->a[i][j]));
                    g->a[j][i] = g->a[i][j];
                    if(g->a[i][j] == 1)
                        g->E += 2;
                }
    }
    else{
         {
        for(i = 0; i < g->V; i++)
            for(j = 0; j < g->V; j++)
                {
                    printf("Is there edge between %d and %d ? 1/0 [Yes/No] ", i , j);
                    scanf("%d", &(g->a[i][j]));
                    if(g->a[i][j] == 1)
                        g->E ++;
                }
         }
    }
    return g;
    
}

void printGraph(Graph* g)
{
    for(int i = 0; i < g->V; i++)
        {
            for(int j = 0; j < g->V; j++)
                printf("%d ", g->a[i][j]);
            printf("\n");
        }
}

int** RoyWarshallEdges(int **a, int V){
    int **d = (int**)malloc(sizeof(int*)*V);
    for(int i = 0; i < V; i++)
        d[i] = (int*)malloc(sizeof(int)*V);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            d[i][j] = a[i][j];
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if(i != j && d[i][j] == 0 && a[i][k]== 1 && a[k][j] == 1)
                    d[i][j] = 1;
    return d;
}
int** RoyWarshallCosts(int **a, int V){
    int **d = (int**)malloc(sizeof(int*)*V);
    for(int i = 0; i < V; i++)
        d[i] = (int*)malloc(sizeof(int)*V);
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(a[i][j])
                d[i][j] = a[i][j];
            else if(i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
    return d;
}
//lists for oriented graphs
GraphList* createGraphList(){
    int next, val;
    GraphList *g = (GraphList*)malloc(sizeof(GraphList));
    if(g == NULL){
        printf("Error for allocating the graph");
        return NULL;
    }
    printf("How many vertices do the graph have ? ");
    scanf("%d", &(g->V));
    printf("\n");
    g->a = (Node**)malloc(g->V*sizeof(Node*));
    for (int i=0; i<g->V;i++) {
        printf( "Give the value of vertex for position %d \n",i);
        scanf("%d",&val);
        Node * newnode=(Node*)malloc(sizeof(Node));
        newnode->vertex_no =val;
        newnode->next=NULL;
        g->a[i]=newnode;
    }
    g->E = 0;
    for (int i=0;i<g->V;i++) {
    printf( "Give the vertices that are after %d \n",g->a[i]->vertex_no );
    next=0;
    Node *p = g->a[i]; 
    while (next==0) { 
    printf( "Is there another vertex ? Yes=0, No - something else "); scanf(" %d", &next);
    if (next ==0){
    printf( "Who is the next vertex ?\n"); scanf ("%d", &val);
    Node * newnode=(Node*)malloc(sizeof(Node));
    newnode->vertex_no =val;
    newnode->next=NULL;
    p->next = newnode; 
    p = p->next ; 
    g->E++; 
            }
        }
    }

    return g;
}

void printGraphList(GraphList *g){
    int i, j;
    for (i=0;i<g->V;i++) 
    {
    while (g->a[i]!=NULL) {
        printf( "%d ",g->a[i]->vertex_no);
        g->a[i] = g->a[i]->next;
    }
    printf("\n");
    }
}
