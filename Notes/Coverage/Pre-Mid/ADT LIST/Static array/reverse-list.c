#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}LIST;

void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void Insert(LIST *L, int x);
void initList(LIST *L);
void Reverse(LIST *L);
//void Delete() not applicable in this program

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
        printf("\n-----\nList: ");
        int i;
        for(i=0; i<L.count; i++)
        {
            printf("%d ", L.data[i]);
        }

        printf("\n");
    }
}

void Reverse(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        int i, j, swap;
        for(i=0, j=L->count-1; i<j; i++, j--)
        {
            swap = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = swap;
        }

        printf("\n\t >> List reversed << \n");
    }

}

int main()
{
    LIST A;
    initList(&A);
    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 3);
    Insert(&A, 4);
    //Insert(&A, 5);
    Print(A);
    Reverse(&A);
    Print(A);
    return 0;
}


