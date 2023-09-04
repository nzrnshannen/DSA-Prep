#include<stdio.h>
#include<stdlib.h>
#define INITIAL_CAPACITY 10
typedef struct{
    int *elemPtr;
    int count;
}List;


void initializeList(List *list)
{
    list->count = 0;
    list->elemPtr = (int*)malloc(sizeof(int)*INITIAL_CAPACITY);
    if(list->elemPtr == NULL)
    {
        printf("\nMemory allocation failure");
        exit(1);
    }
}


void insert()
{

}

int isEmpty()
{

}

int main()
{
    return 0;
}