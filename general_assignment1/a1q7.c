/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q7.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 13:02
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Directory
{
    char fname[50];
    char mname[50];
    char lname[50];
    char ph[10];
};

void parse(char* arg, struct Directory* dir)
{
    char* token = strtok(arg, " ");
    strcpy(dir->lname, token);
    token = strtok(NULL, " ");
    strcpy(dir->fname, token);
    token = strtok(NULL, " ");
    strcpy(dir->mname, token);
    token = strtok(NULL, " ");
    strcpy(dir->ph, token);
}

int main()
{
    struct Directory directory[100];
    int n;
    printf("no. of entries: ");
    scanf("%d", &n);
    while ((getchar()) != '\n');
    for (int i = 0; i < n; i++)
    {
        char str[200];
        gets(str);
        parse(str, &directory[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s, %c.%c %s", 
                directory[i].lname, 
                directory[i].fname[0], 
                directory[i].mname[0], 
                directory[i].ph);
        printf("\n");
    }
        
    return 0;
}