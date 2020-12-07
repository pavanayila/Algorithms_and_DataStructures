#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top;

void Push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    struct node *temp;
    if(top == NULL)
    {
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void Print()
{
    struct node *temp = top;
    printf("Stack: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    top = NULL;
    Push(1);
    Print();
    Push(2);
    Print();
    Push(3);
    Print();
    Push(4);
    Print();
    Push(5);
    Print();

    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();

    return 0;

}

/*
Stack: 1
Stack: 2 1
Stack: 3 2 1
Stack: 4 3 2 1
Stack: 5 4 3 2 1
Stack: 4 3 2 1
Stack: 3 2 1
Stack: 2 1
Stack: 1
Stack:
*/
