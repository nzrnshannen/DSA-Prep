#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}Node, *LIST;

void initList(LIST A);
void emptyListMsg();
void fullListMsg();
void Insert(LIST A, int elem);
void Delete(LIST A, int elem);
void Print(LIST A);
bool isEmpty(LIST A);
bool isFull(LIST A);

void initList(LIST A)
{
    A->count=0;
}

void emptyListMsg()
{   
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

bool isEmpty(LIST A)
{
    return (A->count==0);
}

bool isFull(LIST A)
{
    return (A->count==MAX);
}

void Insert(LIST A, int elem)
{
    if(isFull(A))
    {
        fullListMsg();
    }
    else
    {
        A->data[A->count++] = elem;
        printf("\n\tElement %d inserted.\n\n", elem);
    }
}

void Print(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        int i;
        printf("\n-----\nList: ");
        for(i=0; i<A->count; i++)
        {
            printf("%d ", A->data[i]);
        }

        printf("\n");
    }
}

void Delete(LIST A, int elem)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        int i, j=0;
        for(i=0; i<A->count; i++)
        {
            if(A->data[i]==elem)
            {
                for(j=i; j<A->count; j++)
                {
                    A->data[j] = A->data[j+1];
                }
                A->count--;
            }
        }

        if(j!=0)
        {
            printf("\n\t>> Element %d deleted. <<\n", elem);
        }
        else
        {
            printf("\n\t>> Element %d not found. <<\n", elem);
        }
    }
}

int main()
{
    Node myList;
    LIST L = &myList;
    initList(L);
    Insert(L, 1);
    Insert(L, 2);
    Insert(L, 3);
    Insert(L, 2);
    Insert(L, 5);
    Print(L);
    Delete(L, 10);
    Print(L);

    return 0;
}