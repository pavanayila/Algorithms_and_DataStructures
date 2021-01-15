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

// Size of the binary tree
// Compute the number of nodes in a tree
int SizeOfBinaryTree(struct BstNode *root)
{
    if(root == NULL)
        return 0;
    else
        return (SizeOfBinaryTree(root->left) + 1 + SizeOfBinaryTree(root->right));
}

int main()
{
    int size;
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    size = SizeOfBinaryTree(root);
    printf("\nNumber of nodes in the binary tree is %d ", size);

    return 0;
}
/*
Number of nodes in the binary tree is 6
*/
