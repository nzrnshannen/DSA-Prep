#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
    int *elemPtr;
    int count;
}Node, *LIST;

void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void Initialize(LIST *L);
void Print(LIST L);
void Insert(LIST *L, int elem);
void Delete(LIST *L, int ndx);
void makeNull(LIST *L);

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

bool isEmpty(LIST L)
{
    return (L->count==0);
}

bool isFull(LIST L)
{
    return (L->count==MAX);
}

void Initialize(LIST *L)
{
    (*L)->count=0;
    (*L)->elemPtr=(int*)malloc(sizeof(int) * MAX);
    if((*L)->elemPtr==NULL)
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
        for(i=0; i<L->count; i++)
            printf("%d ", L->elemPtr[i]);

        printf("\n");
    }
}

void makeNull(LIST *L)
{
    free((*L)->elemPtr);
    (*L)->elemPtr=NULL;
    (*L)->count=0;
}

void Insert(LIST *L, int elem)
{
    if(isFull(*L))
    {
        fullListMsg();
        printf("\n\tReallocating...\n");
        int newSize = MAX * 2;
        (*L)->elemPtr = (int*)realloc((*L)->elemPtr, sizeof(int) * newSize);
        if((*L)->elemPtr==NULL)
        {
            printf("\nMemory allocation failure.\n");
            exit(1);
        }
    }
    (*L)->elemPtr[(*L)->count++] = elem;
}

void Delete(LIST *L, int ndx)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else if(ndx<0 || ndx > (*L)->count-1)
    {
        printf("\n\tPlease use an appropriate index for deletion.\n");
    }
    else
    {
        int i;
        for(i=0; i<ndx; i++){}

        for(; i<=(*L)->count-1; i++)
            (*L)->elemPtr[i] = (*L)->elemPtr[i+1];

        (*L)->count--;

        printf("\n\t>> Deletion successful. <<\n");
    }
}

int main()
{
    Node myList;
    LIST L = &myList;
    Initialize(&L);
    Insert(&L, 1);
    Insert(&L, 2);
    Insert(&L, 5);
    Delete(&L, 0);
    Print(L);
    makeNull(&L);
    return 0;
}