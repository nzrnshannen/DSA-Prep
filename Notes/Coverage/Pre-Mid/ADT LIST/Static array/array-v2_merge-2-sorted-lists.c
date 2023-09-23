#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}Node, *LIST;

void emptyListMsg();
void fullListMsg();
void Insert(LIST L, int elem);
void Print(LIST L);
bool isEmpty(LIST L);
bool isFull(LIST L);
void initializeList(LIST L);
void Sort(LIST L);
bool isSorted(LIST L);
void Merge(LIST X, LIST Y);

void initializeList(LIST L)
{
    L->count=0;
}

bool isEmpty(LIST L)
{
    return (L->count==0);
}

bool isFull(LIST L)
{
    return (L->count==MAX);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void Insert(LIST L, int elem)
{
    if(isFull(L))
    {
        fullListMsg();
    }
    else
    {
        L->data[L->count++] = elem;
        printf("\n\tElement %d inserted.\n", elem);
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
        {
            printf("%d ", L->data[i]);
        }

        printf("\n");
    }
}

void Sort(LIST L)
{
    if(isEmpty(L))
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
                if(L->data[j]>L->data[j+1])
                {
                    swap = L->data[j];
                    L->data[j] = L->data[j+1];
                    L->data[j+1] = swap;
                }
            }
        }
    }
}

bool isSorted(LIST L)
{
    int i;
    for(i=0; i<L->count-1 && L->data[i]<=L->data[i+1]; i++){}

    return (i==L->count-1);
}

void Merge(LIST X, LIST Y)
{
    if(isEmpty(X) || isEmpty(Y))
    {
        emptyListMsg();
    }
    else if((X->count + Y->count) > MAX)
    {
        printf("\n\n\tNew list will exceed to the given MAX.\n\n");
    }
    else
    {
        Node listC;
        LIST Z = &listC; //this is to maintain the definition of array version 2 that LIST is a pointer to a structure (Node)
        initializeList(Z);

        if(isSorted(X) && isSorted(Y))
        {
            int i;
            for(i=0; i<X->count; i++)
                Insert(Z, X->data[i]);
            
            for(i=0; i<Y->count; i++)
                Insert(Z, Y->data[i]);
            
            Sort(Z);
            printf("\n*****\nMerged list: ");
            Print(Z);
        }
        else
        {
            printf("\n\n\tSort list first!\n\n");
        }
    }
}

int main()
{
    Node listA, listB;
    LIST A = &listA;
    LIST B = &listB;;
    initializeList(A);
    initializeList(B);
    Insert(A, 5);
    Insert(A, 2);
    Insert(A, 3);
    Sort(A);
    Print(A);

    Insert(B, 4);
    Insert(B, 5);
    Insert(B, 1);
    Print(B);

    Merge(A, B);
    return 0;
}