//Array Implementation: Simple Static Array Implementation

#define MAX_SIZE 100
#include<stdio.h>

typedef struct{
    int arr[MAX_SIZE]; //static array
    int size; //current size; value depends on the number of times we use appendFunc() to append elements
}LIST;

void initialList(LIST* );
void appendFunc(LIST* , int);
int getFunc(LIST*, int);
int getSize(LIST*);

int main()
{
    LIST L;
    initialList(&L); //initialize list first to have a current size of 0

    appendFunc(&L, 1); //size = 1
    appendFunc(&L, 28); //size = 2
    appendFunc(&L, 98); //size = 3

    printf("\n===\nList size: %d\n", getSize(&L));
    printf("Element at index 0: %d\n", getFunc(&L, 0));
    printf("Element at index 1: %d\n", getFunc(&L, 1));
    printf("Element at index 2: %d\n", getFunc(&L, 2));

    return 0;
}

void initialList(LIST *A)
{
    A->size=0; //initialize current size of list at 0 first
}

void appendFunc(LIST *B, int elem)
{
    if(B->size<MAX_SIZE)
    {
        B->arr[B->size++]=elem; //append element then increment size by 1
    }
    else
    {
        printf("\nList is full. Cannot append anymore.\n");
    }

}

int getFunc(LIST *C, int index)
{
    if(index<0 || index>C->size) //not index<=0 as index at first place is 0
    {
        printf("\nIndex out of range\n");
        return -1;
    }

    return C->arr[index];
    
}

int getSize(LIST *L)
{
    return L->size;
}
