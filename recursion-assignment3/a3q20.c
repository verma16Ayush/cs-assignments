/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q20.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-20 01:18
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
struct Node* head1;
struct Node* head2;

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

void Split(struct Node* currSlow, struct Node* currFast, struct Node** head)
{
    // static int nodeCount = CountNodes(*head, head);
    if(currFast->next == *head)
    {
        head1 = *head;
        head2 = currSlow->next;
        currSlow->next = *head;
        currFast->next = head2;
        return;
    }
    Split(currSlow->next, currFast->next->next, head);
}

int main()
{
    int n;
    printf("enter the no. of nodes you would like to be in the list: ");
    scanf("%d", &n);
    int temp;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
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

    if(CountNodes(head, &head) % 2) Split(head, head, &head);
    else Split(head, head->next, &head);
    
    PrintList(head1, &head1);
    printf("\n");
    PrintList(head2, &head2);
    printf("\n");

    return 0;    
}