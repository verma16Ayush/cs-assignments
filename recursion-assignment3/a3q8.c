/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q8.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-19 00:11
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    struct Node* next;
    int data;
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

struct Node* Collect(struct Node* head, int even)
{
    /**
     * @param - put even as 0 if you want to collect even numbers
     **/
    struct Node* h = NULL;

    if(head == NULL) return h;

    if(head->data % 2 == even)
    {
        h = head;
        h->next = Collect(head->next, even);
    }
    else Collect(head->next, even);

    return h;
}

void Rearrange(struct Node* head, struct Node* odd, struct Node* even, struct Node** oddRef)
{
	if (head == NULL)
	{
		odd->next = NULL;
		even->next = (*oddRef)->next;
		return;
	}

	if (head->data & 1)
	{
		odd->next = head;
		Rearrange(head->next, head, even, oddRef);
	}
	else
	{
		even->next = head;
		Rearrange(head->next, odd, head, oddRef);
	}
}

// Rearrange the given linked list by separating odd nodes
// from even ones and maintaining their relative order.
void RearrangeDriver(struct Node** head)
{
	struct Node* odd = (struct Node*)malloc(sizeof(struct Node));
	struct Node* even = (struct Node*)malloc(sizeof(struct Node));

	Rearrange(*head, odd, even, &odd);

	*head = even->next;

	free(odd);
	free(even);
}

void PrintList(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d -> ", curr->data);
    PrintList(curr->next);
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

    // struct Node* he = Collect(head, 0);
    // struct Node* ho = Collect(head, 1);

    RearrangeDriver(&head);
    PrintList(head);
    return 0;

}