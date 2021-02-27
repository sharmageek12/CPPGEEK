#include <stdio.h>
#include <stdlib.h>

//We create an abstract data type
struct node
{
    int data;
    struct node *prev; //to store address of previous node
    struct node *next; //to store address of next node
};

//To traverse our doubly linked list
void traversal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

//To insert a element at the start of linked list
struct node *startinsert(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    return (new);
}

//To insert a element at the end of linked list
struct node *endinsert(struct node *head, int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *h = head;
    while (h->next != NULL)
    {
        h = h->next;
    }
    h->next = new;
    new->next = NULL;
    new->prev = h;

    return (head);
}

//To insert a element at the index given of linked list
struct node *indexinsert(struct node *head, int data, int ind)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    struct node *h = head;
    for (int i = 1; i < ind - 1; i++)
    {
        h = h->next;
    }
    new->next = h->next;
    new->prev = h;
    h->next = new;

    return (head);
}

//To delete a element at the start of linked list
struct node *startdelete(struct node *head)
{
    struct node *h = head;
    head = head->next;
    head->prev = NULL;
    free(h);
    return (head);
}

//To delete a element at the end of linked list
struct node *enddelete(struct node *head)
{
    struct node *h = head->next;
    struct node *x = head;
    while (h->next != NULL)
    {
        h = h->next;
        x = x->next;
    }
    x->next = NULL;
    free(h);
    return (head);
}

//To delete a element at the given index of linked list
struct node *indexdelete(struct node *head, int ind)
{
    struct node *h = head->next;
    struct node *x = head;
    for (int i = 1; i < ind - 1; i++)
    {
        h = h->next;
        x = x->next;
    }
    x->next = h->next;
    free(h);
    return (head);
}

int main()
{
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->prev = NULL;
    head->next = first;
    head->data = 4;

    first->prev = head;
    first->next = second;
    first->data = 5;

    second->prev = first;
    second->next = third;
    second->data = 6;

    third->prev = second;
    third->next = fourth;
    third->data = 7;

    fourth->prev = third;
    fourth->next = NULL;
    fourth->data = 8;

    traversal(head);
    head = startinsert(head, 3);
    printf("\n After Adding element %d in front \n",3);
    traversal(head);
    head = endinsert(head, 9);
    printf("\n After Adding element %d in End \n",9);
    traversal(head);
    head = indexinsert(head, 0, 3);
    printf("\n After Adding element %d at %d position \n",0,3);
    traversal(head);
    head = startdelete(head);
    printf("\n After deleting element at the front\n");
    traversal(head);
    head = enddelete(head);
    printf("\n After deleting element at the end\n");
    traversal(head);
    head = indexdelete(head, 5);
    printf("\n After deleting element at %d position\n",5);
    traversal(head);
}
