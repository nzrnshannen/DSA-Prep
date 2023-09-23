/*
    Functions with 'int' and 'bool' return types are used to encapsulate
    specific operations and return results that can be assigned to lvalues
    (variables), allowing for cleaner and more modular code design. 
    This prevents the need for direct printf statements or modifications 
    of variables in the main function, improving code organization.

    6 main operations:
    - check if list is sorted in ascending manner
    - display sum
    - display maximum element
    - display second maximum element
    - print
    - insert at end
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int count;
}Node, *LIST;

void initList(LIST A);
void emptyListMsg();
void fullListMsg();
bool isEmpty(LIST A);
bool isFull(LIST A);
void Insert(LIST A, int elem);
void Print(LIST A);
void Max(LIST A);
int findMax(LIST A);
void Sum(LIST A);
int calculateSum(LIST A);
void SecondMax(LIST A);
int findSecondLargest(LIST A);
bool checkIfSorted(LIST A);
void isSorted(LIST A);

void initList(LIST A)
{
    A->count=0;
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

bool isEmpty(LIST A)
{
    return (A->count==0);
}

bool isFull(LIST A)
{
    return (A->count==MAX);
}

void Insert(LIST A, int elem)
{
    if(isFull(A))
    {
        fullListMsg();
    }
    else
    {
        A->data[A->count++] = elem;
        printf("\n\tElement %d inserted.\n", elem);
    }
}

void Print(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        int i;
        printf("\n-----\nList: ");
        for(i=0; i<A->count; i++)
        {
            printf("%d ", A->data[i]);
        }

        printf("\n");
    }
}

int findMax(LIST A)
{
    int i, max=-9999;
    for(i=0; i<A->count; i++)
    {
        if(A->data[i] > max)
            max = A->data[i];
    }

    return max;
}

void Max(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n===\nMax = %d\n", findMax(A));
    }
}

void Sum(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n===\nSum = %d\n", calculateSum(A));
    }
}

int calculateSum(LIST A)
{
    int i, sum=0;
    for(i=0; i<A->count; i++)
            sum+=A->data[i];

    return sum;
}

void SecondMax(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n===\nSecond Max = %d", findSecondLargest(A));
    }
}

int findSecondLargest(LIST A)
{
    int i, largest2nd=-9999;
    for(i=0; i<A->count; i++)
    {
        if(A->data[i] > largest2nd && A->data[i]!= findMax(A))
        {
            largest2nd = A->data[i];
        }
    }

    return largest2nd;
}

bool checkIfSorted(LIST A)
{
    int i;
    for(i=0; i<A->count-1 && A->data[i]<=A->data[i+1]; i++){}

    return (i==A->count-1);
}

void isSorted(LIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        if(checkIfSorted(A))
            printf("\n\n\t>> List is in sorted manner. << \n");
        else
            printf("\n\n\t>> List is in unsorted manner. <<\n");
    }
}
int main()
{
    Node myList;
    LIST S = &myList;
    initList(S); 
    Insert(S, 1);
    Insert(S, 2);
    Insert(S, 3);
    Insert(S, 4);
    Insert(S, 5);
    Print(S);
    Max(S);
    Sum(S);
    SecondMax(S);
    isSorted(S);

    return 0;
}