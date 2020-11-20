/** 
 *
 * @author - Ayush Verma 194051
 * @title - hash.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-11-17 12:35
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
    char key[100];
    int value;
    struct Node* next;
};
int cs, ts; // current table size and max Table size
struct Node** hashMap;

int GetInt(const char* msg)
{
    if(msg) printf(msg);
    int temp;
    scanf("%d", &temp);
    while ((getchar()) != '\n');
    return temp;
}

int GenHash(char* key)
{
    int len = strlen(key);
    int ans = 0;
    int p = 1; // any^0 = 1

    for (int i = 0; key[i] != '\0'; i++)
    {
        ans += key[len - i - 1] * p;
        p = p * 37;
        p %= ts;
        ans %= ts;
    }

    return ans;    
}

void InitTable(int tsize)
{
    cs = 0;
    ts = tsize;
    hashMap = (struct Node**)malloc(sizeof(struct Node) * ts);
    memset(hashMap, 0, sizeof(struct Node) * ts);
}

void Insert(char* key, int value)
{
    int i = GenHash(key);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    // newNode->key = key; // note to self->never do this again.
    strcpy(newNode->key, key);
    newNode->next = hashMap[i];
    hashMap[i] = newNode;
    cs++;
}

int* search(char* key)
{
    int i = GenHash(key);
    struct Node* temp = hashMap[i];
    while (temp != NULL)
    {
        if(strcmp(temp->key, key) == 0) return &(temp->value);
        temp = temp->next;
    }
    return NULL;
}

void PrintList(struct Node* head)
{
    struct Node* curr = head;
    for(curr; curr != NULL; curr = curr->next)
    {
        printf("key: %s, Value: %d ->", curr->key, curr->value);
    }
    printf("\n");
}

void PrintHm()
{
    for (int i = 0; i < ts; i++)
    {
        struct Node* temp = hashMap[i];
        printf("At Index: %d || ", i);
        PrintList(temp);
    }
}

int main()
{
    // InitTable(7);
    char key[100] = "";
    int n = GetInt("enter no of values you want in the HashMap: ");
    InitTable(n);

    for (int i = 0; i < n; i++)
    {
        printf("enter Key: ");
        gets(key);
        int val = GetInt("enter Value: ");
        Insert(key, val);
    }

    
    char c;
    int flag = 1;
    int* result;
    while (flag)
    {
        printf("choose: \n");
        printf("1. search for a key \n");
        printf("2. print entire HashMap \n");
        printf("3. exit \n");
        printf("$> ");
        c = getchar();
        while ((getchar()) != '\n');
        printf("\n");
        switch (c)
        {
            case '1':
            {
                printf("enter key: ");
                gets(key);
                result = search(key);
                if(result) printf("value found: %d\n", *result);
                else printf("Not Found\n");
                break;
            }

            case '2':
            {
                PrintHm();
                break;
            }

            default: 
            {
				free(hashMap);
                flag = 0;
                break;
            }
        }
    }
    

    return 0;
}