/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q7.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 23:53
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

struct Node* head1;
struct Node* head2;
struct Node* merge_head;
// static int node_count;

void at_tail(struct Node** head_ref, int data) //append a node at the end of the list
{
    // node_count++;
    struct Node *curr_node = *head_ref;                                 // make a node pointer and point it to head of list
    while (curr_node->next != NULL)
        curr_node = curr_node->next;                                    // traverse to the end of the list

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    new_node->data = data;                                              // set its data value equal to new value
    curr_node->next = new_node;                                         // point the curr_node(node at the end of our list) to newly created node(new_node)
    new_node->next = NULL;                                              // set new node's next as null
}

void print_ll(struct Node** head_ref)
{
    printf("\n");
    struct Node *curr_node = *head_ref;
    for(curr_node = *head_ref; curr_node != NULL; curr_node = curr_node->next)
    {
        printf("%d -> ", curr_node->data);
    }
    printf("\n");
}

struct Node** merge(struct Node** head1, struct Node** head2)
{
    struct Node* i = *head1;
    struct Node* j = *head2;
    merge_head = (struct Node*)malloc(sizeof(struct Node));

    //handle head for new list separately
    if(i->data <= j->data)
    {
        merge_head->data = i->data;
        merge_head->next = NULL;
        i = i->next;
    }
    else
    {
        merge_head->data = j->data;
        merge_head->next = NULL;
        j = j->next;
    }
    
    //rest of the list
    while(i != NULL && j!= NULL)
    {
        if(i->data <= j->data)
        {
            at_tail(&merge_head, i->data);
            i = i->next;
        }
        else
        {
            at_tail(&merge_head, j->data);
            j = j->next;
        }
    }
    while (i != NULL)
    {
        at_tail(&merge_head, i->data);
        i = i->next;
    }

    while (j != NULL)
    {
        at_tail(&merge_head, j->data);
        j = j->next;
    }
    
    return &merge_head;
}

int main()
{
    head1 = (struct Node*)malloc(sizeof(struct Node));
    head2 = (struct Node*)malloc(sizeof(struct Node));
    // node_count++;
    int n;
    printf("enter number of nodes you would like in the list: ");
    scanf("%d", &n);
    printf("enter data in nodes for list 1: ");
    int temp;
    scanf("%d", &temp);
    head1->data = temp;
    head1->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        at_tail(&head1, temp);
    }
    printf("list1:\n");
    print_ll(&head1);

    printf("enter data in nodes for list 2: ");
    scanf("%d", &temp);
    head2->data = temp;
    head2->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        at_tail(&head2, temp);
    }
    printf("list2: \n");
    print_ll(&head2);

    struct Node* merge_head = *(merge(&head1, &head2));
    printf("merged list: \n");
    print_ll(&merge_head);

    return 0;
}