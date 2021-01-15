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

// Sum of elements in binary tree.
int Add(struct BstNode *root)
{
    if(root == NULL)
        return 0;
    else
        return (root->data + Add(root->left) + Add(root->right));
}

int main()
{
    int sum;
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    sum = Add(root);
    printf("\nSum of the elements in binary tree is %d ", sum);

    return 0;
}
/*
Sum of the elements in binary tree is 90
*/
