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

// Height of the binary tree.
int HeightOfBinaryTree(struct BstNode *root)
{
    int leftheight, rightheight;
    if(root == NULL)
        return 0;
    else
    {
        // compute the depth of each subtree.
        leftheight = HeightOfBinaryTree(root->left);
        rightheight = HeightOfBinaryTree(root->right);

        if(leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}


int main()
{
    int height;
    struct BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    height = HeightOfBinaryTree(root);
    printf("\nHeight of the binary tree is %d", height);

    return 0;
}
/*
Height of the binary tree is 3
*/
