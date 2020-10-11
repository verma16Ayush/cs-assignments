/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q14-18.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-05 23:07
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Cnode
{
    int data;
    struct Cnode* next;
};
struct Cnode* head;

void Append(struct Cnode** head_ref, int data)
{
    struct Cnode* currNode = *head_ref;
    struct Cnode* newNode = (struct Cnode*)malloc(sizeof(struct Cnode));
    newNode->data = data;
    newNode->next = *head_ref;
    for(currNode; currNode->next!=NULL && currNode->next!=*head_ref; currNode=currNode->next){}
    currNode->next = newNode;
}

void PrintCl(struct Cnode** head_ref)
{
    struct Cnode* currNode = *head_ref;
    do
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;    
    } 
    while (currNode != *head_ref);
    printf("\n");
}

int CountNodes(struct Cnode** head_ref)
{
    int count = 0;
    struct Cnode* currNode = *head_ref;
    if((*head_ref) == NULL)
        return count;
    else
    {
        do
        {
            count++;
            currNode = currNode->next;
        }
        while(currNode != *head_ref);
    }
    return count;
}

void Reverse(struct Cnode** head_ref)
{
    if (*head_ref == NULL) 
        return; 
    struct Cnode* prev = NULL; 
    struct Cnode* current = *head_ref; 
    struct Cnode* next; 
    do 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    while (current != (*head_ref)); 
  
    (*head_ref)->next = prev; 
    *head_ref = prev; 
}

void InsertAtHead(struct Cnode** head_ref, int data)
{
    struct Cnode* newNode = (struct Cnode*)malloc(sizeof(struct Cnode));
    struct Cnode* currNode = *head_ref;
    newNode->data = data;
    newNode->next = *head_ref;
    do
    {
        currNode=currNode->next;
    } 
    while (currNode->next!=*head_ref);

    currNode->next = newNode;
    *head_ref = newNode;
}

void DeleteHead(struct Cnode** head_ref)
{
    struct Cnode* temp = *head_ref;
    struct Cnode* currNode = *head_ref;
    do
    {
        currNode=currNode->next;
    } 
    while (currNode->next!=*head_ref);
    currNode->next = (*head_ref)->next;
    free(temp);
}

void DeleteEnd(struct Cnode** head_ref)
{
    struct Cnode* currNode = *head_ref;
    do
    {
        currNode=currNode->next;
    } while (currNode->next->next != NULL);
    struct Cnode* temp = currNode->next;
    currNode->next = *head_ref;
    free(temp);
}

int main()
{
    int n;
    printf("how many nodes would you like: ");
    scanf("%d", &n);
    printf("enter data in nodes: ");
    int temp;
    scanf("%d", &temp);
    head = (struct Cnode*)malloc(sizeof(struct Cnode*));
    head->data = temp;
    head->next = NULL;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head, temp);
    }
    PrintCl(&head);
    printf("\n");
    printf("Total no of nodes: %d\n", CountNodes(&head));

    printf("reversed list: \n");
    Reverse(&head);
    PrintCl(&head);

    printf("insert at head: ");
    int temp;
    scanf("%d", &temp);
    InsertAtHead(&head, temp);
    PrintCl(&head);

    printf("deleting head: \n");
    DeleteHead(&head);
    PrintCl(&head);

    printf("deleting end: \n");
    DeleteEnd(&head);
    printcl(&head);
    

    return 0;
}