#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// skeleton for tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// To create tree
struct node *create(int data)
{
    // allocate memory for new node
    struct node *node = (struct node*)malloc(sizeof(struct node));

    // assign data to this node
    node->data = data;

    // initialize left and right children as null
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postorder(struct node *node)
{
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void inorder(struct node *node)
{
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct node *node)
{
    if(node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    struct node *root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    printf("\nPreorder ");
    preorder(root);
    printf("\nInorder ");
    inorder(root);
    printf("\nPostorder ");
    postorder(root);

    return 0;
}

/*
Preorder 1 2 4 3
Inorder 4 2 1 3
Postorder 4 2 3 1
*/
