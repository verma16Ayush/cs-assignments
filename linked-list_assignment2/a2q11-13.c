/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q11-13.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-29 13:41
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct DL_node
{
    int data;
    struct DL_node* next;
    struct DL_node* prev;
};
struct DL_node* head;
struct DL_node* tail;
int node_count;

void append(struct DL_node** head_ref, struct DL_node** tail, int data)
{
    node_count++;
    struct DL_node* curr_node = *head_ref;
    struct DL_node* new_node = (struct DL_node*)malloc(sizeof(struct DL_node));
    for(curr_node; curr_node->next !=NULL; curr_node = curr_node ->next){}
    new_node->data = data;
    new_node->prev = curr_node;
    curr_node->next = new_node;
    new_node->next = NULL;
    *tail = new_node;
}

void at_head(struct DL_node** head_ref, int data)
{
    node_count++;
    struct DL_node* new_node = (struct DL_node*)malloc(sizeof(struct DL_node));
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    *head_ref = new_node;
}

void after_node(struct DL_node** head_ref, int c, int data)
{
    node_count++;
    struct DL_node* curr_node = *head_ref;
    int count = 0;
    for(curr_node; curr_node!=NULL; curr_node = curr_node->next)
    {
        if(count == c)
        {
            struct DL_node* new_node = (struct DL_node*)malloc(sizeof(struct DL_node));
            new_node->prev = curr_node;
            new_node->next = curr_node->next;
            new_node->data = data;
            curr_node->next = new_node;
            return;
        }
        count++;
    }
}

void del_head(struct DL_node** head_ref)
{
    node_count--;
    struct DL_node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    (*head_ref)->prev = NULL;
    free(temp);
}

void del_tail(struct DL_node** tail_ref)
{
    node_count--;
    struct DL_node* temp = *tail_ref;
    *tail_ref = (*tail_ref)->prev;
    (*tail_ref)->next = NULL;
    free(temp);
}

void del_after_node(struct DL_node** head_ref, int c)
{
    node_count--;
    struct DL_node* curr_node = *head_ref;
    int count = 0;
    for(curr_node; curr_node!=NULL; curr_node = curr_node->next)
    {
        if(count == c)
        {
            struct DL_node* temp = curr_node;
            curr_node->next->prev = curr_node->prev;
            curr_node->prev->next = curr_node->next;
            free(temp);
            return;
        }
        count++;
    }
}

void print_ll(struct DL_node** head_ref)
{
    struct DL_node *curr_node = *head_ref;
    for(curr_node = *head_ref; curr_node != NULL; curr_node=curr_node->next)
    {
        printf("%d -> ", curr_node->data);
    }
    printf("\n");
}

int main()
{
    head = (struct DL_node*)malloc(sizeof(struct DL_node));
    tail = (struct DL_node*)malloc(sizeof(struct DL_node));
    node_count = 1;
    printf("enter number of nodes: ");
    int n;
    scanf("%d", &n);
    printf("enter data in nodes");
    int temp;
    scanf("%d", &temp);
    head->data = temp;
    head->next = NULL;
    head->prev = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        append(&head, &tail, temp);
    }

    printf("enter a node at head: ");
    scanf("%d", &temp);
    at_head(&head, temp);
    print_ll(&head);

    printf("enter a node at tail: ");
    scanf("%d", &temp);
    append(&head, &tail, temp);
    print_ll(&head);

    printf("enter the value node after c-th node: ");
    scanf("%d", &temp);
    int c;
    printf("enter c");
    scanf("%d", &c);
    if(c == 0)
    {
        at_head(&head, temp);
    }
    else if(c == node_count - 1)
    {
        append(&head, &tail, temp);
    }
    else
    {
        after_node(&head, c, temp);
    }
    print_ll(&head);

    printf("deleting head: \n");
    del_head(&head);
    print_ll(&head);

    printf("deleting tail: \n");
    del_tail(&tail);
    print_ll(&head);

    printf("enter c for c-th node to be dleted: ");
    scanf("%d", &c);
    if(c == 0)
    {
        del_head(&head);
    }
    else if(c == node_count - 1)
    {
        del_tail(&tail);
    }
    else if(node_count < c)
    {
        printf("not enough nodes");
    }
    else
    {
        del_after_node(&head, c);
    }
    print_ll(&head);
    
    getchar();
    return 0;
}