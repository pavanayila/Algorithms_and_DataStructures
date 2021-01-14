// Queue - Simple Circular array implementation.
#include<stdio.h>
#include<stdlib.h>
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
void Print(struct ArrayQueue *Q)
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
int main()
{
    struct ArrayQueue *A = Queue(10);
    EnQueue(A, 10);
    Print(A);
    EnQueue(A, 20);
    Print(A);
    EnQueue(A, 30);
    Print(A);
    EnQueue(A, 40);
    Print(A);
    DeQueue(A);
    Print(A);
    DeQueue(A);
    Print(A);
    DeQueue(A);
    Print(A);
    DeleteQueue(A);


    return 0;
}

/*
Queue is : 10 <--
Queue is : 10 <-- 20 <--
Queue is : 10 <-- 20 <-- 30 <--
Queue is : 10 <-- 20 <-- 30 <-- 40 <--
Queue is : 20 <-- 30 <-- 40 <--
Queue is : 30 <-- 40 <--
Queue is : 40 <--
*/
