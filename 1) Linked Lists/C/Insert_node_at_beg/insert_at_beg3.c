#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void Insert(struct node **head, int x) // **head is pointer to head
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = *head;
    *head = temp;

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
        Insert(&head, x);
        Print(head);
    }

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

Process returned 5 (0x5)   execution time : 9.119 s
Press any key to continue.
*/
