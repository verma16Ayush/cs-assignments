/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q62.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-31 14:28
 * 
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

int GetInt(const char* msg)
{
    if(msg) printf(msg);
    int temp;
    scanf("%d", &temp);
    return temp;
}

//Function to check if queue is empty or not
bool isempty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

//function to enter elements in queue
void enqueue(int value)
{
	//queue is full
	if ((rear + 1) % SIZE == front) printf("QUEUE_FULL\n");
	else
	{
		//first element inserted
		if (front == -1)
			front = 0;
		//insert element at rear
		rear = (rear + 1) % SIZE;
		A[rear] = value;
	}
}

//function to delete/remove element from queue
void dequeue()
{
	if (isempty()) printf("QUEUE_EMPTY\n");
	else if (front == rear)
		front = rear = -1;
	else
		front = (front + 1) % SIZE;
}

//function to show the element at front
void showfront()
{
	if (isempty()) printf("QUEUE_EMPTY\n");
	else printf("front element: %d\n", A[front]);
}

//function to display queue
void displayQueue()
{
	if (isempty())
		printf("QUEUE_EMPTY\n");
	else
	{
		int i;
		if (front <= rear)
		{
			for (i = front; i <= rear; i++)
				printf("%d ", A[i]);
		}
		else
		{
			i = front;
			while (i < SIZE)
			{
				printf("%d ", A[i]);
				i++;
			}
			i = 0;
			while (i <= rear)
			{
				printf("%d ", A[i]);
				i++;
			}
		}
	}
}

//Main Function
int main()
{
	int choice, flag = 1, value;
	while (flag == 1)
	{
		printf("\n1.enqueue 2.dequeue 3.showfront 4.displayQueue 5.exit\n");
		choice = GetInt(NULL);
		switch (choice)
		{
		case 1:
			value = GetInt("enter value: ");
			enqueue(value);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			showfront();
			break;
		case 4:
			displayQueue();
			break;
		case 5:
			flag = 0;
			break;
		}
	}

	return 0;
}