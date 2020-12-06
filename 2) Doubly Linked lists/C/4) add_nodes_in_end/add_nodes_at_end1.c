#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};


struct node *get_new_node(struct node *head, int data)  // Insertion in an empty list
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *add_at_beg(struct node *head, int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct node *add_at_end(struct node *head, int data)
{
    struct node *temp1, *temp2;
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->prev = NULL;
    temp1->data = data;
    temp1->next = NULL;
    temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    temp1->prev = temp2;
    return head;
}

struct node *create_list(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n == 0)
    {
        return head;
    }
    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = get_new_node(head, data);

    for(i=1; i<n; i++)
    {
        printf("Enter the element for the node %d: ", i+1);
        scanf("%d", &data);
        head = add_at_end(head, data);
    }
    return head;
}

void Print(struct node *head)
{
	struct node* temp = head;
	printf("List is : ");
	while(temp != NULL)
    {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}



int main()
{
    struct node *head;
    int n, i, data;
    head = NULL;

    head = create_list(head);
    Print(head);

    printf("Enter the number of elements to add at the begining of the list: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the node %d to add at begining: ", i+1);
        scanf("%d", &data);
        head = add_at_beg(head, data);
        Print(head);
        printf("\n");
    }

    printf("Enter the number of elements to add at the end of the list: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the node %d to add at end: ", i+1);
        scanf("%d", &data);
        head = add_at_end(head, data);
        Print(head);
        printf("\n");
    }

}

/*
Enter the number of nodes: 5
Enter the element for the node 1: 6
Enter the element for the node 2: 7
Enter the element for the node 3: 8
Enter the element for the node 4: 9
Enter the element for the node 5: 10
List is : 6 7 8 9 10
Enter the number of elements to add at the begining of the list: 5
Enter the node 1 to add at begining: 5
List is : 5 6 7 8 9 10

Enter the node 2 to add at begining: 4
List is : 4 5 6 7 8 9 10

Enter the node 3 to add at begining: 3
List is : 3 4 5 6 7 8 9 10

Enter the node 4 to add at begining: 2
List is : 2 3 4 5 6 7 8 9 10

Enter the node 5 to add at begining: 1
List is : 1 2 3 4 5 6 7 8 9 10

Enter the number of elements to add at the end of the list: 5
Enter the node 1 to add at end: 11
List is : 1 2 3 4 5 6 7 8 9 10 11

Enter the node 2 to add at end: 12
List is : 1 2 3 4 5 6 7 8 9 10 11 12

Enter the node 3 to add at end: 13
List is : 1 2 3 4 5 6 7 8 9 10 11 12 13

Enter the node 4 to add at end: 14
List is : 1 2 3 4 5 6 7 8 9 10 11 12 13 14

Enter the node 5 to add at end: 15
List is : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

*/
