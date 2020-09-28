/** 
 *
 * @author - Ayush Verma 194051
 * @title - a1q6.c
 * @mail - 194051@nith.ac.in
 * @createdOn - 2020-09-28 11:35
 * 
 **/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char title[50];
    char author[50];
    int pages;
    int price;
    int sold;
    int amount;
};

void get_books(struct Book* book, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("book name: ");
        gets(book[i].title);
        printf("author: ");
        gets(book[i].author);
        printf("pages: ");
        scanf("%d", &book[i].pages);
        printf("price: ");
        scanf("%d", &book[i].price);
        printf("copies sold: ");
        scanf("%d", &book[i].sold);
        while ((getchar()) != '\n');
        book[i].amount = book[i].sold * book[i].price;
    }
}

void show_book(struct Book book)
{

    printf("title: %s\n", book.title);
    printf("author: %s\n", book.author);
    printf("page count: %d\n", book.pages);
    printf("price: %d\n", book.price);
    printf("price: %d\n", book.price);
    printf("amount collected: %d\n", book.amount);
}

int get_data(struct Book* book, int n)
{
    int max_pages = 0;
    int imax_pages = 0;
    int max_price = 0;
    int imax_price = 0;
    int money = 0;
    for (int i = 0; i < n; i++)
    {
        if(book[i].pages > max_pages)
        {
            max_pages = book[i].pages;
            imax_pages = i;
        }

        if(book[i].price > max_price)
        {
            max_price = book[i].price;
            imax_price = i;
        }
        money += book[i].amount;
    }
    printf("\nthe book with most pages is: \n");
    show_book(book[imax_pages]);
    printf("\nthe book with max price: \n");
    show_book(book[imax_price]);
    return money;
}


int main()
{
    struct Book book[100];
    printf("enter the number of books you want to keep record of: ");
    int n;
    scanf("%d", &n);
    while ((getchar()) != '\n');
    get_books(book, n);
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        show_book(book[i]);
    }
    printf("\ntotal money earned: %d", get_data(book, n));
    return 0;
    
}