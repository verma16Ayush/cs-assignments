#include <stdio.h>
#include <math.h>
// #include <lin
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
struct Node* second;
struct Node* third;
int main()
{
    // printf("enter 10 elements in linked list");
    head = (struct Node*)malloc(sizeof(struct Node*));
    second = (struct Node*)malloc(sizeof(struct Node*));
    third = (struct Node*)malloc(sizeof(struct Node*));

    head->data = 0;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    struct Node* curr_node = head;

    for(curr_node = head; curr_node != NULL; curr_node=curr_node->next)
    {
        printf("%d -> ", curr_node->data);
    }

    // while (1)
    // {
    //     printf("%d -> ", curr_node->data);
    //     curr_node = curr_node->next;
    //     if(curr_node->next == NULL)
    //     {
    //         printf("%d", curr_node->data);
    //         break;    
    //     }
    // }

    // struct Node* first = (struct Node*)malloc(sizeof(struct Node*));

    // head->next = first;
    // first->data = 10;
    // first->next = second;

    // printf("\n\nafter adding in middle\n");
    // curr_node = head;
    // while (1)
    // {
    //     printf("%d -> ", curr_node->data);
    //     curr_node = curr_node->next;
    //     if(curr_node->next == NULL)
    //     {
    //         printf("%d", curr_node->data);
    //         break;    
    //     }
    // }
    
    // struct Node* fourth = (struct Node*)malloc(sizeof(struct Node*));
    // third->next = fourth;
    // fourth->data = 40;
    // fourth->next = NULL;

    // printf("\n\nafter adding at the end\n");
    // curr_node = head;
    // while (1)
    // {
    //     printf("%d -> ", curr_node->data);
    //     curr_node = curr_node->next;
    //     if(curr_node->next == NULL)
    //     {
    //         printf("%d", curr_node->data);
    //         break;    
    //     }
    // }
    
    return 0;
}