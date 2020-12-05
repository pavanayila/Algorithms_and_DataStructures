#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void Insert(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print()
{
    struct node *temp = head;
    printf("List is : ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_at_given_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *previous = *head;

    if(*head == NULL)
    {
        printf("List is already empty!");
    }
    else if(pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        while(pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

int main()
{
    int a;
    head = NULL;
    printf("How many numbers?\n");
    int i, n, x;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    printf("Enter the position of the node to delete ");
    scanf("%d", &a);
    delete_at_given_pos(&head, a);
    Print();
}

/*
How many numbers?
5
Enter the number
1
List is : 1
Enter the number
2
List is : 2 1
Enter the number
3
List is : 3 2 1
Enter the number
4
List is : 4 3 2 1
Enter the number
5
List is : 5 4 3 2 1
Enter the position of the node to delete 3
List is : 5 4 2 1
*/
