/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q11.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 14:46
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("enter no of elements: ");
    scanf("%d", &n);
    int* a = (int*)malloc(n * sizeof(int));
    printf("enter elements: ");
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        *(a + i) = temp;
    }

    printf("the array is: ");
    for (int* i = a; i != a + n; i++)
    {
        printf("%d ", *i);
    }
    return 0;
}