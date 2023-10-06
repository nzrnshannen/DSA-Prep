#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char elem;
    struct node *link;
}nodeType, *LIST;

void makeNull(LIST *L);
void initialize(LIST *L);
void Print(LIST L);
void Insert(LIST *L, char elem);
void DeleteOccurrences(LIST *L, char elem);
bool isEmpty(LIST L);
void emptyListMsg();
void errorMsg();


void errorMsg()
{
    printf("\nMemory allocation failure.");
    exit(1);
}

void emptyListMsg()
{
   printf("\n\n\tList is empty!\n\n");
}

bool isEmpty(LIST L)
{
    return (L==NULL);
}

void initialize(LIST *L)
{
    (*L)=NULL;
}

void Insert(LIST *L, char elem)
{
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode==NULL)
        errorMsg();

    newNode->elem = elem;
    newNode->link= NULL;

    if(*L==NULL)
    {
        *L = newNode;
    }
    else
    {
        LIST *p;
        for(p=L; (*p)!=NULL; p=&(*p)->link){}
        *p = newNode;
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
        LIST trav;
        for(trav=L; trav!=NULL; trav=trav->link)
        {
            printf("%c ", trav->elem);
        }

        printf("\n");
    }
}

void DeleteOccurrences(LIST *L, char elem)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        LIST *p;

        for(p=L; (*p)!=NULL; )
        {
            if((*p)->elem==elem)
            {
                LIST temp;
                if(p==L)
                {
                    temp=*L;
                    *L = (*L)->link;
                    free(temp);
                    p = L;
                }
                else
                {
                    temp = *p;
                    *p = temp->link;
                    free(temp);
                }   
            }
            else
            {
                p=&(*p)->link;
            }
        }
    }
}
void makeNull(LIST *L)
{
    while((*L)!=NULL)
    {
        LIST temp = *L;
        *L = (*L)->link;
        free(temp);
    }

    *L=NULL;

    printf("\n\tMemory freed.\n");
}


int main()
{
    LIST L1;
    initialize(&L1);
    Insert(&L1, 'B');
    Insert(&L1, 'A');
    Insert(&L1, 'B');
    Insert(&L1, 'A');
    Insert(&L1, 'A');
    Insert(&L1, 'B');
    Print(L1);
    DeleteOccurrences(&L1, 'A');
    Print(L1);
    makeNull(&L1);
    return 0;
}