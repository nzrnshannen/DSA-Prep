#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
typedef struct node{
    int *elemPtr;
    int count;
}LIST;

void initList(LIST *S);
bool isEmpty(LIST S);
bool isFull(LIST S);
void emptyListMsg();
void fullListMsg();
void makeNull(LIST *S);

void initList(LIST *S)
{
    S->count=0;
    S->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if(S->elemPtr==NULL)
    {
        printf("\nMemory allocation failure.\n");
        exit(1);
    }
}

bool isEmpty(LIST S)
{
    return (S.count==0);
}

bool isFull(LIST S)
{
    return (S.count==MAX);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void Insert(LIST *S, int elem)
{
    if(isFull(*S))
    {
        fullListMsg();
        printf("\n\tReallocating...");  
        int newSize = S->count * 2; 
        S->elemPtr = (int*)realloc(S->elemPtr, sizeof(int) * newSize);
        if(S->elemPtr==NULL)
        {
            printf("\nMemory allocation failure.\n");
            exit(1);
        }
        S->elemPtr[S->count++] = elem;
    }
    else   
    {
        S->elemPtr[S->count++] = elem;
    }
    
}

void Print(LIST S)
{
    if(isEmpty(S))
    {
        emptyListMsg();
    }
    else
    {
        int i;
        printf("\n-----\nList: ");
        for(i=0; i<S.count; i++)
            printf("%d ", S.elemPtr[i]);
        
        printf("\n");
    }
}

void makeNull(LIST *S)
{
    free(S->elemPtr);
    S->elemPtr=NULL;
    S->count=0;
    printf("\n\tMemory freed.");
}

int main()
{
    LIST A;
    initList(&A);
    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 3);
    Insert(&A, 4);
    Insert(&A, 5);
    Insert(&A, 6);
    Print(A);
    makeNull(&A);
    return 0;
}