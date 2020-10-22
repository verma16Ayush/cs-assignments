/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q11-13.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-19 14:13
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
    struct Node* prev;
    struct Node* next;
};

void Append(struct Node** curr, int data)
{
    if((*curr)->next == NULL)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = *curr;
        newNode->next = NULL;
        (*curr)->next = newNode;
        return;
    }

    Append(&((*curr)->next), data);
}

void InsertAtHead(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

void Insert(struct Node** curr, int t, int data)
{
    static int counter = 0;
    if(counter <= t && *curr == NULL)
    {
        printf("***NOT ENOUGH NODES***");
        return;
    }
    if(counter == t)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = *curr;
        newNode->next = (*curr)->next;
        (*curr)->next = newNode;
        return;
    }
    counter++;
    Insert(&((*curr)->next), t, data);
}

void DeleteHead(struct Node** head)
{
    struct Node* temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(temp);
}

void DeleteTail(struct Node** curr)
{
    if((*curr)->next == NULL)
    {
        struct Node* temp = *curr;
        (*curr)->prev->next = NULL;
        free(temp);
        return;
    }
    DeleteTail(&((*curr)->next));
}

void DeleteMid(struct Node** head, int t)
{
    static int counter = 0;
    if(t == 0) {DeleteHead(head); return;}

    if(counter <= t && *head == NULL)
    {
        printf("**NOT_ENOUGH_NODES**");
        return;
    }
    if(counter==t)
    {
        if((*head)->next == NULL) {DeleteTail(head); return;}
        struct Node* temp = *head;
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        free(temp);
        return;
    }
    counter++;
    DeleteMid(&((*head)->next), t);
}

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d <-> ", curr->data);
    PrintList(curr->next);
}

void PrintListReverse(struct Node* curr)
{
    if(curr == NULL) return;
    PrintListReverse(curr->next);
    printf("%d <-> ", curr->data);
}

int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    printf("enter number of nodes: ");
    int n;
    scanf("%d", &n);
    printf("enter data in nodes: ");
    int temp;
    scanf("%d", &temp);
    head->data = temp;
    head->next = NULL;
    head->prev = NULL;
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
    InsertAtHead(&head, temp);
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

    return 0;
}