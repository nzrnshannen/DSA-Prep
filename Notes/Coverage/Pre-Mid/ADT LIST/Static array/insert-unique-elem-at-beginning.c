#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef struct node{
    int data[MAX];
    int count;
}Node, *LIST;

//void delete() not applicable in this program
void initList(LIST A);
void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST A);
bool isFull(LIST A);
void Print(LIST A);
void Populate(LIST A);
void Insert(LIST A, int elem); //insert elem at beginning if not on the list

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

void Populate(LIST A)
{
    int i;
    for(i=1; i<=5; i++)
    {
        A->data[A->count++] = i;
    }
}

void Insert(LIST A, int elem)
{
    int i;
    for(i=0; i<A->count&&A->data[i]!=elem; i++){}

    if(i==A->count)
    {
        for(; i>0; i--) A->data[i] = A->data[i-1];
        A->data[i] = elem;
        A->count++;
        printf("\n\tElement %d inserted.\n", elem);
    }
    else
    {
        printf("\n\n >> Element %d already exists! <<\n\n", elem);
    }
}

int main()
{
    Node L;
    LIST P = &L;
    initList(P);
    Populate(P);
    Print(P);
    Insert(P, 99);
    Insert(P, 12);
    Insert(P, 12);
    Print(P);

    return 0;
}