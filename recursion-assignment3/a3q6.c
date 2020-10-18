/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q6.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-16 15:07
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

void FindCommon(struct Node** h1, struct Node** h2)
{
    if(h1 == NULL) return;

    struct Node* curr = *h2;
    for(curr; curr!=NULL; curr=curr->next)
    {
        if(curr->data == (*h1)->data)
        {
            printf("%d ", curr->data);
            // return;
            break;
        }
    }

    FindCommon(&((*h1)->next), h2);
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

    printf("common elements are: \n");
    FindCommon(&head1, &head2);
    return 0;
    
}