#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define MAX 5
typedef struct{
    int *elemPtr;
    int count;
}LIST;

void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void initList(LIST *L);
void Print(LIST L);
void Insert(LIST *L, int elem);
void Reverse(LIST *L);
void makeNull(LIST *L);

void emptyListMsg()
{
    printf("\n\n\tList is empty!");
}

void fullListMsg()
{
    printf("\n\n\tList is full!");
}

bool isEmpty(LIST L)
{
    return (L.count==0);
}

bool isFull(LIST L)
{
    return (L.count==MAX);
}

void initList(LIST *L)
{
    L->count=0;
    L->elemPtr =(int*)malloc(sizeof(int) * MAX);
    if(L->elemPtr==NULL)
    {
        printf("\nMemory allocation failure.\n");
        exit(1);
    }
}

void Print(LIST L)
{
    if(isEmpty(L))
    {
        emptyListMsg();
    }
    else
    {
        int i;
        printf("\n-----\nList: ");
        for(i=0; i<L.count; i++)
        {
            printf("%d ", L.elemPtr[i]);
        }

        printf("\n");
    }
}

void Insert(LIST *L, int elem)
{
    if(isFull(*L))
    {
        fullListMsg();
        printf("\n\tReallocating...\n");
        int newSize = L->count * 2;
        L->elemPtr = (int*)realloc(L->elemPtr, sizeof(int) * newSize);
        if(L->elemPtr==NULL)
        {
            printf("\nMemory allocation failure.\n");
            exit(1);
        }

        L->elemPtr[L->count++] = elem;
    }
    else
    {
        L->elemPtr[L->count++] = elem;
    }
}

void Reverse(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, swap;
        for(i=0, j=L->count-1; i<=j; i++, j--)
        {
            swap = L->elemPtr[i];
            L->elemPtr[i] = L->elemPtr[j];
            L->elemPtr[j] = swap;
        }

        printf("\n\t>> List reversed. <<\n");
    }
}

void makeNull(LIST *L)
{
    free(L->elemPtr);
    L->elemPtr=NULL;
    L->count=0;
    printf("\n\tMemory freed.\n");
}   

int main()
{
    LIST myList;
    initList(&myList);
    Insert(&myList, 1);
    Insert(&myList, 2);
    Insert(&myList, 3);
    Insert(&myList, 4);
    Insert(&myList, 3);
    Insert(&myList, 4);
    Print(myList);
    Reverse(&myList);
    Print(myList);
    makeNull(&myList);

    return 0;
}