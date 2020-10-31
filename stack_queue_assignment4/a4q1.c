/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q1.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-30 00:53
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int GetInt(const char* msg)
{
    if(msg) printf(msg);
    int temp;
    scanf("%d", &temp);
    return temp;
}

struct Stack
{
    int top;
    unsigned int cap;
    int* array;
};

struct Stack InitStack(const unsigned int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->cap = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->cap * sizeof(int));
    return *stack;
}

bool IsEmpty(struct Stack* stack) { return stack->top == -1;}

bool IsFull(struct Stack* stack) { return stack->top == stack->cap - 1;}

int StackSize(struct Stack* stack){ return stack->top - 1;}

int Pop(struct Stack* stack)
{
	if(!IsEmpty(stack)){ return stack->array[(stack->top)--];}

	printf("STACK_UNDERFLOW\n");

	return NULL;
}

void Push(struct Stack* stack, int data)
{
	if(!IsFull(stack))
	{
		stack->array[++(stack->top)] = data;
		return;
	}
	printf("STACK_OVERFLOW\n");
}

int Top(struct Stack* stack)
{
	if(!IsEmpty(stack)) return stack->array[stack->top];

	printf("STACK_EMPTY\n");
	return NULL;
}

void PrintStack(struct Stack* stack)
{
	// while(stack->top != -1) 
	// {
	// 	printf("%d ", stack->array[stack->top])
	// }
	int i= stack->top;
	for(i; i != -1; i--)
	{
		printf("%d ", stack->array[i]);
	}
	printf("\n");
}

int main()
{
    unsigned int capacity = GetInt("enter max size for stack: ");
    struct Stack stack = InitStack(capacity);
	
	printf("enter data in stack: ");
	while(!IsFull(&stack))
	{
		Push(&stack, GetInt(NULL));
	}

	int t = GetInt("enter one more element to demonstrate stack overflow: ");
	Push(&stack, t);

	printf("stack elements: ");
	PrintStack(&stack);

	t = GetInt("enter no of stack enteries to delete: ");
	for (int i = 0; i < t; i++)
	{
		int t = Pop(&stack);
		if(t)
		{
			printf("Stack entry deleted: %d\n", t);
		}
	}
	return 0;
}