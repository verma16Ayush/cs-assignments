/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q1.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 09:19
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int id;
    char name[100];
    char city[100];
};

int search(struct Employee* employee, int n)
{
    printf("enter the employee id to be searched: ");
    int key;
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
    {
        if(employee[i].id == key)
            return i;
    }
    printf("\n");
    return -1;
}

void swap(struct Employee* a, struct Employee* b)
{
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

void sort_records(struct Employee* employee, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(employee[i].id > employee[j].id)
                swap(&employee[i], &employee[j]);
        }  
    }
    return;
}

void add(struct Employee* employee)
{
    printf("enter 5 more employees\n");
    for (int i = 5; i < 10; i++)
    {
        printf("enter id: ");
        scanf("%d", &employee[i].id);
        while ((getchar()) != '\n');
        // printf("\n");
        printf("enter employee name: ");
        gets(employee[i].name);
        // printf("\n");
        printf("enter city: ");
        gets(employee[i].city);
    }
    
}

int main()
{
    struct Employee employee[10];
    printf("Enter employee details\n");
    for (int i = 0; i < 5; i++)
    {
        printf("enter id: ");
        scanf("%d", &employee[i].id);
        while ((getchar()) != '\n');
        // printf("\n");
        printf("enter employee name: ");
        gets(employee[i].name);
        // printf("\n");    
        printf("enter city: ");
        gets(employee[i].city);
    }
    add(employee);
    sort_records(employee, 10);
    int k = search(employee, 10);
    if(k!=-1)
    {
        printf("id: %d\n", employee[k].id);
        printf("name: %s\n", employee[k].name);
        printf("city: %d\n", employee[k].city);
    }
    return 0;
}