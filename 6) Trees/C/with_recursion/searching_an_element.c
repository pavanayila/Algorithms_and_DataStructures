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

// Searching an element in binary tree
int FindInBinaryTreeUsingRecursion(struct BstNode *root, int data)
{
    int temp;
    // Base case == empty tree, in that case, the data is not found so return false
    if(root == NULL)
        return 0;
    else
    {
        // see if found here
        if(data == root->data)
            return 1;
        else
        {
            // otherwise recur down the correct subtree
            temp = FindInBinaryTreeUsingRecursion(root->left, data);
            if(temp != 0)
                return temp;
            else
                return (FindInBinaryTreeUsingRecursion(root->right, data));
        }
    }
    return 0;
}

int main()
{
    int find;
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

    find = FindInBinaryTreeUsingRecursion(root, 20);
    printf("\nSearching element results %d", find);

    return 0;
}

/*
Searching element results 1
*/
