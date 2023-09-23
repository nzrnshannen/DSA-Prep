//for sorted

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
void Union(LIST X, LIST Y);
void Intersection (LIST X, LIST Y);

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

void Union(LIST X, LIST Y)
{
    if(isEmpty(X) || isEmpty(Y))
    {
        emptyListMsg();
    }
    else
    {
        Node listThree;
        LIST C = &listThree; //creating LIST which is a pointer to a structure (maintaning array v2's definition)
        initList(C);
        int i, j;

        for(i=0, j=0; i<X->count && j<Y->count; )
        {
            if(X->data[i] < Y->data[j])
            {
                Insert(C, X->data[i]);
                i++;
            }
            else if(Y->data[j] < X->data[i])
            {
                Insert(C, Y->data[j]);
                j++;
            }
            else
            {
                Insert(C, X->data[i]);
                i++, j++;
            }
        }

        if(i!=X->count)
        {
            for(; i<X->count; i++)
                Insert(C, X->data[i]);
        }
        else
        {
            for(; j<Y->count; j++)
                Insert(C, Y->data[j]);
        }

        printf("\n*****\nUNION");
        Print(C);
    }
}

void Intersection(LIST X,LIST Y)
{
    if(isEmpty(X) || isEmpty(Y))
    {
        emptyListMsg();
    }
    else
    {
        int i, j;
        Node listFour;
        LIST Z = &listFour;
        initList(Z);
        for(i=0, j=0; i<X->count && j<Y->count; )
        {
            if(X->data[i] < Y->data[j])
                i++;
            else  if(Y->data[j] < X->data[i])
                j++;
            else
            {
                Insert(Z, X->data[i]);
                i++, j++;
            }
        }

        printf("\n*****\nINTERSECTION");
        Print(Z);
    }
}

int main()
{
    Node listOne, listTwo;
    LIST A = &listOne;
    LIST B = &listTwo;

    initList(A);
    initList(B);

    Insert(A, 1);
    Insert(A, 2);
    Insert(A, 3);
    Insert(A, 8);

    Insert(B, 1);
    Insert(B, 6);
    Insert(B, 8);

    Print(A);
    Print(B);
    Union(A, B);
    Intersection(A, B);

    return 0;
}