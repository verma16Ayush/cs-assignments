/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q5.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 23:20
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

void find_node(struct Node** head_ref, int c)
{
    struct Node* curr_node = *head_ref;
    int count = 0;
    for(curr_node = *head_ref; curr_node != NULL; curr_node = curr_node->next)
    {
        if(count == c)
        {
            printf("data in this node is: %d\n", curr_node->data);
            return;
        }
        count++;
    }
}

int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    node_count++;
    int n;
    printf("enter number of nodes you would like in the list: ");
    scanf("%d", &n);
    printf("enter data in nodes: ");
    int temp;
    scanf("%d", &temp);
    head->data = temp;
    head->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        at_tail(&head, temp);
    }
    print_ll(&head);
    printf("enter the value of for n-th node from the end: ");
    scanf("%d", &n);
    int c = node_count - n;
    if(c < 0)
        printf("invalid place queried\n");
    else
    {
        find_node(&head, c);
    }

    getchar();
    return 0;
}