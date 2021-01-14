// Stack - Simple Array based implementation.

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
struct ArrayStack
{
	int top;
	int capacity;
	int *array;
};
struct ArrayStack *CreateStack()
{
	struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
	if(!S)
		return NULL;
	S->capacity = MAXSIZE;
	S->top = -1;
	S->array = malloc(sizeof(S->capacity * sizeof(int)));
	if(!S->array)
		return NULL;
	return S;
}
int IsEmptyStack(struct ArrayStack *S)
{
	// if the condition is true then 1 is returned else 0 is returned.
	return (S->top == -1); 
}
int IsFullStack(struct ArrayStack *S)
{
	//if the condition is true then 1 is returned else 0 is returned.
	return (S->top == S->capacity - 1);
}
void Push(struct ArrayStack *S, int data)
{
	// S->top == capacity - 1 indicates that the stack is full
	if(IsFullStack(S))
		printf("Stack Overflow");
	else  // Increasing the top by 1 and storing the value at top position.
		S->array[++S->top] = data;
}
int Pop(struct ArrayStack *S)
{
	// S->top == - 1 indicates empty stack
	if(IsEmptyStack(S))
	{
		printf("Stack is Empty");
		return;
	}
	else  // Removing element from top of the array and reducing top by 1.
		return (S->array[S->top--]);

}
void DeleteStack(struct ArrayStack *S)
{
	if(S)
	{
		if(S->array)
		{
			free(S->array);
		}
		free(S);
	}
}
void Print(struct ArrayStack *S)
{
	int i;
	if(!S)
	{
		printf("Stack is empty");
		return;
	}
	else
	{
		printf("\nStack is : ");
		for(i=0; i<=S->top; i++)
		{
			printf("%d ", S->array[i]);
		}
	}
}
int main()
{
	struct ArrayStack *A = CreateStack();
	
	Push(A, 10);
	Print(A);
    Push(A, 20);
    Print(A);
    Push(A, 30);
    Print(A);
    Push(A, 40);
    Print(A);
    Pop(A);
    Print(A);
    Pop(A);
    Print(A);
    Pop(A);
    Print(A);
    DeleteStack(A);


	return 0;
}

/*
Stack is : 10 
Stack is : 10 20 
Stack is : 10 20 30 
Stack is : 10 20 30 40 
Stack is : 10 20 30 
Stack is : 10 20 
Stack is : 10
*/