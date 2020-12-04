#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Insert(struct node *head, int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

void Print(struct node *head)
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
void count_of_nodes(struct node *head)
{
    int count = 0;
    if(head == NULL)
    {
        printf("Linked List is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nThe Number of nodes is %d", count);
}

void add_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
int main()
{
    struct node *head;
    head = NULL;
    printf("How many numbers?\n");
    int i, n, x;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        head = Insert(head, x);
        Print(head);
    }
    add_at_end(head, 15);
    Print(head);

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
List is : 5 4 3 2 1 15
*/
