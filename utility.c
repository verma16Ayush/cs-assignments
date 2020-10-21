/** 
 *
 * @author - Ayush Verma 194051
 * @title - utility.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-20 13:43
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int GetInt(const char* msg)
{
    if(msg) printf(msg);
    int temp;
    scanf("%d", &temp);
    return temp;
}

void PrintInt(int a)
{
    printf("%d ", a);
}

int main()
{
    
}