#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char elem;
    struct node *link;
}nodeType, *LIST;

void deleteFirstOccurrence(LIST *D, char elem)
{
    LIST *p;
    for(p=D; (*p)!=NULL && (*p)->elem!=elem; p = &(*p)->link){}

    printf("test: %c \n", (*p)->elem);
    if((*p)!=NULL) //accessing elem: (*p)->elem; accessing link: (*p) as p is already pointing to the link part of the node
    {
        LIST temp;
        temp = (*p);
        (*p)= temp->link;

        free(temp);
        printf("\n\tElement %c successfully deleted.\n\n", elem);
    }
    else
    {
        printf("\n\tElement %c can't be found on the list.\n\n", elem);
    }
}

void clearList(LIST *C) //should be pass by address
{
    LIST temp;
    while(*C!=NULL)
    {
        temp = *C;
        C = &(*C)->link;
    
        free(temp);
    }

    printf("\n\tList cleared.\n");
    

}


void insertFirst(LIST *Head, char elem)
{
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    newNode->elem = elem;
    newNode->link = *Head;
    *Head = newNode;

    printf("\n\tElement inserted.\n\n");
}

void displayList(LIST *A)
{
    LIST *p = A;
    printf("\nList: ");

    for(; (*p)!=NULL; p = &(*p)->link)
    {
        printf("%c ", (*p)->elem);
    }

    printf("\n");
}
int main()
{
    LIST L;
    L=NULL;
    insertFirst(&L, 'A');
    insertFirst(&L, 'B');
    insertFirst(&L, 'C');
    insertFirst(&L, 'A');
    displayList(&L);

    deleteFirstOccurrence(&L, 'B');
    displayList(&L);
    clearList(&L);

    if(L==NULL)
    {
        printf("\n-----\nList is successfully cleared!");
    }

    return 0;
}