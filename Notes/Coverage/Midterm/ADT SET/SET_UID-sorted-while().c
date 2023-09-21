#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

typedef Node * SET;

SET Union(SET X, SET Y);
void Insert(SET *D, int x);
SET Intersection(SET X, SET Y);
SET Difference(SET X, SET Y);

void initSet(SET *D)   
{
    *D = NULL;
}

SET Difference(SET X, SET Y)
{
    SET Z;
    initSet(&Z);

    while(X!=NULL && Y!=NULL)
    {
        if(X->data < Y->data)
        {
            Insert(&Z, X->data);
            X=X->link;
        }
        else if(X->data == Y->data)
        {
            X=X->link;
            Y=Y->link;
        }
        else
        {
            Y=Y->link;
        }
    }

    if(X!=NULL)
    {
        for(; X!=NULL; X=X->link)
        {
            Insert(&Z, X->data);
        }
    }

    return Z;
}

SET Intersection(SET X, SET Y)
{
    SET Z;
    initSet(&Z);

    while(X!=NULL && Y!=NULL)
    {
        if(X->data == Y->data)
        {
            Insert(&Z, X->data);
            X=X->link;
            Y=Y->link;
        }
        else if(X->data < Y->data)
            X=X->link;
        else
            Y=Y->link;
    }

    return Z;

}

SET Union (SET X, SET Y)
{
    SET Z;
    initSet(&Z);
    int elem;

    while(X!=NULL && Y!=NULL)
    {
        if(X->data < Y->data)
        {
            elem = X->data; 
            X=X->link;
        }
        else if(Y->data < X->data)
        {
            elem = Y->data;
            Y=Y->link;
        }   
        else
        {
            elem = X->data;
            X=X->link;
            Y=Y->link;
        }

        Insert(&Z, elem);
    }
    
    if(X!=NULL)
    {
        for(; X!=NULL; X=X->link)
            Insert(&Z, X->data);
    }
    else
    {
        for(; Y!=NULL; Y=Y->link)
            Insert(&Z, Y->data);
    }

    return Z;
}

void Insert(SET *Z, int elem)
{
    SET newNode = (SET)malloc(sizeof(Node));
    if(newNode!=NULL)
    {
        newNode->data = elem;
        newNode->link= NULL;
        
        if(*Z==NULL)
        {
            *Z = newNode;
        }
        else
        {
            SET *p = Z;
            for(; *p!=NULL;p = &(*p)->link){}
            (*p) = newNode;
        }
    }
}


void Print(SET P)
{

    printf("Printing set...\n\n\t");
    for(; P!=NULL; P=P->link)
    {
        printf("%d ", P->data);
    }

    printf("\n\n");
}

int main()
{
    SET A, B, C;
    initSet(&A);
    initSet(&B);
    initSet(&C);
    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 6);
    Insert(&A, 7);
    Insert(&A, 10);

    Insert(&B, 1);
    Insert(&B, 6);
    Insert(&B, 7);
    Insert(&B, 10);

    //Union(A, B, &C);
    //Intersection(A, B, &C);
    // Difference(A, B, &C);
    // Print(A);
    // Print(B);
    // Print(C);

    C = Difference(A, B);
    Print(C);

    return 0;
    
}