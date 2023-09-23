#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int *elemPtr;
    int count;
}LIST;

bool isEmpty(LIST L);
bool isFull(LIST L);
void emptyListMsg();
void fullListMsg();
void Initialize(LIST *L);
void Print(LIST L);
void makeNull(LIST *L);
void Insert(LIST *L, int elem);
void Union(LIST *A, LIST *B);
void Intersection(LIST A, LIST B);
void Sort(LIST *L);
bool isSorted(LIST *L);

bool isSorted(LIST *L)
{
    int i;
    for(i=0; i<L->count-1 && L->elemPtr[i] <= L->elemPtr[i+1]; i++){}

    return (i==L->count-1);    
}

void Sort(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, swap;
        for(i=0; i<L->count; i++)
        {
            for(j=0; j<L->count-1; j++)
            {
                if(L->elemPtr[j] > L->elemPtr[j+1])
                {
                    swap = L->elemPtr[j];
                    L->elemPtr[j] = L->elemPtr[j+1];
                    L->elemPtr[j+1] = swap;
                }
            }
        }
    }
}

void Union(LIST *A, LIST *B)
{
    if(isEmpty(*A) || isEmpty((*B)))
    {
        emptyListMsg();
    }
    else
    {
        if(!(isSorted(A) && isSorted(B)))
        {
            Sort(A);
            Sort(B);
        }

        LIST C;
        Initialize(&C);
        int i, j;

        for(i=0, j=0; i<A->count && j<B->count; )
        {
            if(A->elemPtr[i]<B->elemPtr[j])
            {
                Insert(&C, A->elemPtr[i++]);
            }
            else if(B->elemPtr[j]<A->elemPtr[i])
            {
                Insert(&C, B->elemPtr[j++]);
            }
            else
            {
                Insert(&C, A->elemPtr[i]);
                i++, j++;
            }

            if(i==A->count)
            {
                for(; j<B->count; j++)
                    Insert(&C, B->elemPtr[j]);
            }
            
            if(j==B->count)
            {
                for(; i<A->count; i++)
                    Insert(&C, A->elemPtr[i]);
            }
        }

        printf("\n*****\nUNION");
        Print(C);
        makeNull(&C);
    }
}

void Intersection(LIST A, LIST B)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyListMsg();
    }
    else
    {
        if(!(isSorted(&A) && isSorted(&B)))
        {
            Sort(&A);
            Sort(&B);
        }

        LIST C;
        Initialize(&C);
        int i, j;

        for(i=0, j=0; i<A.count && j<B.count; )
        {
            if(A.elemPtr[i]<B.elemPtr[j])
            {
                i++;
            }
            else if(B.elemPtr[j]<A.elemPtr[i])
            {
                j++;
            }
            else
            {
                Insert(&C, A.elemPtr[i]);
                i++, j++;
            }
        }
        
        printf("*****\nINTERSECTION");
        Print(C);
        makeNull(&C);
    }
}
bool isEmpty(LIST L)
{
    return (L.count==0);
}

bool isFull(LIST L)
{
    return (L.count==MAX);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void Initialize(LIST *L)
{
    L->count=0;
    L->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if(L->elemPtr==NULL)
    {
        printf("\n\tMemory allocation failure.\n");
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
            printf("%d ", L.elemPtr[i]);
        
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
    }

    L->elemPtr[L->count++] = elem;
}

void makeNull(LIST *L)
{
    free(L->elemPtr);
    L->elemPtr=NULL;
    L->count=0;
    printf("\n\t>> Memory freed. <<\n");
}

int main()
{
    LIST listOne, listTwo;
    Initialize(&listOne);
    Initialize(&listTwo);
    Insert(&listOne, 1);
    Insert(&listOne, 2);
    Insert(&listOne, 3);
    Insert(&listOne, 8);

    Insert(&listTwo, 2);
    Insert(&listTwo, 8);
    Insert(&listTwo, 9);

    Union(&listOne, &listTwo); //using pass by reference for Union (but can be also pass by copy only)
    Intersection(listOne, listTwo); //using pass by copy 
    makeNull(&listOne);
    makeNull(&listTwo);
    return 0;
}