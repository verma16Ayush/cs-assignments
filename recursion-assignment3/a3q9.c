/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q9.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-19 01:22
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

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d -> ", curr->data);
    PrintList(curr->next);
}

void Delete(struct Node** curr, struct Node* arg)
{
    if(*curr == NULL)
    {
        printf("arg node not found");
        return;
    }
    if((*curr)->next == arg)
    {
        struct Node* temp = (*curr)->next;
        (*curr)->next = (*curr)->next->next;
        free(temp);
        return;
    }
    Delete(&((*curr)->next), arg);
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
    PrintList(head);
    printf("\n");
    printf("deleteing a node after the head: \n");
    Delete(&head, head->next);
    PrintList(head);

    return 0;

}