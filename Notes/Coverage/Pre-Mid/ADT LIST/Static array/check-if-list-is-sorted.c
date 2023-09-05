/*
    CHECK IF LIST IS SORTED (ASCENDING)

    Notes: 
    - When you need to modify the members of the list, it is a must to pass it by address (&myArr)
    - You can choose NOT to pass the address of the list like in terms of displaying, checking if value of list 
        is empty or full, read-only operations
*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 20
typedef struct{
    int arr[MAX];
    int count;
}List;

void initializeList(List *L)
{
    L->count=0;
}

bool isEmpty(List L)
{
    return (L.count==0);
}

bool isFull(List L)
{
    return (L.count==MAX);
}

bool isSorted(List L)
{
    int x=0;
    if(!(isEmpty(L)))
    {
        for(; x<L.count-1 && L.arr[x]<=L.arr[x+1]; x++){}
        return (x==L.count-1);
    }
    else
    {
        return false;
    }
}

void insert(List *L, int elem)
{
    if(isFull(*L))
    {
        printf("\n\tList is full. Cannot insert.\n");
        fflush(stdin);
    }
    else
    {
        L->arr[L->count++] = elem;
        printf("\n\tElement %d inserted.\n", elem);
    }
}

void display(List L)
{
    if(isEmpty(L))
    {
        printf("\n\tEmpty list!\n");
    }
    else
    {
        int x;
        printf("===========\nList: ");
        for(x=0; x<L.count; x++)
        {
            printf("%d ", L.arr[x]);
        }

        printf("\n");
    }
}

int main()
{
    List myList;
    initializeList(&myList);

    insert(&myList, 1);
    insert(&myList, 2);
    insert(&myList, 2);
    insert(&myList, 5);

    printf("\n");
    display(myList);

    if(isSorted(myList))
        printf("\n---\nList is sorted in ascending order.");
    else 
        printf("\n---\nList is not sorted in ascending order/might be empty.");

    return 0;
}