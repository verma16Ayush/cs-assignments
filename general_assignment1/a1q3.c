/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q3.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 10:41
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
long long int fib(int n )
{
    if(n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("enter value of n (atmost 15)", &n);
    printf("%lld", fib(n));
    return 0;
}