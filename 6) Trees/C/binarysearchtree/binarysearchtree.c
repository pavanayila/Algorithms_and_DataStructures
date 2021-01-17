#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// To create BST node
struct node *create(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;

    return temp;
}

void postorder(struct node *node)
{
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
}

void inorder(struct node *node)
{
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
}

void preorder(struct node *node)
{
    if(node == NULL)
        return;
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
}

// to insert a node in bst
struct node *insert(struct node *node, int key)
{
    if(node == NULL)
        return create(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    return node;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    return 0;
}

/*
20 30 40 50 60 70 80
*/
