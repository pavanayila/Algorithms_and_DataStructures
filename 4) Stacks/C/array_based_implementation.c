// Stack - Array based implementation.
// Creating a stack of integers.

#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE]; // integer array to store the stack
int top = -1;    // variable to mark top of stack in array

// Push operation to insert an element on top of stack.
void Push(int x)
{
    if(top == MAX_SIZE -1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    top++;
    A[top] = x;
}

// Pop operation to remove an element from top of stack.
void Pop()
{
    if(top == -1)
    {
        printf("Error: No element to pop\n");
    }
    top--;
}

// Top operation to return element at top of stack.
int Top()
{
    return A[top];
}

int Is_Empty()
{
    if(top == -1)
    {
        printf("Stack is Empty \n");
        return 1;
    }
    printf("Stack is not Empty");
    return 0;
}

void Print()
{
    int i;
    printf("Stack: ");
    for(i=0; i<=top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    Is_Empty();
    Push(1);
    Print();
    Push(2);
    Print();
    Push(3);
    Print();
    Pop();
    Print();
    Push(1);
    Print();
    Top();
    Is_Empty();

    return 0;
}


/*
Stack is Empty
Stack: 1
Stack: 1 2
Stack: 1 2 3
Stack: 1 2
Stack: 1 2 1
Stack is not Empty
*/
