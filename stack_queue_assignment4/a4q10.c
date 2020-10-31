/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q10.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-31 13:28
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

int GetInt(const char* msg)
{
    if(msg) printf(msg);
    int temp;
    scanf("%d", &temp);
    return temp;
}

void PushStack(struct Node** stackHead, int data)
{
    if(stackHead == NULL)
    {
        *stackHead = (struct Node*)malloc(sizeof(struct Node));
        (*stackHead)->data = data;
        (*stackHead)->next = NULL;
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *stackHead;
    *stackHead = newNode;
    return;
}

int PopStack(struct Node** stack)
{
    if(*stack == NULL) return NULL;

    int temp = (*stack)->data;
    
	struct Node* toDel = *stack;
	*stack = (*stack)->next;
	free(toDel);
	return temp;
}

void Enq(struct Node** rear, struct Node** front, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*front == NULL)
    {
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

int Deq(struct Node** rear, struct Node** front)
{
    if(*front == NULL)
    {
        printf("\nQUEUE_EMPTY\n");
        return NULL;
    }

    int temp = (*front)->data;
     
    if(*rear == *front)
    {
        *rear = NULL;
        *front = NULL;
        return temp;
    }

    struct Node* toDel = *front;
    *front = (*front)->next;
    free(toDel);
    return temp;
}

void PrintQ(struct Node* curr)
{
    if(curr == NULL) return;
    printf("%d, ", curr->data);
    PrintQ(curr->next);
}

int main()
{
	struct Node* stackHead = NULL;
	struct Node* front = NULL;
	struct Node* rear = NULL;

	int n = GetInt("enter no of elements in queue: ");
	printf("enetr data in queue: ");
	for (int i = 0; i < n; i++)
	{
		int temp = GetInt(NULL);
		Enq(&rear, &front, temp);
	}

	int k = GetInt("enter K for first k elements to be reversed: ");
	for (int i = 0; i < k; i++)
	{
		int t = Deq(&rear, &front);
		PushStack(&stackHead, t);
	}

	int t = PopStack(&stackHead);
	while(t)	
	{
		Enq(&rear, &front, t);
		t = PopStack(&stackHead);
	}

	for (int i = 0; i < n - k; i++)
	{
		t  = Deq(&rear, &front);
		Enq(&rear, &front, t);
	}
	
	PrintQ(front);
	return 0;
}