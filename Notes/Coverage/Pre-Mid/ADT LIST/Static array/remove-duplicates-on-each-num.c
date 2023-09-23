#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}LIST;

void emptyListMsg();
void fullListMsg();
void initList(LIST *L);
void Insert(LIST *L, int elem);
void Print(LIST L);
bool isEmpty(LIST L);
bool isFull(LIST L);
void RemoveDuplicates(LIST *L);

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void initList(LIST *L)
{
    L->count=0;
}

void Insert(LIST *L, int elem)
{
    if(isFull(*L))
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
        printf("\n-----\nList: ");
        int i;
        for(i=0; i<L.count; i++)
        {
            printf("%d ", L.data[i]);
        }

        printf("\n");
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

void RemoveDuplicates(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, k, key;
        for(i=0; i<L->count-1; i++)
        {
            key = L->data[i];
            for(j=i+1; j<L->count; j++)
            {
                if(L->data[j]==key)
                {
                    for(k=j; k<L->count-1; k++)
                    {
                        L->data[k] = L->data[k+1];
                    }
                    L->count--;
                }
            }
        }
    }
}

int main()
{
    LIST L;
    initList(&L);
    Insert(&L, 1);
    Insert(&L, 2);
    Insert(&L, 1);
    Insert(&L, 2);
    Insert(&L, 1);
    Print(L);
    RemoveDuplicates(&L);
    Print(L);
    return 0;
}