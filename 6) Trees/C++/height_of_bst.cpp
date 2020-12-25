// Binary Search Tree - Implementation in C++
#include<iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *GetNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;   // (*newNode).data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode *Insert(BstNode *root, int data)
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

bool Search(BstNode *root, int data)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

int FindMin(BstNode *root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->left == NULL)
    {
        return root->data;       // (*root).data
    }
    // search in left subtree
    return FindMin(root->left);  //
}

int FindMax(BstNode *root)
{
    if(root == NULL)
    {
        cout<<"Error: Tree is empty\n";
        return -1;
    }
    else if(root->right == NULL)
    {
        return root->data;       // (*root).data
    }
    // search in right subtree
    return FindMax(root->right);
}

int FindHeight(BstNode *root)
{
    if(root == NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
int main()
{
    BstNode *root; // pointer to root node
    root = NULL;   // setting tree as empty
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    cout<<"The Height is : "<<FindHeight(root)<<endl;
}

/*
The Height is : 2
*/
