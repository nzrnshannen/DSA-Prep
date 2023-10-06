#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//for 1 list only
typedef struct node{
    int data;
    struct node *link;
}nodeType, *LIST;

int count = 0;
bool isEmpty(LIST L);
void Initialize(LIST *L);
void Insert(LIST *L, int elem);
void Print(LIST *L);
void makeNull(LIST *L);
void emptyListMsg();
void Delete(LIST *L, int pos);

bool isEmpty(LIST L)
{
    return (L==NULL);
}

void Initialize(LIST *L)
{
    (*L) = NULL;
    count = 0;
}

void Print(LIST *L)
{
    if(isEmpty(*L))
    {
        emptyListMsg();
    }
    else
    {
        LIST *p;
        printf("\n-----\nList: ");
        for(p = L; (*p)!=NULL; p = &(*p)->link)
        {
            printf("%d ", (*p)->data);
        }
        printf("\nNumber of nodes = %d\n", count);
    }
}

void makeNull(LIST *L)
{
    while((*L)!=NULL)
    {
        LIST temp;
        temp = *L;
        *L = (*L)->link;
        free(temp);
    }
}

void Insert(LIST *L, int elem)
{
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    newNode->data = elem;
    newNode->link = NULL;

    if(*L==NULL)
    {
        *L = newNode;
    }
    else
    {
        LIST *p;
        for(p = L; (*p)->link!=NULL; p = &(*p)->link){}

        (*p)->link=newNode;
    }

    count++;
}

void Delete(LIST *L, int pos)
{
    if(isEmpty(*L)) 
    {
        emptyListMsg();
    }
    else
    {
        if(pos > count || pos < 1)
        {
            printf("\n\t>> Please provide a proper position for deletion. <<\n");
        }
        else
        {
            LIST *trav = L;
            LIST temp;
            
            if(pos==1)
            {
                temp = (*L);
                *L = temp->link;
                free(temp);
            }
            else
            {
                int i;
                for(i=1; i<pos; i++, trav = &(*trav)->link){}

                temp = *trav;
                *trav = temp->link;
                free(temp);
            }

            count--;
            printf("\n\tDeletion successful.\n");
        }

    }
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

int main()
{
    LIST A;
    Initialize(&A);
    Insert(&A, 1);
    Insert(&A, 2);
    Insert(&A, 3);
    Print(&A);
    Delete(&A, 4);
    Print(&A);
    makeNull(&A);

    return 0;
}