//delete operation not included in here

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int count;
}LIST;



void initList(LIST *L);
bool isEmpty(LIST L);
bool isFull(LIST L);
void emptyListMsg();
void fullListMsg();
void print(LIST L);
void insert(LIST *L, int elem);
void sort(LIST *L);
void merge(LIST A, LIST B);


void initList(LIST *L)
{
    L->count=0;
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

void print(LIST L)
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

        printf("\n\n");
    }
}

void insert(LIST *L, int elem)
{
    if(isFull(*L))
    {
        fullListMsg();
    }
    else
    {
        L->data[L->count++] = elem;
        printf("\nElement %d inserted.\n", elem);
    }
}


void sort(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        int x, y;
        for(x=0; x<L->count; x++)
        {
            for(y=0; y<L->count-1; y++)
            {
                if(L->data[y+1] < L->data[y])
                {
                    int swap;
                    swap = L->data[y];
                    L->data[y] = L->data[y+1];
                    L->data[y+1] = swap;
                }
            }
        }
    }
}

void merge(LIST A, LIST B)
{
    if((A.count + B.count) > MAX)
    {
        printf("\n\n\tCannot merge lists! Insufficient Space.\n\n");
    }
    else
    {
        int i;
        LIST C;
        initList(&C);
        for(i=0; i<A.count; i++)
        {
            insert(&C, A.data[i]);
        }

        for(i=0; i<B.count; i++)
        {
            insert(&C, B.data[i]);
        }

        sort(&C);
        print(C);
    }
}

int main()
{
    LIST L1, L2; 

    initList(&L1);
    initList(&L2);
    insert(&L1, 1);
    insert(&L1, 2);
    insert(&L1, 0);
    insert(&L1, 10);
    insert(&L1, 9);
    sort(&L1);

    insert(&L2, 5);
    insert(&L2, 6);
    insert(&L2, -2);
    insert(&L2, 88);
    insert(&L2, -1);
    insert(&L2, 100);

    sort(&L2);

    merge(L1, L2);

    return 0;
}