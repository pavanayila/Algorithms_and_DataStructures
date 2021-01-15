#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = malloc(sizeof(struct BstNode));
    newNode->data = data;   // (*newNode).data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct BstNode *Insert(struct BstNode *root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

struct BstNode *MirrorOfBinaryTree(struct BstNode *root)
{
    struct BstNode *temp;
    if(root)
    {
        MirrorOfBinaryTree(root->left);
        MirrorOfBinaryTree(root->right);
        // swap the pointers in this node
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return root;
}

void PreOrder(struct BstNode *root)
{
    if(root)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void InOrder(struct BstNode *root)
{
    if(root)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
void PostOrder(struct BstNode *root)
{
    if(root)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    printf("Before Mirroring ");
    printf("\nInOrder : ");
    InOrder(root);
    printf("\nPreOrder : ");
    PreOrder(root);
    printf("\nPostOrder : ");
    PostOrder(root);

    printf("\n\nAfter Mirroring");
    root = MirrorOfBinaryTree(root);
    printf("\nInOrder : ");
    InOrder(root);
    printf("\nPreOrder : ");
    PreOrder(root);
    printf("\nPostOrder : ");
    PostOrder(root);




    return 0;
}


/*
Before Mirroring
InOrder : 8 10 12 15 20 25
PreOrder : 15 10 8 12 20 25
PostOrder : 8 12 10 25 20 15

After Mirroring
InOrder : 25 20 15 12 10 8
PreOrder : 15 20 25 10 12 8
PostOrder : 25 20 12 8 10 15
*/
