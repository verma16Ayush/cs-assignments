/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q20.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-11 15:42
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
struct Cnode* list1;
struct Cnode* list2;


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

void Split(struct Cnode** head_ref)
{
    struct Cnode* fast_iter = *head_ref; 
    struct Cnode* slow_iter = *head_ref; 

    do
    {
        // fast iter moves at double the speed of slow iter, so when
        // fast_iter is at end, slow iter is at the middle of the list
        slow_iter = slow_iter->next;
        fast_iter = fast_iter->next;
        if(fast_iter->next==*head_ref)
            break;
        fast_iter = fast_iter->next;
    } 
    while (fast_iter->next!=*head_ref);
    list1 = *head_ref;
    list2 = slow_iter->next;
    slow_iter->next = list1;
    fast_iter->next = list2;   
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
    Split(&head);
    return 0;
}