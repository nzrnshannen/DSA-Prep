#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char elem;
    struct node *link;
}nodeType, *LIST;

bool isEmpty(LIST L);
void emptyListMsg();
void Initialize(LIST *L);
void Print(LIST *L);
void Insert(LIST *L, char elem);
void Reverse(LIST *L);
void errorMsg();
void makeNull(LIST *L);

bool isEmpty(LIST L)
{
    return (L==NULL);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void errorMsg()
{
    printf("\n\nMemory allocation failure.\n\n");
    exit(1);
}

void Initialize(LIST *L)
{
    *L=NULL;
}

void Print(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        LIST *p;
        for(p=L; (*p)!=NULL; p=&(*p)->link)
            printf("%c ", (*p)->elem);
        
        printf("\n");
    }
}

void Insert(LIST *L, char elem)
{
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode==NULL)
    {
        errorMsg();
    }
    else
    {
        newNode->elem=elem;
        newNode->link=NULL;

        if(isEmpty(*L))
        {
            *L = newNode;
        }
        else
        {
            LIST *trav;
            for(trav=L; *trav!=NULL; trav=&(*trav)->link){}

            *trav = newNode;
        }
    }
}

void makeNull(LIST *L)
{
    LIST temp;

    while(*L!=NULL)
    {
        temp = *L;
        *L = (*L)->link;
        free(temp);
    }

    temp = NULL;
    printf("\n\n\t>> Memory freed. <<\n\n");
}

void Reverse(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        LIST prev, curr, next;
        
        for(prev=NULL, curr=next=*L; curr!=NULL; prev=curr, curr=next)
        {
            next=next->link;
            curr->link=prev;
        }

        *L = prev;

        printf("\n\n\t>> List reversed. <<\n\n");
    }
}

int main()
{
    LIST p1;
    Initialize(&p1);
    Insert(&p1, 'A');
    Insert(&p1, 'B');
    Insert(&p1, 'C');
    Print(&p1);
    Reverse(&p1);
    Print(&p1);
    makeNull(&p1);
    return 0;
}