/* Write a function struct node * insert_order (struct node *first, int reg_no ) which inserts a new node into a circular singly linked list without header node(list may be initially empty) in the ascending order of the registration number and returns the new list. */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int reg;
    struct Node *next;
};

void display(struct Node *first)
{
    struct Node *ptr = first;
    do
    {
        printf("%d\t", ptr->reg);
        ptr = ptr->next;
    } while (ptr != first);
    printf("\n");
}

struct Node * insert_order (struct Node *first, int reg_no )
{

    if(first->next==NULL)
    {
        printf("List is empty");
        return first;
    }

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->reg = reg_no;

    struct Node *low = (struct Node *)malloc(sizeof(struct Node));
    low=first;

    struct Node *high = (struct Node *)malloc(sizeof(struct Node));
    high=first->next;

    //insert at front
    if(reg_no<first->reg)
    {
        while(low->next!=first)
            low=low->next;
        low->next = temp;
        temp->next = first;
        first = temp;
    }

    else
    {
        while (high->next != first  && reg_no>high->reg)
        {
            low = low->next;
            high = high->next;
        }

        //insert somewhere in the middle
        if(high->reg > reg_no)
        {
            temp->next=high;
            low->next=temp;
        }

        //insert at end
        else if(high->reg < reg_no && high->next==first)
        {
            temp->next=first;
            high->next=temp;
        }
    }
    
    return first;
}

int main()
{

    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    first->reg = 4;
    first->next = second;

    // Link second and third nodes
    second->reg = 5;
    second->next = third;

    // Link third and fourth nodes
    third->reg = 7;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->reg = 8;
    fourth->next = first;

    printf("Original List: \n");
    display(first);

    printf("List after insertion: \n");
    first=insert_order(first,2);
    display(first);
    first=insert_order(first,6);
    display(first);
    first=insert_order(first,12);
    display(first);

    return 0;
}
