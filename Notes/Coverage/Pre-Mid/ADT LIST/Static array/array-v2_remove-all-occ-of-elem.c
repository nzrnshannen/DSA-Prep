#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct node{
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
void RemoveAllOccurrences(LIST L, int elem);

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

void RemoveAllOccurrences(LIST L, int elem)
{
    if(isEmpty(L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j;
        int checker = L->count;
        for(i=0; i<L->count; i++)
        {   
            if(L->data[i]==elem)
            {
                for(j=i; j<L->count; j++)
                {
                    L->data[j] = L->data[j+1];
                }
                L->count--;
            }
        }

        if(L->count==checker)
        {
            printf("\n\t>> Element %d not on the list. <<\n", elem);
        }
        else
        {
            printf("\n\t>> Removed all occurrences of %d. <<\n", elem);
        }
    }
}

int main()
{
    Node myList;
    LIST S = &myList;
    initList(S);
    Insert(S, 1);
    Insert(S, 2);
    Insert(S, 3);
    Insert(S, 1);
    Insert(S, 2);
    Print(S);
    RemoveAllOccurrences(S, 1);
    Print(S);
    return 0;
}