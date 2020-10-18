/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q1-4.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-15 21:11
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

void DeleteTail(struct Node** curr)
{
    if((*curr)->next->next == NULL)
    {
        struct Node* temp = (*curr)->next;
        (*curr)->next = NULL;
        free(temp);
        return;
    }

    DeleteTail(&((*curr)->next));
}

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

void DeleteHead(struct Node** head_ref)
{
    // free(*head_ref);
    // node_count--;
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void InsertHead(struct Node** head_ref, int data)
{
    // node_count++;
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node)); // allocate memory for a node
    new_node->data = data;                                              // set the data for this node equal to new data
    new_node->next = *head_ref;                                         // point this node's 'next' to previous head
    *head_ref = new_node;                                               // seat the head as this new node
}

void DeleteMid(struct Node** curr, int t)
{
    static int counter = 0;
    if(counter + 1 <= t && *curr == NULL)
    {
        printf("***NOT ENOUGH NODES***");
        return;
    }

    if(counter + 1 == t)
    {
        struct Node* temp = (*curr)->next;
        (*curr)->next = (*curr)->next->next;
        free(temp);
        return;
    }
    counter++;
    DeleteMid(&((*curr)->next), t);
}

void Insert(struct Node** curr, int t, int data)
{
    static int counter = 0;
    if(counter <= t && *curr == NULL)
    {
        printf("***NOT ENOUGH NODES***\n");
        return;
    }
    if(counter == t)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = (*curr)->next;
        (*curr)->next = new_node;   
        return;
    }
    counter++;
    Insert(&((*curr)->next), t, data);
 
}

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d -> ", curr->data);
    PrintList(curr->next);
}

void PrintListReverse(struct Node* curr)
{
    if(curr == NULL) return;
    PrintListReverse(curr->next);
    printf("%d <- ", curr->data);
}

void Reverse(struct Node** head)
{
    struct Node* first;
    struct Node* rest;

    if(*head == NULL) return;     // empty list

    first = *head;                // eg first = 1->2->3
    rest = first->next;           // rest = 2->3

    if(rest == NULL) return;      //empty rest

    Reverse(&rest);

    first->next->next = first;
    first->next = NULL;

    *head = rest;
}

int main()
{
    int n;
    printf("enter the no. of nodes you would like to be in the list: ");
    scanf("%d", &n);
    int temp;
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("enter data in nodes: ");
    scanf("%d", &temp);
    head->data = temp;
    head->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head, temp);
    }

    PrintList(head);
    printf("\n");
    PrintListReverse(head);
    printf("\n");
    
    
    printf("enter data and t to be inserted after t-th node: ");
    int t;
    scanf("%d%d", &temp, &t);
    Insert(&head, t, temp); 
    PrintList(head);
    printf("\n");

    printf("enter data to be inserted at head: ");
    scanf("%d", &temp);
    InsertHead(&head, temp);
    PrintList(head);
    printf("\n");

    printf("deleting head:\n");
    DeleteHead(&head);
    PrintList(head);
    printf("\n");

    printf("Deleting tail: \n");
    DeleteTail(&head);
    PrintList(head);
    printf("\n");

    printf("enter t for t-th node to be deleted: ");
    scanf("%d", &t);
    DeleteMid(&head, t);
    PrintList(head);
    printf("\n");

    printf("Reversing : \n");
    Reverse(&head);
    PrintList(head);
    printf("\n");


    return 0;
}