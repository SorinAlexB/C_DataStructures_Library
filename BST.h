#ifndef BSTLib
#define BSTLib
typedef struct Node{
    int value;
    struct Node *left, *right;
}Node;
Node* CreateRoot();
Node* InitBST();
void InorderPrint(Node* root);
#endif