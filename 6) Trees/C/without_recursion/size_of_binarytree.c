#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 10
struct ArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};
struct ArrayQueue *Queue(int size)
{
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q)
        return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}
int IsEmptyQueue(struct ArrayQueue *Q)
{
    // If the condition is true then 1 is returned else 0 is returned.
    return (Q->front == -1);
}
int IsFullQueue(struct ArrayQueue *Q)
{
    // If the condition is true then 1 is returned else 0 is returned.
    return ((Q->rear + 1) % Q->capacity == Q->front);
}
int QueueSize(struct ArrayQueue *Q)
{
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}
void EnQueue(struct ArrayQueue *Q, int data)
{
    if(IsFullQueue(Q))
        printf("Queue Overflow");
    else
    {
        Q->rear = (Q->rear+1)%Q->capacity;
        Q->array[Q->rear] = data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
}
int DeQueue(struct ArrayQueue *Q)
{
    int data = 0; // or element which does not exist in queue
    if(IsEmptyQueue(Q))
    {
        printf("Queue is empty");
        return 0;
    }
    else
    {
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front = (Q->front+1) % Q->capacity;
    }
    return data;

}
void DeleteQueue(struct ArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}
void PrintQueue(struct ArrayQueue *Q)
{
    int i;
    if(IsEmptyQueue(Q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue is : ");
        for(i=Q->front; i<=Q->rear; i++)
        {
            printf("%d <-- ", Q->array[i]);
        }
    }
}
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

// Size of binary tree.
// compute the number of nodes in a tree.
int SizeOfBTUsingLevelOrder(struct BstNode *root)
{
    struct BstNode *temp;
    struct ArrayQueue *Q;
    int count = 0;
    if(!root)
        return 0;
    Q = Queue(10);
    EnQueue(Q, root);
    while(!IsEmptyQueue(Q))
    {
        temp = DeQueue(Q);
        count++;
        if(temp->left)
            EnQueue(Q, temp->left);
        if(temp->right)
            EnQueue(Q, temp->right);
    }
    DeleteQueue(Q);
    return count;
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
    size = SizeOfBTUsingLevelOrder(root);
    printf("\nNo of nodes in a binary tree is %d ", size);

    return 0;
}

/*
No of nodes in a binary tree is 6
*/
