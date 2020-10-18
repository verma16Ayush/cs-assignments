/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q7.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-18 23:29
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

void Append(struct Node** curr, int data)
{
    if((*curr)->next == NULL)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = NULL;
        (*curr)->next = new_node;
        return;
    }

    Append(&((*curr)->next), data);
}

struct Node* Merge(struct Node* h1, struct Node* h2)
{
    struct Node* h = NULL;
    if(h1 == NULL) return h2;
    else if(h2 == NULL) return h1;

    if(h1->data <= h2->data)
    {
        h = h1;
        h->next = Merge(h1->next, h2);
    }
    else
    {
        h = h2;
        h->next = Merge(h1, h2->next);
    }
    return h;
}

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d -> ", curr->data);
    PrintList(curr->next);
}

int main()
{
    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* head2 = (struct Node*)malloc(sizeof(struct Node));

    printf("enter no. of nodes: ");
    int n;
    scanf("%d", &n);
    printf("enter data in nodes for list1: ");
    int temp;
    scanf("%d", &temp);
    head1->data = temp;
    head1->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head1, temp);
    }

    printf("enter data in nodes for list2: ");
    scanf("%d", &temp);
    head2->data = temp;
    head2->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head2, temp);
    }
    struct Node* head = Merge(head1, head2);
    PrintList(head);

    return 0;
}