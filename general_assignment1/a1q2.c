/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q2.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 10:05
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[100];
    int carr[1001] = {0};
    int n;
    int max = -1;
    printf("enter the number of elements\n");
    scanf("%d", &n);
    printf("enter %d positive numbers with atmost value of 1000\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] > max)
            max = arr[i];
        carr[arr[i]]++;
    }
    for (int i = 0; i < 1000; i++)
    {
        if(carr[i] != 0)
            printf("%d occurs %d times\n", i, carr[i]);
    }
    return 0;
}