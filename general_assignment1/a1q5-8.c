/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q5-8.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 13:33
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char* find_replace(const char* arg, const char* find, const char* replace) 
{ 
    char* result; 
    int i, count = 0; 
    int replace_len = strlen(replace); 
    int find_len = strlen(find); 
 
    for (i = 0; arg[i] != '\0'; i++) 
    { 
        if (strstr(&arg[i], find) == &arg[i]) 
        { 
            count++; 
            i += find_len - 1; 
        } 
    }  
    result = (char*)malloc(i + count * (replace_len - find_len) + 1); 
  
    i = 0; 
    while (*arg) 
    { 
        if (strstr(arg, find) == arg) 
        { 
            strcpy(&result[i], replace); 
            i += replace_len; 
            arg += find_len; 
        } 
        else
        {
            result[i++] = *arg++;
        } 
    }
    result[i] = '\0'; 
    return result; 
} 

int main()
{
    char str[200];
    char find[50];
    char replace[50];

    printf("enter the string: ");
    gets(str);
    printf("find pattern: ");
    gets(find);
    printf("replace with: ");
    gets(replace);
    printf("new string is: \n");
    printf("%s", find_replace(str, find, replace));
    return 0;
}