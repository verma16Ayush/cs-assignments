/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q10.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 14:35
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

int linear_search(int* a, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i] == key);
            return i;
    }
    return -1;
}

int binary_search(int* a, int n, int key)
{
	int start = 0;
	int end = n - 1;
	int mid;
	while(start <= end)
	{
		mid = start + (end - start) / 2;
		if(a[mid] == key)
			return mid;
		else if(key < a[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
  
	return -1;
}

int main()
{
    int a[100];
    int n;
    printf("no. of elements: ");
    scanf("%d", &n);
    printf("enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int key;
    printf("enter element to be searched: ");
    scanf("%d", &key);

    int r1 = linear_search(a, n, key);

    sort(a, n);
    int r2 = binary_search(a, n, key);

    printf("result by linear search: %d\n", r1);

    printf("sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("result by binary search: %d\n", r2);

    return 0;
}