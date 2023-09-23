#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}LIST;

//void delete() not applicable in this program
void initList(LIST *L);
void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void Insert(LIST *L, int x);
void Print(LIST L);
void Rotate(LIST *L, int pos);

void initList(LIST *L)
{
    L->count=0;
}

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
    return (L.count==0);
}

bool isFull(LIST L)
{
    return (L.count==MAX);
}

void Insert(LIST *L, int x)
{
    if(isFull(*L))
    {
        fullListMsg();
    }
    else
    {
        L->data[L->count++] = x;
        printf("\n\tElement %d inserted.\n", x);
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
        {
            printf("%d ", L.data[i]);
        }
        printf("\n");
    }
}

void Rotate(LIST *L, int pos)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else if(pos>L->count)
    {
        printf("\nCannot rotate list.\n");
    }
    else
    {
        LIST A;
        initList(&A);

        int i;

        for(i=pos; i<L->count; i++)
        {
            Insert(&A, L->data[i]);
        }

        for(i=0; i<pos; i++)
        {
            Insert(&A, L->data[i]);
        }

        printf("\n\t>> List rotated. <<\n");

        for(i=0; i<L->count; i++)
        {
            L->data[i] = A.data[i];
        }
    }
}

int main()
{
    LIST L;
    initList(&L);
    Insert(&L, 1);
    Insert(&L, 2);
    Insert(&L, 3);
    Insert(&L, 4);
    Insert(&L, 5);

    Rotate(&L, 1);
    Print(L);
    return 0;
}