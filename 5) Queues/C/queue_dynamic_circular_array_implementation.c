// Queue - Simple Dynamic Circular array implementation.
#include<stdio.h>
#include<stdlib.h>
struct DynArrayQueue
{
    int front, rear;
    int capacity;
    int *array;
};
struct DynArrayQueue *CreateDynQueue()
{
    struct DynArrayQueue *Q = malloc(sizeof(struct DynArrayQueue));
    if(!Q)
        return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity * sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}
int IsEmptyQueue(struct DynArrayQueue *Q)
{
    // If the condition is true then 1 is returned else 0 is returned.
    return (Q->front == -1);
}
int IsFullQueue(struct DynArrayQueue *Q)
{
    // If the condition is true then 1 is returned else 0 is returned.
    return ((Q->rear + 1) % Q->capacity == Q->front);
}
int QueueSize(struct DynArrayQueue *Q)
{
    return (Q->capacity - Q->front + Q->rear + 1) % Q->capacity;
}
void EnQueue(struct DynArrayQueue *Q, int data)
{
    if(IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear+1)%Q->capacity;
    Q->array[Q->rear] = data;
    if(Q->front == -1)
        Q->front = Q->rear;
}
void ResizeQueue(struct DynArrayQueue *Q)
{
    int i;
    int size = Q->capacity;
    Q->capacity = Q->capacity * 2;
    Q->array = realloc(Q->array, Q->capacity);
    if(!Q->array)
    {
        printf("Memory Error");
        return;
    }
    if(Q->front > Q->rear)
    {
        for(i=0; i<Q->front; i++)
        {
            Q->array[i+size] = Q->array[i];
        }
    Q->rear = Q->rear + size;
    }
}
int DeQueue(struct DynArrayQueue *Q)
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
void DeleteQueue(struct DynArrayQueue *Q)
{
    if(Q)
    {
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}
void Print(struct DynArrayQueue *Q)
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
    struct DynArrayQueue *A = CreateDynQueue();
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
