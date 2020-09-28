//Write a program to record the Book Number, Book Name, Book Type in a structure and print it.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct book_rec
    {
        int boo_num;
        char book_name[100];
        char book_type[1000];
    };
    
    struct book_rec book1 = {123456, "thousand splendid suns", "fiction"};
    struct book_rec book2 = {123457, "the subtle art of not", "non-fiction"};

    printf("NUMBER\tTYPE\t\t\tTYPE\n");
    printf("%d\t%s\t%s\n", book1.boo_num, book1.book_name, book1.book_type);
    printf("%d\t%s\t%s\n", book2.boo_num, book2.book_name, book2.book_type);
    return 0;
}