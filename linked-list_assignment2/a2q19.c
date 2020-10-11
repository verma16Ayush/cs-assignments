/** 
 *
 * @author - Ayush Verma 194051
 * @title - a2q19.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-11 14:31
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

void PrintCl(struct Cnode** head_ref, int count)
{
    struct Cnode* currNode = *head_ref;
    int c = 0;
    do
    {
        printf("%d -> ", currNode->data);
        currNode = currNode->next; 
        c++;
    } 
    while (currNode != *head_ref && c != count);
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

void Link(struct Cnode** head_ref, int t)
{
    struct Cnode* currNode = *head_ref;
    struct Cnode* temp;
    int c = 0;
    do
    {
        if(c==t)
        {
            temp = currNode;
        }

        currNode = currNode->next;
        c++;
    } 
    while (currNode->next != *head_ref);
    currNode->next = temp;
}

struct Cnode* FindLink(struct Cnode** head_ref, int count)
{
    struct Cnode* currNode = *head_ref;
    for (int c = 0; c < count; c++)
    {
        currNode = currNode->next;
    }
    return currNode; 
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
    int nodeCount = CountNodes(&head);
    PrintCl(&head, nodeCount);

    printf("enter t for t-th node to be linked to the last node: ");
    int t;
    scanf("%d", &t);
    
    if(t > nodeCount)
        printf("not enough nodes: ");
    
    else
    {
        Link(&head, t);
    }
    PrintCl(&head, nodeCount);

    printf("node linked to the last node is: %d", (FindLink(&head, nodeCount))->data);
    return 0;
}