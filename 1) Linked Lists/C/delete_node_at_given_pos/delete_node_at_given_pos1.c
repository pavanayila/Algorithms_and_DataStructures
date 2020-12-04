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

void delete_at_given_pos(int pos)
{
    struct node *temp1 = head;

    if(pos == 1)
    {
        head = temp1->next; //head now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=0; i<pos-2; i++)
    {
        temp1 = temp1->next;
    }
    //temp1 points to (n-1)th node
    struct node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next; // (n+1)th node
    free(temp2); //delete temp2;
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
    delete_at_given_pos(a);
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
