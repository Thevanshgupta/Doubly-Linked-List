#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head;

void insertion_beginning();
void deletion_beginning();
void display();

void main ()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\n********Main Menu********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Delete from beginning\n3.Display\n4.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertion_beginning();
                break;
            case 2:
                deletion_beginning();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice..\n");
        }
    }
}

void insertion_beginning()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter item value: ");
        scanf("%d", &item);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }

        printf("\nNode inserted\n");
    }
}

void deletion_beginning()
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void display()
{
    struct node *ptr;
    printf("\nPrinting values...\n");
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
        }
}