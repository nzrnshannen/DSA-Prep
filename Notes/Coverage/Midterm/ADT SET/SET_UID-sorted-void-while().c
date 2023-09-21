#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}Node;

typedef Node * SET;

void Union(SET X, SET Y, SET *Z);
void Insert(SET *D, int x);


void initSet(SET *D)   
{
    *D = NULL;
}

void Difference(SET X, SET Y, SET *Z)
{
    while(X!=NULL && Y!=NULL)
    {
        if(X->data < Y->data)
        {
            Insert(Z, X->data);
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
            Insert(Z, X->data);
        }
    }
}

void Intersection(SET X, SET Y, SET *Z)
{
    SET t1, t2;
    t1=X;
    t2=Y;

    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data == t2->data)
        {
            Insert(Z, t1->data);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->data < t2->data)
            t1=t1->link;
        else
            t2=t2->link;
    }

}

void Union (SET X, SET Y, SET *Z)
{
    SET t1, t2;
    t1=X;
    t2=Y;
    int elem;

    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data < t2->data)
        {
            elem = t1->data; 
            t1=t1->link;
        }
        else if(t2->data < t1->data)
        {
            elem = t2->data;
            t2=t2->link;
        }   
        else
        {
            elem = t1->data;
            t1=t1->link;
            t2=t2->link;
        }

        Insert(Z, elem);
    }
    
    if(t1!=NULL)
    {
        for(; t1!=NULL; t1=t1->link)
            Insert(Z, t1->data);
    }
    else
    {
        for(; t2!=NULL; t2=t2->link)
            Insert(Z, t2->data);
    }
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
    Difference(A, B, &C);
    Print(A);
    Print(B);
    Print(C);

    return 0;
    
}