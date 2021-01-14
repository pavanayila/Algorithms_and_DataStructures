#include<stdio.h>
#include<stdlib.h>
struct DynArrayStack
{
	int top;
	int capacity;
	int *array;
};
struct DynArrayStack *CreateStack()
{
	struct DynArrayStack *S = malloc(sizeof(struct DynArrayStack));
	if(!S)
		return NULL;
	S->capacity = 1;
	S->top = -1;
	S->array = malloc(S->capacity * sizeof(int));
	if(!S->array)
		return NULL;
	return S;
}
int IsFullStack(struct DynArrayStack *S)
{
	return (S->top == S->capacity-1);
}
void DoubleStack(struct DynArrayStack *S)
{
	S->capacity *= 2;
	S->array = realloc(S->array, S->capacity * sizeof(int));
}
void Push(struct DynArrayStack *S, int data)
{
	// No overflow in this implementation.
	if(IsFullStack(S))
		DoubleStack(S);

	S->array[++S->top] = data;
}
int IsEmptyStack(struct DynArrayStack *S)
{
	return S->top == -1;
}
int Top(struct DynArrayStack *S)
{
	if(IsEmptyStack(S))
		return 0;

	return S->array[S->top];
}
int Pop(struct DynArrayStack *S)
{
	if(IsEmptyStack(S))
		return 0;

	return S->array[S->top--];
}
void DeleteStack(struct DynArrayStack *S)
{
	if(S)
	{
		if(S->array)
			free(S->array);
		free(S);
	}
}
void Print(struct DynArrayStack *S)
{
	if(!S->array)
    {
    	printf("Stack is empty");
    }
    else
    {
    	int i;
    	printf("\nStack is : ");
    	for(i=0; i<=S->top; i++)
    	{
    		printf("%d ", S->array[i]);
    	}
    }
}
int main()
{
	struct DynArrayStack *A = CreateStack();
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
