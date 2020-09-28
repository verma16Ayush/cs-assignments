#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct  test
{
    int one;
    int two;
    int three;
};


int main()
{
    struct test test1;
    test1.one = 1;
    test1.two = 2;
    test1.three = 3;

    

    printf("%d", test1.one + test1.two + test1.three);
    return 0;
}