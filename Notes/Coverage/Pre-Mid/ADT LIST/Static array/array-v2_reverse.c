#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}Node, *LIST;

bool isEmpty(LIST L);
bool isFull(LIST L);
void emptyListMsg();
void fullListMsg();
void initList(LIST L);
void Print(LIST L);
void Insert(LIST L, int elem);
void Reverse(LIST L);

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

void initList(LIST L)
{
    L->count=0;
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
            printf("%d ", L->data[i]);
        
        printf("\n");
    }
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
        printf("\n\n\tElement %d inserted.\n\n", elem);
    }
}

void Reverse(LIST L)
{
    if(isEmpty(L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, swap;
        for(i=0, j=L->count-1; i<=j; i++, j--)
        {
            swap = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = swap;
        }
        
        printf("\n\t>> List Reversed. <<\n");
    }
}

int main()
{
    Node myList;
    LIST A = &myList;
    initList(A);
    Insert(A, 1);
    Insert(A, 2);
    Insert(A, 3);
    Insert(A, 4);
    Insert(A, 5);
    Print(A);
    Reverse(A);
    Print(A);
    return 0;
}