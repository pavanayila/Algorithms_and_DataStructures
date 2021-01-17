#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Skeleton for stack
struct Stack
{
    int top;
    unsigned size;
    int *arr;
};

// To create stack
struct Stack *Create(unsigned size)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->size - 1;
}

// empty when is top is -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// to add an item to stack
void push(struct Stack *stack, int item)
{
    if(isFull(stack))
        return;
    stack->arr[++stack->top] = item;
}

// to remove an item to stack
int pop(struct Stack *stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

// to get the top element
int peek(struct Stack *stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

int main()
{
    struct Stack *stack = Create(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("%d popped\n", pop(stack));
    printf("%d popped\n", pop(stack));
    (isEmpty(stack) == -1)?printf("empty"):printf("not empty");

    return 0;
}
/*
30 popped
20 popped
not empty
*/
