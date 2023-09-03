//remove occurrences of a specified element

/*
    Program made for testing only
*/

#include<stdio.h>
#define MAX_SIZE 5
typedef struct{
    char elem[MAX_SIZE];
    int count;
}LIST;

void Insert(LIST *list, int elem)
{
    if(list->count>=MAX_SIZE)
    {
        printf("\nList is full.\n");
        return;
    }
    else
    {
        list->elem[list->count++] = elem;
        printf("\n\tElement inserted.\n\n");
    }
}

void DeleteOccurrences(LIST *list, int elem)
{
    int i, j, curr_size = list->count;

    for(i=0; i<list->count; i++)
    {
        if(list->elem[i] == elem)
        {
            for(j=i; j<list->count; j++)
            {
                list->elem[j] = list->elem[j+1];
            }
            list->count--;
        }
    }
    
    if(list->count==curr_size)
    {
        printf("\nThe element %d can't be found on the list.\n", elem);
    }
    else
    {
        printf("\nSuccessfully removed element.");
    }
}

void initializeList(LIST *list)
{
    list->count=0;
}

int isEmpty(LIST *list)
{
    return (list->count==0);
}

int isFull(LIST *list)
{
    return (list->count==MAX_SIZE);
}

void Display(LIST *list)
{
    int i;
    printf("\n-----\nList: ");
    for(i=0;i<list->count;i++)
    {
        printf("%d ", list->elem[i]);
    }

    printf("\n");
}

int main()
{
    LIST myList;
    initializeList(&myList);

    if(isEmpty(&myList))
    {
        printf("List is empty at the moment.\n");
    }

    Insert(&myList, 5);
    Insert(&myList, 10);
    Insert(&myList, 5);
    
    Display(&myList);
    Insert(&myList, 9);
    Insert(&myList, 88);
    Insert(&myList, 19);

    Display(&myList);

    DeleteOccurrences(&myList, 1);
    Display(&myList);
}