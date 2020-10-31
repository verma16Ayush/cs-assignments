/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q4.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-30 00:36
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack
{
	int top;
	unsigned int cap;
	int *array;
};

int GetInt(const char *msg)
{
	if (msg)
		printf(msg);
	int temp;
	scanf("%d", &temp);
	return temp;
}

int Calculate(int a, int b, char op)
{
	switch (op)
	{
	case '*':
		return a * b;

	case '+':
		return a + b;

	case '-':
		return a - b;

	case '/':
		return a / b;
	}
	return 0;
}

struct Stack InitStack(const unsigned int capacity)
{
	struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
	stack->cap = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->cap * sizeof(int));
	return *stack;
}

bool IsEmpty(struct Stack *stack) { return stack->top == -1; }

bool IsFull(struct Stack *stack) { return stack->top == stack->cap - 1; }

int StackSize(struct Stack *stack) { return stack->top - 1; }

int Pop(struct Stack *stack)
{
	if (!IsEmpty(stack))
	{
		return stack->array[(stack->top)--];
	}

	printf("STACK_UNDERFLOW\n");

	return NULL;
}

void Push(struct Stack *stack, int data)
{
	if (!IsFull(stack))
	{
		stack->array[++(stack->top)] = data;
		return;
	}
	printf("STACK_OVERFLOW\n");
}

int Top(struct Stack *stack)
{
	if (!IsEmpty(stack))
		return stack->array[stack->top];

	printf("STACK_EMPTY\n");
	return NULL;
}

bool IsOp(const char c)
{
	char arr[5] = "+-*/";
	for (int i = 0; i <= 4; i++) if (c == arr[i]) return true;
	return false;
}

int main()
{
	struct Stack stack = InitStack(100);
	char expr[100];
	printf("enter expression: ");
	gets(expr);
	for (int i = 0; expr[i] != '\0'; i++)
	{
		if(!IsOp(expr[i]))
		{
			Push(&stack, expr[i] - 48);
		}
		else
		{
			int b = Pop(&stack);
			int a = Pop(&stack);
			int res = Calculate(a, b, expr[i]);
			Push(&stack, res);
		}
	}

	printf("result of expression is: %d", Pop(&stack));
	return 0;
}