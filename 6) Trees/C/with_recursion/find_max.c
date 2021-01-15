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

// Find max element in a binary tree with recursion.
int FindMax(struct BstNode *root)
{
    int root_val, left, right, max = 0;
    if(root != NULL)
    {
        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);
        // Find the largest of the three values.
        if(left > right)
            max = left;
        else
            max = right;
        if(root_val > max)
            max = root_val;
    }
    return max;
}

int main()
{
    int max;
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    max = FindMax(root);
    printf("Maximum element in the binary tree is %d ", max);

    return 0;
}
/*
Maximum element in the binary tree is 25
*/
