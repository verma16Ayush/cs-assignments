/** 
 *
 * @author - Ayush Verma 194051
 * @title - a5q1.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-11-12 12:10
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


int main()
{
    int a = GetInt(NULL);
}