#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
Node* CreateRoot(){
    Node *root = (Node*)malloc(sizeof(Node));
    root->left=NULL;
    root->right=NULL;
    return root;
}
Node* InitBST(){
    Node* root = CreateRoot();
    int val;
    printf("Give me a value : ");
    scanf("%d", &val);
    root->value = val;
    int answear;
    printf("\nDoes it have left node ? [1/0]\n");
    scanf("%d", &answear);
    printf("\n");
    if(answear == 1)
        root->left = InitBST();
    printf("\nDoes it have right node ? [1/0]\n");
    scanf("%d", &answear);
    printf("\n");
    if(answear == 1)
        root->right = InitBST();
    return root;
}

void InorderPrint(Node* root){
    if(root == NULL)
        return;  
    InorderPrint(root->left);
    printf("%d ", root->value);
    InorderPrint(root->right);
}