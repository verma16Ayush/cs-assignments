/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q12.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 15:29
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void add_mat(int a[][100], int b[][100], int n)
{
    int sum[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return;
}


void multiply(int a[][100], int b[][100], int n)
{
    int i, j, k;
    int res[n][n]; 
    for (i = 0; i < n; i++) 
    { 
        for (j = 0; j < n; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < n; k++) 
                res[i][j] += a[i][k]*b[k][j]; 
        } 
    } 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
    return;
}


int main()
{
    int n;
    printf("enter dimension of square matrix: ");
    scanf("%d", &n);
    int a[100][100];
    int b[100][100];
    printf("enter matrix A: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }   
    }
    printf("enter matrix B: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }   
    }
    
    printf("sum matrix: \n");
    add_mat(a, b, n);
    printf("\nmultiplication: \n");
    multiply(a, b, n);
    return 0;
}