/*
    Program: Remove each element's duplicate, leaving only unique elements.

    TEST CASES
    5 19 5 5 5 -> 5 19 /
    1 2 3 4 5 -> 1 2 3 4 5 /
    5 5 5 5 5 -> 5 /
    1 2 1 2 1 -> 1 2 /
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 10
typedef struct{
    int arr[MAX];
    int count;  
}List;

void printEmpty()
{
    printf("\n\tList is empty!\n");
}

void printFull()
{
    printf("\n\tList is already full!\n");
}

void initList(List *L)
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

void insert(List *L, int elem)
{
    if(!isFull(*L))
    {
        L->arr[L->count++] = elem;
        printf("\n-- Element %d inserted. --\n", elem);
    }   
    else
    {
        printFull();
    }
}

void display(List L)
{
    if(!isEmpty(L))
    {
        int x;
        printf("\n*******\nList: ");
        for(x=0; x<L.count; x++)
        {
            printf("%d ", L.arr[x]);
        }
        printf("\n");
    }
    else
    {
        printEmpty();
    }
}

void removeDuplicates(List *L)
{
    int cap = L->count;
    if(!isEmpty(*L))
    {
        int x, y;
        for(x=0; x<L->count-1; x++)
        {
            for(y=L->count-1; y>x; y--)
            {
                if(L->arr[x] == L->arr[y])
                {
                    L->arr[y] = L->arr[y+1];
                    L->count--;
                }
            }
        }
    }
    else
    {
        printEmpty();
    }

    if(cap==L->count)
    {
        printf("\n\tElements in the list are unique.\n");
    }
}
int main()
{
    List myArr;
    initList(&myArr);
    insert(&myArr, 1);
    insert(&myArr, 2);
    insert(&myArr, 1);
    insert(&myArr, 2);
    insert(&myArr, 1);

    
    display(myArr);

    removeDuplicates(&myArr);
    display(myArr);

    return 0;
}