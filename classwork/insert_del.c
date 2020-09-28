#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int a[100] = {0};
    srand(time(0));
    int num_ele = 20;

    for (int i = 0; i < num_ele; i++)
    {
        a[i] = rand() % 21;
    }

    printf("original array:\n\n");
    for (int i = 0; i < num_ele; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");


    printf("enter the pos to insert at and value to insert\n");
    int pos, val;
    scanf("%d%d", &pos, &val);
    num_ele++;


    for(int i = num_ele - 1; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = val;

    
    printf("updated array\n\n");
    for (int i = 0; i < num_ele; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    
    printf("enter the position to delete array\n");
    scanf("%d", &pos);

    for (int i = pos; i < num_ele; i++)
    {
        a[i] = a[i+1];
    }
    
    printf("\nupdated array\n\n");
    for (int i = 0; i < num_ele; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
    
}