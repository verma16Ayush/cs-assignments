/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q13.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 15:58
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int m, n, z;
    printf("enter the dimensions for 3D matrix");
    scanf("%d%d%d", &m, &n, &z);
    int a[100][100][100];
    for (int k = 0; k < z; k++)
    {
        prinftf("enter the 2d matrix at a[][][%d]: \n", k);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }
    
}