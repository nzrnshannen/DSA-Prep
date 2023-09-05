/*
    Test cases:
    5 19 5 5 5 /
    19 5 5 5 5 /
    5 19 5 19 5 /
    19 19 5 5 5 /
    5 5 5 5 5 /

*/

#include<stdio.h>
#include<stdbool.h>

#define MAX 10
typedef struct{
    int arr[MAX];
    int count;
}List;

void initList(List *list)
{
    list->count=0;
}

bool isEmpty(List *list)
{
    return (list->count==0);
}

bool isFull(List *list)
{
    return (list->count==MAX);
}

void removeOccurrences(List *list, int elem)
{
    if(!(isEmpty(list)))
    {
        int cap = list->count, x, y; 
        for(x=list->count-1; x>=0; x--) //traversing starts from the end of the list towards index 0 
        {
            if(list->arr[x]==elem)
            {
                for(y=x; y<list->count; y++) //deleting as well as shifting elements starts from index 0 towards the last index
                {
                    list->arr[y] = list->arr[y+1];
                }
                list->count--;
            }
        }
        if(cap==list->count)
        {
            printf("\n\tElement specified is not in the list.\n");
        }
    }
    else
    {
        printf("\n\tEmpty list!");
    }  
}

void insert(List *list, int elem)
{
    if(!(isFull(list)))
    {
        list->arr[list->count++] = elem;
        printf("\n\t-- Element inserted. Count = %d--\n", list->count);
    }
    else
    {
        printf("\n\tList already full. Cannot insert anymore.\n");
    }
}

void display(List *list)
{
    if(isEmpty(list))
    {
        printf("\n\tEmpty list!\n");
    }
    else
    {
        printf("\n*******\nList: ");
        int x;
        for(x=0; x<list->count; x++)
        {
            printf("%d ", list->arr[x]);
        }

        printf("\n");
    }
}

int main()
{
    int inputElem;
    List myArr;
    initList(&myArr);

    insert(&myArr, 19);
    insert(&myArr, 19);
    insert(&myArr, 5);
    insert(&myArr, 5);
    insert(&myArr, 5);
    display(&myArr);

    printf("Input an element: ");
    scanf("%d", &inputElem);

    removeOccurrences(&myArr, inputElem);
    display(&myArr);
}