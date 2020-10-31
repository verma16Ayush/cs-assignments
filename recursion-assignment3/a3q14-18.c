/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q14-18.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-19 14:59
 * 
 **/

//TODO: 16. REVERSE THE LINKED LIST

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

void Append(struct Node** curr, struct Node** head, int data)
{
    if((*curr)->next == *head)
    {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = *head;
        (*curr)->next = new_node;
        return;
    }
    Append(&((*curr)->next), head, data);
}

void PrintList(struct Node* curr, struct Node** head)
{
    if(curr->next == *head) {printf("%d -> HEAD", curr->data); return;}
    printf("%d -> ", curr->data);
    PrintList(curr->next, head);
}

int CountNodes(struct Node* curr, struct Node** head)
{
    static int counter = 0;
    if(curr->next == *head)  return counter + 1;
    counter++;
    return CountNodes(curr->next, head);
}

void InsertAtHead(struct Node** curr, struct Node** head, int data)
{
    if((*curr)->next == *head)
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head; 
        (*curr)->next = newNode;
        *head = newNode;
        return;
    }
    InsertAtHead(&((*curr)->next), head, data);
}

void Insert(struct Node** curr, struct Node** head, int t, int data)
{
    static int counter = 0;
    if(counter <= t && (*curr)->next == *head)
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
    Insert(&((*curr)->next), head, t, data);
}

void DeleteHead(struct Node** curr, struct Node** head)
{
    if((*curr)->next == *head)
    {
        struct Node* temp = *head;
        (*curr)->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
        return;
    }
    DeleteHead(&((*curr)->next), head);
}

void DeleteTail(struct Node** curr, struct Node** head, struct Node** tail)
{
    if((*curr)->next->next == *head)
    {
        struct Node* temp = (*curr)->next;
        (*curr)->next = *head;
        *tail = *curr;
        free(temp);
        return;
    }
    DeleteTail(&((*curr)->next), head, tail);
}

void Reverse(struct Node* head, struct Node* tail, struct Node *p, struct Node *q)
{

    struct Node *r=q->next;
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

// void DeleteMid(struct Node** curr, struct Node** head, int t)
// {
//     static int counter = 0;
//     if(counter + 1 <= t && (*curr)->next == *head)
//     {
//         printf("***NOT ENOUGH NODES***");
//         return;
//     }

//     if(counter + 1 == t)
//     {
//         struct Node* temp = (*curr)->next;
//         (*curr)->next = (*curr)->next->next;
//         free(temp);
//         return;
//     }
//     counter++;
//     DeleteMid(&((*curr)->next), head, t);
// }

int main()
{
    int n;
    printf("enter the no. of nodes you would like to be in the list: ");
    scanf("%d", &n);
    int temp;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
    printf("enter data in nodes: ");
    scanf("%d", &temp);
    head->data = temp;
    head->next = head;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head, &head, temp);
    }
    PrintList(head, &head);
    printf("\n");
    printf("Total Nodes: %d\n", CountNodes(head, &head));

    printf("enter data to be inserted at head: ");
    scanf("%d", &temp);
    InsertAtHead(&head, &head, temp);
    PrintList(head, &head);
    printf("\n");

    printf("enter data and t to be inserted after t-th node: ");
    int t;
    scanf("%d%d", &temp, &t);
    Insert(&head, &head, t, temp); 
    PrintList(head,&head);
    printf("\n");

    printf("deleting head:\n");
    DeleteHead(&head, &head);
    PrintList(head, &head);
    printf("\n");

    printf("Deleting tail: \n");
    DeleteTail(&head, &head, &tail);
    PrintList(head, &head);
    printf("\n");

    Reverse(head, tail, head, head->next);
    PrintList(head, &head);
    

    return 0;
}