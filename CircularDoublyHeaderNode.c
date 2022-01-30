#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *rlink;
    struct Node *llink;
}*NODE;


void display(NODE head)
{
    NODE temp =(NODE)malloc(sizeof(struct Node));
    temp=head->rlink;
    while (temp->rlink != head)
    {
        printf("Element: %d\n", temp->data);
        temp = temp->rlink;
    }
    printf("Element: %d\n", temp->data);
}

NODE insertAtFront(NODE head, int data)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE next = (NODE)malloc(sizeof(struct Node));
    next=head->rlink;
    cur->data=data;
    head->rlink=cur;
    cur->llink=head;
    cur->rlink=next;
    next->llink=cur;

    return head;    
}

NODE insertAtEnd(NODE head, int data)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE temp = (NODE)malloc(sizeof(struct Node));
    cur=head->rlink;
    while (cur->rlink != head)
        cur = cur->rlink;
    temp->data=data;
    temp->llink=cur;
    cur->rlink=temp;
    temp->rlink=head;
    head->llink=temp;

    return head;    
}

NODE deleteFront(NODE head)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE next = (NODE)malloc(sizeof(struct Node));
    cur=head->rlink;
    next=cur->rlink;
    head->rlink=next;
    next->llink=head;
    free(cur);
    return head;    
}

NODE deleteEnd(NODE head)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE prev = (NODE)malloc(sizeof(struct Node));
    cur=head->rlink;
    while (cur->rlink != head)
        cur = cur->rlink;
    prev=cur->llink;
    prev->rlink=head;
    head->llink=prev;
    free(cur);
    return head;    
}

NODE insertKeyRight(NODE head, int keyData)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE next = (NODE)malloc(sizeof(struct Node));
    NODE temp = (NODE)malloc(sizeof(struct Node));

    if(head->rlink==head)
    {
        printf("List is empty");
        return head;
    }

    cur=head->rlink;
    while(cur->rlink!=head)
    {
        if(cur->data==keyData)
            break;
        cur=cur->rlink;
    }
    
    printf("Enter data: ");
    int num;
    scanf("%d",&num);
    temp->data=num;

    next=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;

    temp->rlink=next;
    next->llink=temp;

    return head;    
}

NODE insertKeyLeft(NODE head, int keyData)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE prev = (NODE)malloc(sizeof(struct Node));
    NODE temp = (NODE)malloc(sizeof(struct Node));

    if(head->rlink==head)
    {
        printf("List is empty");
        return head;
    }

    cur=head->rlink;
    while(cur->rlink!=head)
    {
        if(cur->data==keyData)
            break;
        cur=cur->rlink;
    }
    
    printf("Enter data: ");
    int num;
    scanf("%d",&num);
    temp->data=num;

    prev=cur->llink;
    cur->llink=temp;
    temp->rlink=cur;

    temp->llink=prev;
    prev->rlink=temp;

    return head;    
}

NODE deleteKeyLeft(NODE head, int keyData)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE prev = (NODE)malloc(sizeof(struct Node));
    NODE pprev = (NODE)malloc(sizeof(struct Node));

    if(head->rlink==head)
    {
        printf("List is empty");
        return head;
    }

    cur=head->rlink;
    while(cur->rlink!=head)
    {
        if(cur->data==keyData)
            break;
        cur=cur->rlink;
    }

    prev=cur->llink;
    pprev=prev->llink;

    pprev->rlink=cur;
    cur->llink=pprev;

    free(prev);
   
    return head;    
}

NODE deleteIndex(NODE head, int key)
{
    NODE cur = (NODE)malloc(sizeof(struct Node));
    NODE prev = (NODE)malloc(sizeof(struct Node));
    NODE next = (NODE)malloc(sizeof(struct Node));

    if(head->rlink==head)
    {
        printf("List is empty");
        return head;
    }

    cur=head->rlink;
    int c=1;
    while(cur->rlink!=head)
    {
        if(c==key)
            break;
        cur=cur->rlink;
        c++;
    }

    next=cur->rlink;
    prev=cur->llink;
    prev->rlink=next;
    next->llink=prev;

    free(cur);

    return head;    
}

int main()
{

    NODE head;
    NODE first;
    NODE second;
    NODE third;
    NODE fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (NODE)malloc(sizeof(struct Node));
    first = (NODE)malloc(sizeof(struct Node));
    second = (NODE)malloc(sizeof(struct Node));
    third = (NODE)malloc(sizeof(struct Node));
    fourth = (NODE)malloc(sizeof(struct Node));

    head->rlink=first;
    head->llink=fourth;

    // Link first and second nodes
    first->data = 1;
    first->rlink = second;
    first->llink=  head;

    // Link second and third nodes
    second->data = 2;
    second->rlink = third;
    second->llink = first;

    // Link third and fourth nodes
    third->data = 3;
    third->rlink = fourth;
    third->llink = second;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->rlink = head;
    fourth->llink = third;

    printf("Doubly Linked list original\n");
    display(head);

    /*
    
    head = insertAtFront(head, 5);
    printf("Doubly Linked list after front insertion\n");
    display(head);

    head = insertAtEnd(head, 10 );
    printf("Doubly Linked list after end insertion\n");
    display(head);

    printf("Doubly Linked list after front deletion\n");
    deleteFront(head);
    display(head);

    printf("Doubly Linked list after end deletion\n");
    deleteEnd(head);
    display(head);

    printf("Doubly Linked list after key right insertion\n");
    head= insertKeyRight(head,2);
    display(head);

    printf("Doubly Linked list after key left insertion\n");
    head= insertKeyLeft(head,2);
    display(head); 
    
    printf("Doubly Linked list after key left deletion\n");
    head= deleteKeyLeft(head,2);
    display(head);

    head = deleteIndex(head, 2);
    printf("Doubly Linked list after front insertion\n");
    display(head);
    
    */

    return 0;
}