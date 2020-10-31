/** 
 *
 * @author - Ayush Verma 194051
 * @title - a4q5.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-10-30 00:06
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool Compare(const char* str1, const char* str2, int top)
{
    while(top != -1 && str2 != "\0")
    {
        if(str1[top--] != *str2++) return false;
    }
    return true;
}

int main()
{
    char st1[100];
    char* st2;

    printf("enter your string: ");
    gets(st1);

    int i = 0;
    while(st1[i] != 'X') i++;

    st2 = &st1[i+1];
    int top = i-1;
    if(Compare(st1, st2, top)) printf("Palindrome\n");
    else printf("Not Palindrome\n");

    return 0;
}