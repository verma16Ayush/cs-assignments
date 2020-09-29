/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q8.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-29 11:54
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
struct Node* even_head;
struct Node* odd_head;

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

void del_head(struct Node** head_ref)
{
    // free(*head_ref);
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void join(struct Node** even_head_ref, struct Node** odd_head_ref)
{
    struct Node* curr_node = *even_head_ref;
    for(curr_node; curr_node->next!=NULL; curr_node=curr_node->next){}
    curr_node->next = *odd_head_ref;
}


struct Node** rearrange(struct Node** head_ref)
{
    struct Node* curr_node = *head_ref;
    even_head = (struct Node*)malloc(sizeof(struct Node));
    odd_head = (struct Node*)malloc(sizeof(struct Node));
    // struct Node* curr_even = even_head;
    // struct Node* curr_odd = odd_head;
    even_head->data = 0;
    even_head->next = NULL;

    odd_head->data = 0;
    odd_head->next = NULL;

    for(curr_node; curr_node!=NULL; curr_node = curr_node->next)
    {
        if(curr_node->data % 2 == 0)
            at_tail(&even_head, curr_node->data);
        
        else
            at_tail(&odd_head, curr_node->data);
    }
    del_head(&even_head);
    del_head(&odd_head);
    join(&even_head, &odd_head);

    return &even_head;
}



int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("enter the no. of nodes: ");
    int n;
    scanf("%d", &n);
    printf("enter data for nodes: ");
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

    // struct Node* rearranged_list = *(rearrange(&head));
    printf("rearranged list: ");
    print_ll(rearrange(&head));
    return 0;
    
}