#include <stdio.h>
#include <string.h>
#include <math.h>
struct Student
{
    int roll_no;
    char name[100];
    char grade;
};

int main()
{
    

    
    struct Student student[5];
    for (int i = 0; i < 5; i++)
    {
        printf("roll_no: ");
        scanf("%d", &student[i].roll_no);
        while ((getchar()) != '\n');
        printf("\ngrade: ");
        scanf("%c", &student[i].grade);
        printf("\nname: ");
        gets(student[i].name);
        while ((getchar()) != '\n');
    }

    for (int i = 0; i < 5; i++)
    {
        printf("\nname: %s", student[i].name);
        printf("\nroll_no: %d", student[i].roll_no);
        printf("\ngrade: %c", student[i].grade);
        printf("\n");
    }
    
    return 0;
    
}