
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *at_tail(struct node **head_ref, int data)
{
    struct node *curr_node = *head_ref;
    if (curr_node == NULL)
    {
        curr_node = (struct node *)malloc(sizeof(struct node));
        curr_node->data = data;
        curr_node->next = NULL;
        return curr_node;
    }
    else
    {
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }

        curr_node->next = (struct node *)malloc(sizeof(struct node));
        curr_node = curr_node->next;
        curr_node->next = NULL;
        curr_node->data = data;
        return curr_node;
    }
}

void print_ll(struct node *first)
{
    printf("****Linked List**\n");
    struct node *ptr = first;
    int i = 0;
    while (ptr != NULL)
    {
        printf("%d:%d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}

void find_common(struct node *one, struct node *two)
{
    printf("Common Elements are\n");
    struct node *tmp = two;
    while (one)
    {
        two = tmp;
        while (two)
        {
            if (one->data == two->data)
            {
                printf("%d\n", one->data);
            }
            two = two->next;
        }
        one = one->next;
    }
}

int main()
{
    struct node *one = NULL, *two = NULL;
    one = at_tail(&one, 4);
    at_tail(&one, 24);
    at_tail(&one, 5);
    at_tail(&one, 10);
    print_ll(one);

    two = at_tail(&two, 4);
    at_tail(&two, 5);
    at_tail(&two, 3);
    at_tail(&two, 10);
    print_ll(two);
    find_common(one, two);
    return 0;
}