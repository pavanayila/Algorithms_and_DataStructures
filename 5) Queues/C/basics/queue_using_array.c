#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Skeleton for queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// To create queue
struct Queue *CreateQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

// empty when size is 0
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

// to add an item to queue
void enqueue(struct Queue *queue, int item)
{
    if(isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size+1;
    printf("%d enqueued to queue\n", item);
}

// to remove an item from queue
int dequeue(struct Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size -1;
    return item;
}

// to get the first element
int front(struct Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// to get the last element
int rear(struct Queue *queue)
{
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main()
{
    struct Queue *queue = CreateQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("%d dequeued from queue\n\n", dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}
/*
10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
10 dequeued from queue

Front item is 20
Rear item is 30
*/
