/* in doubly circular, head->prev=last, last->next=head */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*NODE;

//typedef struct Node *NODE;

void display(NODE first)
{
    NODE ptr = (NODE)malloc(sizeof(struct Node));
    ptr=first;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != first);
}

NODE insertAtRear(NODE head, int data)
{
    NODE ptr = (NODE)malloc(sizeof(struct Node));
    ptr->data = data;
    NODE cur= head;
    while(cur->next!=head)
        cur=cur->next;
    
    cur->next=ptr;
    ptr->prev=cur;
    ptr->next=head;
    head->prev=ptr;

    return head;
}

int main()
{

    NODE first;
    NODE second;
    NODE third;
    NODE fourth;

    // Allocate memory for nodes in the linked list in Heap
    first = (NODE)malloc(sizeof(struct Node));
    second = (NODE)malloc(sizeof(struct Node));
    third = (NODE)malloc(sizeof(struct Node));
    fourth = (NODE)malloc(sizeof(struct Node));

    // Link first and second nodes
    first->data = 1;
    first->next = second;
    first->prev=  fourth;

    // Link second and third nodes
    second->data = 2;
    second->next = third;
    second->prev = first;

    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = first;
    fourth->prev = third;

    printf("Doubly Linked list before insertion\n");
    display(first);
    first = insertAtRear(first, 54);
    printf("Doubly Linked list after insertion\n");
    display(first);

    return 0;
}