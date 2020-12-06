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

struct node *add_after_given_pos(struct node *head, int data, int position)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = get_new_node(newp, data);

    while(position != 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL)
    {
        temp->next = newp;
        newp->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }
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


struct node *add_before_given_pos(struct node *head, int data, int position)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = get_new_node(newp, data);
    int pos = position;
    while(pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    if(position == 1)
    {
        head = add_at_beg(head, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
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
    int n, i, data, pos;
    head = NULL;

    head = create_list(head);
    Print(head);

    printf("To add the data at before given position: ");
    printf("Enter the data: ");
    scanf("%d", &data);
    printf("Enter the position: ");
    scanf("%d", &pos);
    head = add_before_given_pos(head, data, pos);
    Print(head);


    printf("To add the data at after given position: ");
    printf("Enter the data: ");
    scanf("%d", &data);
    printf("Enter the position: ");
    scanf("%d", &pos);
    head = add_after_given_pos(head, data, pos);
    Print(head);


}

/*
Enter the number of nodes: 5
Enter the element for the node 1: 1
Enter the element for the node 2: 2
Enter the element for the node 3: 3
Enter the element for the node 4: 4
Enter the element for the node 5: 5
List is : 1 2 3 4 5
To add the data at before given position: Enter the data: 10
Enter the position: 3
List is : 1 2 10 3 4 5
To add the data at after given position: Enter the data: 20
Enter the position: 3
List is : 1 2 10 20 3 4 5
*/
