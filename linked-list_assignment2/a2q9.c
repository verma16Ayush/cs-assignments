/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q9.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-29 23:36
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

void at_tail(struct Node** head_ref, int data) //append a node at the end of the list
{
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

void del(struct Node** head_ref, struct Node** arg_node)
{
    struct Node* temp = (*arg_node);
    struct Node* curr_node = *head_ref;
    for(curr_node; curr_node!= NULL; curr_node=curr_node->next)
    {
        if(curr_node->next->data == (*arg_node)->data && curr_node->next == *arg_node)
        {
            curr_node->next = (*arg_node)->next;
            free(temp);
            return;
        }
    }
}

int main()
{
    printf("enter no. of node in the list initially: ");
    int n;
    scanf("%d", &n);
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
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
    printf("deleting a node after head: ");
    del(&head, &(head->next));
    print_ll(&head);

    getchar();
    return 0;
    
}