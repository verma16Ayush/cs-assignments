// Write a Program to take 20 integer inputs from user and print the following:
// number of positive numbers            
// number of negative numbers
// number of odd numbers
// number of even numbers 
// number of Zeroes

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int p = 0, n = 0, o = 0, e = 0, z = 0;
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &n);

        if(n >= 0)
        {
            p++;
        }
        if(n<0)
        {
            n++;
        }
        if(n %2 == 0) 
        {
            e++;
        }
        if (n %2 == 1)
        {
            o++;
        }
        if(n == 0)
        {
            z++;
        }
    }
    
    printf("%d positives\n", p);
    printf("%d negatives\n", n);
    printf("%d ndds\n", o);
    printf("%d evens\n", e);
    printf("%d zeroes\n", z);
    return 0;
}