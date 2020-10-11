/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q21.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-11 23:12
 * 
 **/

/**
 * 
 * TODO: 
 * insert - head, end, mid
 * delete - head, end, mid
 * reverse
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
    struct Node* prev;
};
struct Node* head;

void Append(struct Node** head_ref, int data)
{
    struct Node* curr_node = *head_ref;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    for(curr_node; curr_node != NULL && curr_node->next!=*head_ref; curr_node=curr_node->next);
    new_node->data = data;
    curr_node->next = new_node;
    new_node->prev = curr_node;
    (*head_ref)->prev = new_node;
    new_node->next = *head_ref;
}

void InsertAtHead(struct Node** head_ref, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    new_node->prev = (*head_ref)->prev;
    *head_ref = new_node;
}

void PrintDcl(struct Node** head_ref)
{
    struct Node* curr_node = *head_ref;
    do
    {
        printf("%d <-> ", curr_node->data);
        curr_node = curr_node->next;
    } 
    while (curr_node!=*head_ref);
}

int main()
{
    head = (struct Node*)malloc(sizeof(struct Node));
    // head = NULL;
    int n;
    printf("how many nodes would you like: ");
    scanf("%d", &n);
    printf("enter data in nodes: ");
    int temp;
    scanf("%d", &temp);
    head->data = temp;
    head->next = head;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head, temp);
    }
    PrintDcl(&head);
    printf("\n");
    printf("enter data for a node at the head: ");
    scanf("%d", &temp);
    InsertAtHead(&head, temp);
    PrintDcl(&head);
    return 0;
}