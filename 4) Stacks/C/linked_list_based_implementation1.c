// Stack - Linked List based implementation
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void Push(struct node **top, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));
    if(!temp)
    {
        return;
    }
    temp->data = data;
    temp->next = *top;
    *top = temp;
}
int IsEmptyStack(struct node *top)
{
    return top == NULL;
}
int Pop(struct node **top)
{
    int data;
    struct node *temp;
    if(IsEmptyStack(*top))
        return 0;
    temp = *top;
    *top = (*top)->next;
    data = temp->data;
    free(temp);
    return data;
}
int Top(struct node *top)
{
    if(IsEmptyStack(top))
        return 0;
    return top->next->data;
}
void DeleteStack(struct node **top)
{
    struct node *temp, *p;
    p = *top;
    while(p->next)
    {
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
    free(p);
}
void Print(struct node *top)
{
    if(!top)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("\nStack is : ");
        while(top != NULL)
        {
            printf("%d ", top->data);
            top = top->next;
        }
    }
}

int main()
{
    struct node *top = NULL;

    Push(&top, 10);
    Print(top);
    Push(&top, 20);
    Print(top);
    Push(&top, 30);
    Print(top);
    Push(&top, 40);
    Print(top);
    Pop(&top);
    Print(top);
    Pop(&top);
    Print(top);
    Pop(&top);
    Print(top);
    DeleteStack(&top);

    return 0;
}

/*
Stack is : 10
Stack is : 20 10
Stack is : 30 20 10
Stack is : 40 30 20 10
Stack is : 30 20 10
Stack is : 20 10
Stack is : 10
*/
