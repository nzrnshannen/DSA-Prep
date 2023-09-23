#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int *elemPtr;
    int count;
}Node, *LIST;

void Initialize(LIST *L);
void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void makeNull(LIST *L);
void Print(LIST L);
void Insert(LIST *L, int elem);

void Initialize(LIST *L)
{
    (*L)->count=0;
    (*L)->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if((*L)->elemPtr==NULL)
    {
        printf("\nMemory allocation failure.\n");
    }
}

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

void makeNull(LIST *L)
{
    free((*L)->elemPtr);
    (*L)->elemPtr=NULL;
    (*L)->count=0;
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

void Insert(LIST *L, int elem)
{
    if(isFull(*L))
    {
        fullListMsg();
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


int main()
{
    Node myList;
    LIST L = &myList;
    Initialize(&L);
    Insert(&L, 1);
    Insert(&L, 2);
    Print(L);
    makeNull(&L);
    return 0;
}
