/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q1-4.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 19:50
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
struct Node* head;
static int node_count;

void at_tail(struct Node** head_ref, int data) //append a node at the end of the list
{
    node_count++;
    struct Node *curr_node = *head_ref;                                 // make a node pointer and point it to head of list
    while (curr_node->next != NULL)
        curr_node = curr_node->next;                                    // traverse to the end of the list

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    new_node->data = data;                                              // set its data value equal to new value
    curr_node->next = new_node;                                         // point the curr_node(node at the end of our list) to newly created node(new_node)
    new_node->next = NULL;                                              // set new node's next as null
}

void at_head(struct Node** head_ref, int data)
{
    node_count++;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // allocate memory for a node
    new_node->data = data;                                              // set the data for this node equal to new data
    new_node->next = *head_ref;                                         // point this node's 'next' to previous head
    *head_ref = new_node;                                               // seat the head as this new node
}

void print_ll(struct Node** head_ref)
{
    printf("\n");
    struct Node *curr_node = *head_ref;
    for(curr_node = *head_ref; curr_node != NULL; curr_node=curr_node->next)
    {
        printf("%d -> ", curr_node->data);
    }
    printf("\n");
}

void after_node(struct Node** head_ref, int data, int c)
{
    node_count++;
    struct Node* curr_node = *head_ref;
    int count = 0;
    for(curr_node = *head_ref; curr_node != NULL; curr_node = curr_node->next)
    {
        if(count == c)
        {
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->next = curr_node->next;
            new_node->data = data;
            curr_node->next = new_node;
        }
        count++;
    }
    if(count < c)
    {
        printf("not enough nodes, overflow\n");
        return;
    }
}

void del_head(struct Node** head_ref)
{
    // free(*head_ref);
    node_count--;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void del_tail(struct Node** head_ref)
{
    node_count--;
    struct Node* curr_node = *head_ref;
    while(curr_node->next != NULL)
    {
        if((curr_node->next)->next == NULL)
        {
            // curr_node->next = NULL;
            break;
        }
        curr_node = curr_node->next;
    }
    struct Node* temp = curr_node->next;
    curr_node->next = NULL;
    free(temp);
}

void del_at_node(struct Node** head_ref, int c)
{
    node_count--;
    struct Node* curr_node = *head_ref;
    int count = 0;
    
    for(curr_node = *head_ref; curr_node != NULL; curr_node = curr_node->next)
    {
        if(count + 1 == c)
        {
            struct Node* temp = curr_node->next;
            curr_node->next = (curr_node->next)->next;
            free(temp);
            return;
        }
        count++;
    }
}

void reverse_ll(struct Node** head_ref)
{
    struct Node* curr_node = *head_ref;
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node* next = (struct Node*)malloc(sizeof(struct Node));
    prev = NULL;
    next = NULL;
    while(curr_node != NULL)
    {
        next = curr_node ->next;
        curr_node->next = prev;
        prev = curr_node;
        curr_node = next;
    }
    *head_ref = prev;
}

void fun(struct Node* list)
{
    struct Node *p, *q;
    int temp;
    p = list;
    q = list->next;
    while(p)
    {
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        q = p ? p->next : 0;
        p = q->next;
    }
    return;
}


int main()
{
    int n;
    printf("enter the no. of nodes you want initially: ");
    scanf("%d", &n);
    printf("enter the data for the first node: ");
    int temp;
    scanf("%d", &temp);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = temp;
    head->next = NULL;
    node_count++;

    printf("enter next n - 1 nodes: ");
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        at_tail(&head, temp);
    }
    print_ll(&head);

    // printf("enter a node a at the head: ");
    // scanf("%d", &temp);
    // at_head(&head, temp);
    // print_ll(&head);

    // printf("enter a node at the the tail: ");
    // scanf("%d", &temp);
    // at_tail(&head, temp);
    // print_ll(&head);

    // printf("enter data to be inserted after node count c and enter value of c (zero based indexing): ");
    // scanf("%d", &temp);
    // int c;
    // scanf("%d", &c);
    // if(c == node_count - 1)
    //     at_tail(&head, temp);
    // else if(c == 0)
    //     at_head(&head, temp);
    // else
    //     after_node(&head, temp, c);
    // print_ll(&head);

    // printf("deleting the head: ");
    // del_head(&head);
    // print_ll(&head);

    // printf("deleting tail: ");
    // del_tail(&head);
    // print_ll(&head);

    // printf("delete at node count of c, enter the value of c: ");
    // scanf("%d", &c);
    // if(c==0)
    //     del_head(&head);
    // else if(c==node_count - 1)
    //     del_tail(&head);
    // else if(c >= node_count)
    //     printf("not enough nodes");
    // else
    //     del_at_node(&head, c);
    
    // print_ll(&head);

    // printf("reversing: ");
    // reverse_ll(&head);
    // print_ll(&head);


    // getchar();

    fun(head);
    return 0;
}