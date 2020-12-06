#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

struct node *get_new_node(struct node *head, int data)  // Insertion in an empty list
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

void Print()
{
	struct node* temp = head;
	while(temp != NULL)
    {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
    int n;
    head = NULL;

    printf("Enter the data for node: ");
    scanf("%d", &n);
    head = get_new_node(head, n);
    Print();

}

/*

Enter the data for node: 5
5

*/
