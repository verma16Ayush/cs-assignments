/** 
 *
 * @author - Ayush Verma 194051
 * @title - a3q2.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-30 01:05
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

bool IsFull(struct Node** head)
{
	return false;
}

bool IsEmpty(struct Node** head)
{
	return *head == NULL;
}

int StackSize(struct Node* head)
{
	struct Node* curr = head;
	int count = 0;
	for(curr; curr!=NULL; curr=curr->next) count++;
	return count;
}

int Top(struct Node* head) {return head->data;}

void Push(struct Node** head, int data)
{
	if(*head == NULL)
	{
		*head = (struct Node*)malloc(sizeof(struct Node));
		(*head)->next = NULL;
		(*head)->data = data;
		return;
	}
    if(!IsFull(head))
	{
		struct Node* newHead = (struct Node*)malloc(sizeof(struct Node));
		newHead->data = data;
		newHead->next = *head;
		*head = newHead;
		return;
	}

	printf("STACK_OVERFLOW\n");
}

int Pop(struct Node** head)
{
	if(!IsEmpty(head))
	{
		struct Node* temp = *head;
		int data = temp->data;
		*head = (*head)->next;
		free(temp);
		return data;
	}
	printf("STACK_UNDERFLOW\n");
	return NULL;
}

void PrintStack(struct Node* head)
{
	if(head == NULL) return;
	printf("%d-> ", head->data);
	PrintStack(head->next);
}

int main()
{
    struct Node* stackHead = NULL;
	int size = GetInt("enter stack size: ");
	printf("enter stack data: ");
	for (int i = 0; i < size; i++)
	{
		int data = GetInt(NULL);
		Push(&stackHead, data);
	}

	printf("stack elements: \n");
	PrintStack(stackHead);
	printf("\n");
	printf("stack size: %d\n", StackSize(stackHead));
	printf("top of stack: %d\n", Top(stackHead));

	int t = GetInt("enter no of stack enteries to delete: ");
	for (int i = 0; i < t; i++)
	{
		int t = Pop(&stackHead);
		if(t)
		{
			printf("Stack entry deleted: %d\n", t);
		}
	}
	return 0;
}