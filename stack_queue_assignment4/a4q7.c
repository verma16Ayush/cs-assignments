/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q7.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-31 12:22
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


int main()
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int flag = 0;

    for(;flag == 0;)
    {
        printf("chose: \n");
        printf("1. Enqueue: enter data in queue.\n");
        printf("2. Dequeue: delete from queue\n");
        printf("3. exit\n");
        printf("$> ");
        // while(getchar() == '\n');
        int c = GetInt(NULL);

        switch(c)
        {
            case 1:
            {   
                
                int data = GetInt("Enter data: ");
                Enq(&rear, &front, data);
                break;
            }
            case 2:
            {
                int t = Deq(&rear, &front);
                if(t) printf("entery deleted: %d\n", t);
                break;
            }
            case 3:
                flag = 1;
                break;
        }
    }
    return 0;
}