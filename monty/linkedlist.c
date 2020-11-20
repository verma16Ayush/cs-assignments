// pointers
// malloc
// recursion

/**
 * 10 -> 20 -> 30 -> NULL

/** 
 *
 * @author - Ayush Verma 194051
 * @title - linkedlist.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-11-12 13:00
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


void Append(struct Node** head_ref, int data)
{
    struct Node* currentNode = *head_ref;
    for(currentNode; currentNode->next != NULL; currentNode = currentNode->next){}

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    currentNode->next = newNode;
}

void InsertAtHead(struct Node** head_ref, int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = *head_ref;
    *head_ref = newnode;
}

void printlist(struct Node* head)
{
    struct Node* currNode = head;
    for(currNode; currNode != NULL; currNode = currNode->next)
    {
        printf("%d, ", currNode->data);
    }
}

void deleteafterHead(struct Node** head_ref)
{
    struct Node* temp = (*head_ref)->next;
    (*head_ref)->next = (*head_ref)->next->next;
    free(temp);
}




int main()
{
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = NULL;

    for (int i = 0; i < 5; i++)
    {
        int temp;
        scanf("%d", &temp);

        Append(&head, temp);
    }
    printlist(head);
    printf("\n");

    deleteafterHead(&head);
    printlist(head);
    return 0;


}

