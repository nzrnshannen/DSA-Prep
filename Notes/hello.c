#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef struct{
    int data[MAX];
    int count;
}LIST;  

//void delete(); <-- not necessarily needed for this program
void Union(LIST X, LIST Y);
void fullListMsg();
void emptyListMsg();
bool isEmpty(LIST L);
bool isFull(LIST L);
void initList(LIST *L);
void insert(LIST *L, int x);
void print(LIST L);
void Intersection(LIST X, LIST Y); //do this

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
    printf("\n\n\tEmpty list!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void insert(LIST *L, int x)
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

void print(LIST L)
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
        printf("\n\n");
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
        LIST Z;
        initList(&Z);
        int i, j;

        for(i=0, j=0; i<X.count && j<Y.count; )
        {
            if(X.data[i] < Y.data[j])
            {
                insert(&Z, X.data[i]);
                i++;
            }
            else if(X.data[i] > Y.data[j])
            {
                insert(&Z, Y.data[j]);
                j++;
            }
            else
            {
                insert(&Z, X.data[i]);
                i++;
                j++;
            }
        }

        if(i!=X.count)
        {
            for(; i<X.count; i++)
            {
                insert(&Z, X.data[i]);
            }
        }
        else
        {
            for(; j<Y.count; j++)
            {
                insert(&Z, Y.data[j]);
            }
        }

        print(Z);   
    }
}

void Intersection (LIST X, LIST Y)
{
    if(isEmpty(X) || isEmpty(Y))
    {
        emptyListMsg();
    }
    else
    {
        LIST Z;
        initList(&Z);
        int i, j;

        for(i=0, j=0; i<X.count && j<Y.count; )
        {
            if(X.data[i] < Y.data[j])
            {
                i++;
            }
            else if(X.data[i] > Y.data[j])
            {
                j++;
            }
            else
            {
                insert(&Z, X.data[i]);
                i++, j++;
            }
        }

        print(Z);
    }
}

int main()
{
    LIST A, B;
    initList(&A);
    initList(&B);
    insert(&A, 1);
    insert(&A, 2);
    insert(&A, 15);
    insert(&B, 2);
    insert(&B, 3);
    insert(&B, 17);
    print(A);
    print(B);
    Union(A, B);
    Intersection(A, B);
    return 0;
}