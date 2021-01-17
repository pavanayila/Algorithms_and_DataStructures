#include<stdio.h>
#include<stdlib.h>

// Skeleton for every node or element of linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to print all the elements of linked list
void display(struct Node *n)
{
    while(n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // memory allocation
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // assigning values to nodes
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // linking nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // calling display
    display(head);

    return 0;
}

// 10 20 30
