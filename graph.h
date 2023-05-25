#ifndef GraphLib
#define GraphLib
//Matrix
typedef struct{
    int V, E; // number of vertices and edges
    int **a; // the matrix
}Graph;
Graph* createGraph();
void printGraph(Graph *g);
int** RoyWarshallEdges(int **a, int V);
int** RoyWarshallCosts(int **a, int V);
//List
typedef struct Node{
    int vertex_no;
    struct Node* next;
}Node;
typedef struct{
    int V, E; // number of vertices and edges
    Node **a; // the matrix
}GraphList;
GraphList* createGraphList();
void printGraphList(GraphList *g);
#endif 