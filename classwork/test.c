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

int main()
{
    struct Node* tnode = (struct Node*)malloc(sizeof(struct Node));
    // tnode->data = NULL;
    tnode->next = NULL;
    struct Node* curr = tnode->next;
    // tnode = NULL;
    bool s = curr == NULL;
    return 0;
}