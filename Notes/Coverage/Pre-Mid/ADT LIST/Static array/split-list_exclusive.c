/*
    SPLITTING LIST (EXCLUSIVE)
    0 up until ndx-1 is for LIST A
    ndx up until L->count is for LIST B
*/

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
void initializeList(LIST L);
void Insert(LIST L, int elem);
void Print(LIST L);
void SplitList(LIST L, int ndx); 

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


void initializeList(LIST L)
{
    L->count=0;
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
            printf("%d ", L->data[i]);

        printf("\n\n");
    }
}

void SplitList(LIST L, int ndx)
{
    if(isEmpty(L))
    {
        emptyListMsg();
    }
    else if(ndx==0 || ndx > L->count-1)
    {
        printf("\nCannot split list!\n");
    }
    else
    {
        int i;
        Node A, B;
        LIST X, Y;
        X= &A; //maintaining the definition that LIST is a pointer to a structure 
        Y= &B;
        initializeList(X);
        initializeList(Y);
        for(i=0; i<ndx; i++)
            Insert(X, L->data[i]);
        
        for(; i<L->count; i++)
            Insert(Y, L->data[i]);

        printf("List A");
        Print(X);
        printf("List B");
        Print(Y);
    }
}

int main()
{
    Node myList;
    LIST P = &myList;
    initializeList(P);
    Insert(P, 1);
    Insert(P, 2);
    Insert(P, 3);
    Print(P);
    SplitList(P, 2);
    return 0;
}