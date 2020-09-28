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

int main()
{
    int n;
    printf("enter number of elements in array: ");
    int a[100];
    scanf("%d", &n);
    printf("\nenter elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, n);
    
    printf("\nsorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;

    
}