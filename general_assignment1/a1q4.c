/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q4.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 10:55
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[101];
    int n;
    printf("enter max number of elements (atmost 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        swap(&a[i], &a[n - 1 - i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
    
}