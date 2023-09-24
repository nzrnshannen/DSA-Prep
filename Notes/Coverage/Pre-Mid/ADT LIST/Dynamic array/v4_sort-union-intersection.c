#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int *elemPtr;
    int count;
}Node, *LIST;

void emptyListMsg();
void fullListMsg();
void Union(LIST *X, LIST *Y);
void Intersection(LIST *X, LIST *Y);
bool isEmpty(LIST L);
bool isFull(LIST L);
bool isSorted(LIST L);
void Sort(LIST *L);
void Initialize(LIST *L);
void Insert(LIST *L, int elem);
void Print(LIST L);
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

void makeNull(LIST *L)
{
    (*L)->count=0;
    free((*L)->elemPtr);
    (*L)->elemPtr=NULL;
}

void Initialize(LIST *L)
{
    (*L)->count=0;
    (*L)->elemPtr = (int*)malloc(sizeof(int) * MAX);
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
            exit(1);
        }
    }

    (*L)->elemPtr[(*L)->count++] = elem;
}

void Union(LIST *X, LIST *Y)
{
    if(isEmpty(*X) || isEmpty(*Y))
    {
        emptyListMsg();
    }
    else
    {
        if(!isSorted(*X))
            Sort(X);
        
        if(!isSorted(*Y))
            Sort(Y);
        
        Node C;
        LIST Z = &C;
        Initialize(&Z);
        int i, j;

        for(i=0, j=0; i<(*X)->count && j<(*Y)->count; )
        {
            if((*X)->elemPtr[i] < (*Y)->elemPtr[j])
            {
                Insert(&Z, (*X)->elemPtr[i]);
                i++;
            }
            else if((*Y)->elemPtr[j] < (*X)->elemPtr[i])
            {
                Insert(&Z, (*Y)->elemPtr[j]);
                j++;
            }
            else
            {
                Insert(&Z, (*X)->elemPtr[i]);
                i++, j++;
            }

            if(i==(*X)->count)
            {
                for(; j<(*Y)->count; j++)
                    Insert(&Z, (*Y)->elemPtr[j]);
            }
            
            if(j==(*Y)->count)
            {
                for(; i<(*X)->count; i++)
                    Insert(&Z, (*X)->elemPtr[i]);
            }
        }

        printf("\nUNION");
        Print(Z);
        makeNull(&Z);
    }
}

bool isSorted(LIST L)
{
    int i;
    for(i=0; i<L->count-1 && L->elemPtr[i] <= L->elemPtr[i+1]; i++){}

    return (i==L->count-1);
}

void Sort(LIST *S)
{
    if(isEmpty(*S))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, swap;
        for(i=0; i<(*S)->count; i++)
        {
            for(j=0; j<(*S)->count-1; j++)
            {
                if((*S)->elemPtr[j+1] < (*S)->elemPtr[j])
                {
                    swap = (*S)->elemPtr[j+1];
                    (*S)->elemPtr[j+1] = (*S)->elemPtr[j];
                    (*S)->elemPtr[j] = swap;
                }
            }
        }
    }
}

void Intersection(LIST *X, LIST *Y)
{
    if(isEmpty(*X) || isEmpty(*Y))
    {
        emptyListMsg();
    }
    else
    {
        if(!isSorted(*X))
            Sort(X);

        if(!isSorted(*Y))
            Sort(Y);

        Node C;
        LIST Z = &C;
        Initialize(&Z);
        int i, j;
        for(i=0, j=0; i<(*X)->count && j<(*Y)->count; )
        { 
            if((*X)->elemPtr[i] < (*Y)->elemPtr[j])
            {
                i++;
            }
            else if((*Y)->elemPtr[j] < (*X)->elemPtr[i])
            {
                j++;
            }
            else
            {
                Insert(&Z, (*X)->elemPtr[i]);
                i++, j++;    
            }
        }

        printf("\nINTERSECTION");
        Print(Z);
        makeNull(&Z);
    }
}
int main()
{
    Node listOne, listTwo;
    LIST A, B;
    A = &listOne;
    B = &listTwo;

    Initialize(&A);
    Initialize(&B);

    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 1);

    Insert(&B, 1);
    Insert(&B, 2);
    Intersection(&A, &B);
    makeNull(&A);
    makeNull(&B);
    return 0;
}