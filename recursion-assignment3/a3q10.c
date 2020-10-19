/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q10.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-19 01:34
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

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d -> ", curr->data);
    PrintList(curr->next);
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

void SwapNodes(struct Node** a, struct Node** b)
{
    int temp = (*a)->data;
    (*a)->data = (*b)->data;
    (*b)->data = temp;
}

void ReverseInPairs(struct Node** curr)
{
    if(*curr == NULL || (*curr)->next == NULL) return;

    SwapNodes(curr, &((*curr)->next));
    ReverseInPairs(&((*curr)->next->next));
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
    head->next = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &temp);
        Append(&head, temp);
    }
    printf("original list: \n");
    PrintList(head);
    printf("\n");
    printf("Reversing in pairs: \n");
    ReverseInPairs(&head);
    PrintList(head);
    return 0;
}