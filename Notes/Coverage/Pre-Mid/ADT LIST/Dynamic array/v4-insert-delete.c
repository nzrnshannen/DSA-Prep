#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef struct node{
    char *elemPtr;
    int count;
}*List;

void initList(List* A)
{
    // (*A) = (List*)malloc(sizeof(struct node));
    (*A) = (List)malloc(sizeof(struct node));
    if(*A == NULL)
    {
        printf("\nMemory allocation failure\n");
        exit(EXIT_FAILURE);
    }

    (*A)->count = 0;
    (*A)->elemPtr = (char*)malloc(sizeof(char) * MAX);
}

bool isEmpty(List L)
{
    return (L->count==0);
}

bool isFull(List L)
{  
    return (L->count==MAX);
}

void insert(List L, char elem)
{
    int x;
    if(isFull(L))
    {
        int newCapacity = 2 * MAX;
        L->elemPtr = (char*)realloc(L->elemPtr, sizeof(char) * newCapacity);
        if(L->elemPtr==NULL)
        {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }
        printf("\n\tExpanded list capacity.\n");
    }

    for(x=L->count-1; x>=0 && elem < L->elemPtr[x]; x--)
    {
        L->elemPtr[x+1] = L->elemPtr[x];
    }
    L->elemPtr[x+1] = elem;
    L->count++;
    
    printf("\n\tElemented inserted.\n");
}

void delete(List L, char elem)
{
    if(!isEmpty(L))
    {
        int x, y;
        int initial_count = L->count; 
        for(x=0; x<L->count; x++)
        {
            if(L->elemPtr[x] == elem)
            {
                for(y=x; y<L->count; y++)
                {
                    L->elemPtr[y] = L->elemPtr[y+1];
                }

                L->count--;
            }
        }

        if(L->count==initial_count)
        {
            printf("\n\tElement doesn't exists!\n");
        }
        else
        {
            printf("\n\tElement deleted.\n");;
        }
    }
    else
    {
        printf("\n\tEmpty list!\n");
    }
}

void display(List L)
{   
    if(!isEmpty(L))
    {
        printf("\nElements: ");
        int i;
        for(i=0; i<L->count; i++)
        {
            printf("%c ", L->elemPtr[i]);
        }
    }
    else
    {
        printf("\n\tEmpty list!\n");
    }

    printf("\n");
}
int main()
{
    List L;
    initList(&L);
    insert(L, 'A');
    insert(L, 'c');
    insert(L, 'f');
    insert(L, 'g');
    insert(L, 'k');
    insert(L, 'z');
    display(L);
}