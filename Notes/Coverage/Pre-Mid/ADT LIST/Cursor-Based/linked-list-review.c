/*
    OPERATIONS: 
    - insertFirst
    - display
    - clearList
    - deleteElem (first occurrence)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *link;
}nodeType, *LLIST;

void clearList(LLIST *A)
{
    LLIST temp;
    while(*A!=NULL)
    {
        temp= *A;
        *A = (*A)->link;
        free(temp);
    }
}
void deleteElem(LLIST *A, char elem)
{
    if(*A!=NULL)
    {
        LLIST temp=NULL;
        if((*A)->data==elem)
        {
            temp=*A;
            *A=(*A)->link;
            free(temp);
            printf("\n\tElement removed.\n");
        }
        else
        {
            LLIST trav;
            for(trav=*A; trav->link!=NULL && trav->link->data!=elem; trav=trav->link){}

            if(trav->link!=NULL)
            {
                temp=trav->link;
                trav->link=temp->link;
                free(temp);
                printf("\n\tElement removed.\n");
            }
            else
            {
                printf("\n\tElement not found.\n");
            }
        }
    }
    else
    {
        printf("\n\tList is empty!\n");
    }
}

void display(LLIST A)
{
    if(A!=NULL)
    {
        printf("\nList: ");
        for(; A!=NULL; A=A->link)
        {
            printf("%c ", A->data);
        }
        printf("\n");
    }
    else
    {
        printf("\n\tList is empty!\n");
    }
}

void insertFirst(LLIST *A, char elem)
{
    LLIST newNode = (LLIST)malloc(sizeof(nodeType));
    newNode->data=elem;
    newNode->link=*A;
    *A = newNode;
    printf("\n\tElement %c inserted.\n", elem);
}

int main()
{
    LLIST L;
    L=NULL;
    display(L);
    insertFirst(&L, 'a');
    insertFirst(&L, 'b');
    insertFirst(&L, 'c');
    insertFirst(&L, 'b');
    display(L);
    deleteElem(&L, 'b');
    display(L);

    clearList(&L);

    return 0;
}