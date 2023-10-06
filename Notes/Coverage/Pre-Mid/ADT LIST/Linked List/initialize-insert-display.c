#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}nodeType, *LIST;

void Initialize(LIST *L);
bool isEmpty(LIST L);
void Print(LIST L);
void emptyListMsg();

void Initialize(LIST *L)
{
    (*L)=NULL;
}

bool isEmpty(LIST L)
{
    return (L==NULL);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
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
        for(; L!=NULL; L=L->link)
            printf("%d ", L->data);
        
        printf("\n");
    }
}

void Insert(LIST *L, int elem)
{
    LIST newNode =(LIST )malloc(sizeof(nodeType));
    newNode->data = elem;
    newNode->link = NULL;

    if(isEmpty(*L))
    {
        *L = newNode;
    }
    else
    {
        //using pointer to pointer to node
        LIST *temp;
        for(temp = L; (*temp)->link!=NULL; temp=&(*temp)->link){}
        (*temp)->link = newNode;
    }
}

void makeNull(LIST *L)
{
    while(*L!=NULL)
    {
        LIST temp = *L;
        *L = (*L)->link;
        free(temp);
    }

    printf("\nList cleared.\n");
}

int main()
{
    LIST L;
    Initialize(&L);
    Insert(&L, 1);
    Insert(&L, 2);
    Print(L);
    makeNull(&L);
    return 0;
}