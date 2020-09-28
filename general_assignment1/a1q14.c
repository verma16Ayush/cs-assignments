/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q14.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 16:18
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int a[100][100];
    int n, m;
    int zeroes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)
                zeroes++;
        }
        
    }

    if(2 * zeroes > n * m)
    {
        printf("sparse matrix");
    }
    else
    {
        printf("not a sparse matrix");
    }
    return 0;
}