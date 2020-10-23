/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q21.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-20 01:40
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

void Append(struct Node* curr, struct Node** head, int data)
{
    if(curr->next == *head)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
        newNode->prev = curr;
        curr->next = newNode;
        (*head)->prev = newNode;
        return;
    }
    Append(curr->next, head, data);
}

void InsertAtHead(struct Node** head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = (*head)->prev;
    (*head)->prev->next = new_node;
    *head = new_node;
}

void DeleteEnd(struct Node** head_ref)
{
    struct Node* temp = (*head_ref)->prev;
    (*head_ref)->prev = (*head_ref)->prev->prev;
    (*head_ref)->prev->next = *head_ref;
    free(temp);
}

void DeleteHead(struct Node** head_ref)
{
    struct Node* temp = *head_ref;
    (*head_ref)->prev->next = (*head_ref)->next;
    (*head_ref)->next->prev = (*head_ref)->prev;
    *head_ref = (*head_ref)->next;
    free(temp);
}

void PrintList(struct Node* curr, struct Node** head)
{
    if(curr->next == *head) {printf("%d -> HEAD", curr->data); return;}
    printf("%d -> ", curr->data);
    PrintList(curr->next, head);
}

void Reverse(struct Node* head, struct Node* tail, struct Node *p, struct Node *q)
{

    struct node *r=q->next;
    if(head==NULL)
    {
        printf("List is empty!");
        return;
    }
    if(q==head)
    {
        q->next = tail;
        head=p;
        return;
    }
    r=q->next;
    q->next=p;
    return Reverse(head, tail, q, r);
}

int main()
{
    int n;
    printf("enter no of nodes: ");
    scanf("%d", &n);
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    int temp;
    printf("enter data in nodes: ");
    scanf("%d", &temp);
    head->data = temp;
    head->next = head;
    head->next = head;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(head, &head, temp);
    }
    PrintList(head, &head);
    printf("\n");

    printf("\n");
    printf("enter data for a node at the head: ");
    scanf("%d", &temp);
    InsertAtHead(&head, temp);
    PrintList(head, &head);
    printf("\n");

    printf("deleting head: \n");
    DeleteHead(&head);
    PrintList(head, &head);
    printf("\n");

    printf("deleting end: \n");
    DeleteEnd(&head);
    PrintList(head, &head);
    printf("\n");
    return 0;
    
}