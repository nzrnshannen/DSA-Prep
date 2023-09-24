#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int *elemPtr;
    int count;
}Node, *LIST;

void Print(LIST L);
void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void Insert(LIST *L, int elem);
void Reverse(LIST *L);
void Initialize(LIST *L);
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

void Print(LIST L)
{
    if(isEmpty(L))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        int i;
        for(i=0; i<L->count; i++)
            printf("%d ", L->elemPtr[i]);
        
        printf("\n");
    }
}

void Insert(LIST *L, int elem)
{
    if(isFull(*L))
    {   
        fullListMsg();
        printf("\nReallocating...\n");
        int newSize = (*L)->count * 2;
        (*L)->elemPtr = (int*)realloc((*L)->elemPtr, sizeof(int) * newSize);
        if((*L)->elemPtr==NULL)
        {
            printf("\nMemory allocation failure.\n");
        }
    }

    (*L)->elemPtr[(*L)->count++] = elem;
}

void Initialize(LIST *L)
{
    (*L)->count=0;
    (*L)->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if((*L)->elemPtr==NULL)
    {
        printf("\nMemory allocation failure.");
        exit(1);
    }
}

void makeNull(LIST *L)
{
    free((*L)->elemPtr);
    (*L)->elemPtr=NULL;
    (*L)->count=0;
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
        for(i=0, j=(*L)->count-1; i<=j; i++, j--)
        {
            swap = (*L)->elemPtr[i];
            (*L)->elemPtr[i] = (*L)->elemPtr[j];
            (*L)->elemPtr[j] = swap;
        }

        printf("\n\t>> List reversed <<\n");
    }
}

int main()
{
    Node myList;
    LIST P = &myList;
    Initialize(&P);
    Insert(&P, 1);
    Insert(&P, 2);
    Insert(&P, 3);
    Insert(&P, 4);
    Insert(&P, 5);
    Insert(&P, 6);
    Print(P);
    Reverse(&P);
    Print(P);

    makeNull(&P);

    return 0;
}