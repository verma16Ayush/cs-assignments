/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q9.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 13:44
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int n)
{
    int* i;
    int* j;
    for (i = a; i != &a[n]; i++)
    {
        for (j = i; j != &a[n - 1]; j++)
        {
            if(*i > *j)
                swap(i, j);
        }
    }
}

int del(int* a, int n)
{
    if(n == 0 || n == 1)
        return n;
    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if(a[i] != a[i+1])
            a[j++] = a[i];
    }
    a[j] = a[n-1];
    return j + 1;
}

int main()
{
    int a[100];
    int n;
    printf("enter no. of elemets");
    scanf("%d", &n);
    printf("enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    
    n = del(a, n);
    printf("reformed array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}