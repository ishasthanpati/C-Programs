// Head: prev->NULL
// Last: next->NULL

/* in doubly circular, head->prev=last, last->next=head */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversalForward(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void linkedListTraversalBackward(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    struct Node *last;
    while (ptr != NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }
    struct Node *trav = last;

    while (last != NULL)
    {
        printf("Element: %d\n", last->data);
        last = last->prev;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    ptr->prev = NULL;
    head->prev = ptr;
    head = ptr;
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 1;
    head->next = second;
    head->prev = NULL;

    // Link second and third nodes
    second->data = 2;
    second->next = third;
    second->prev = head;

    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;
    third->prev = second;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Doubly Linked list before insertion\n");
    linkedListTraversalForward(head);
    head = insertAtFirst(head, 54);
    // head = insertAtFirst(head, 58);
    // head = insertAtFirst(head, 59);
    printf("Doubly Linked list after insertion\n");
    linkedListTraversalForward(head);

    linkedListTraversalBackward(head);
    return 0;
}