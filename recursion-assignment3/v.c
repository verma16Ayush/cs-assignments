#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;

void create(struct node *temp, int data)
{
    if (temp == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        newNode->next = newNode;

        head = newNode;
        return;
    }
    if (temp->next == head)
    {

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;

        newNode->next = head;
        temp->next = newNode;
        tail = newNode;
        return;
    }

    create(temp->next, data);
}

void print()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty!");
        return;
    }
    printf("Elements of Circular Linked List are:\n");
    while (temp->next != head)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    return;
}
int c = 1;
void countNodes(struct node *temp)
{

    if (temp->next == head)
    {
        return;
    }
    c++;
    return countNodes(temp->next);
    // printf("Number of nodes in the circular linked list is: %d \n",c );
}

void reverse(struct node *p, struct node *q)
{

    struct node *r = q->next;
    if (head == NULL)
    {
        printf("List is empty!");
        return;
    }
    if (q == head)
    {
        q->next = tail;
        head = p;
        return;
    }
    r = q->next;
    q->next = p;
    return reverse(q, r);
}

void Reverse(struct node **head)
{
    struct node *first;
    struct node *rest;

    if (*head == NULL)
        return; // empty list

    first = *head;      // eg first = 1->2->3
    rest = first->next; // rest = 2->3

    if (rest == *head)
    {
        return; //empty rest
    }
    Reverse(&rest);

    first->next->next = first;
    first->next = NULL;

    *head = rest;
}

int main()
{
    int n;
    printf("Enter number of nodes ");
    scanf("%d", &n);

    printf("Enter n elements in circular linked list\n");
    while (n-- > 0)
    {
        int a;
        scanf("%d", &a);
        create(head, a);
    }
    countNodes(head);
    printf("Number of nodes in the circular linked list is: %d \n", c);

    struct node *p = head;
    struct node *q = p->next;

    // p->next=NULL;
    reverse(p, q);
    print();
    return 0;
}