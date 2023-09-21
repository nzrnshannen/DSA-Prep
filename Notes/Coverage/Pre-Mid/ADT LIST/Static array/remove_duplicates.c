#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 5

typedef struct{
    char arr[MAX_SIZE];
    int count;
}List;

void emptyListMsg()
{
    printf("\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\tList is full!\n\n");
}

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
    return (L.count==MAX_SIZE);
}

void insertFirst(List *A, char elem)
{
    if(isFull(*A))
        fullListMsg();
    else
    {
        int x;
        for(x=A->count; x>0; x--)
        {
            A->arr[x]=A->arr[x-1];
        }
        A->arr[x] = elem;
        A->count++;
        printf("\n\tElement successfully inserted.\n");
    }
}

void deleteDuplicates(List *L)
{
    if(isEmpty(*L))
        emptyListMsg();
    else
    {
        int x, y, initialSize;
        initialSize = L->count;
        for(x=0; x<MAX_SIZE-1; x++)
        {
            for(y=L->count-1; y>x; y--)
            {
                if(L->arr[x]==L->arr[y])
                {
                    L->arr[y] = L->arr[y+1];
                    L->count--;
                }
            }
        }

        //include erasing the element that has duplicates

        // if(L->count!=initialSize)
        // {
        //     int z; 
        //     for(z=x; z<L->count-1; z++)
        //     {
        //         L->arr[z] = L->arr[z+1];
        //     }
        // }
    }
}

void displayList(List L)
{
    if(isEmpty(L))
        emptyListMsg();
    else
    {
        int x;
        printf("\n================\nList: ");
        for(x=0; x<L.count; x++)
        {
            printf("%c ",L.arr[x]);
        }

        printf("\n\n");
    }

}

int main()
{
    List myList;
    initializeList(&myList);

    insertFirst(&myList, 'B');
    insertFirst(&myList, 'A');
    insertFirst(&myList, 'C');
    insertFirst(&myList, 'E');
    insertFirst(&myList, 'B');
    deleteDuplicates(&myList);
    displayList(myList);

    return 0;
}