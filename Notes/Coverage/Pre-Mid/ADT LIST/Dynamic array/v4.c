#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int *elemPtr;
    int count;
}*List;

void initializeList(List *L)
{
    *L = (List)malloc(sizeof(struct node)); //making the list
    if(*L == NULL)
    {
        printf("\nMemory allocation failure");
        exit(1);
    }

    (*L)->count=0;
    (*L)->elemPtr=NULL; //initialize pointer to NULL first
}

int main()
{
    List L;
    initializeList(&L);
}