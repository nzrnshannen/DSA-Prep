#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5
typedef struct{
    int data[MAX];
    int count;
}LIST;

void initList(LIST *L);
bool isEmpty(LIST L);
bool isFull(LIST L);
void printEmptyList();
void printFullList();
void Print(LIST L);
bool checkIfPalindrome (LIST L);
void isPalindrome(LIST L);


void insert(LIST *L, int elem)
{
    if(isFull(*L))
    {
        printFullList();
    }
    else
    {
        L->data[L->count++] = elem;
    }
}

bool checkIfPalindrome(LIST L)
{
    LIST A;
    initList(&A);
    int i;

    for(i=L.count-1; i>=0; i--)
    {
        A.data[A.count++] = L.data[i];
    }

    for(i=0; i<L.count && L.data[i]==A.data[i]; i++){}

    return (i==L.count);
}


void isPalindrome(LIST L)
{
    int r = checkIfPalindrome(L);
    if(r==1)
    {
        printf("\n\tPalindrome");
    }
    else
    {
        printf("\n\tNot a Palindrome");
    }
}

void initList(LIST *L)
{ 
    L->count=0;
}

bool isEmpty(LIST L)
{
    return (L.count==0);
}

bool isFull(LIST L)
{
    return (L.count==MAX);
}

void printEmptyList()
{
    printf("\n\n\tEmpty list!\n\n");
}

void printFullList()
{
    printf("\n\n\tList is full!\n\n");
}


void Print(LIST L)
{
    if(isEmpty(L))
    {
        printEmptyList();
    }
    else
    {
        int i;
        printf("\n-----\nList: ");
        for(i=0; i<L.count; i++)
        {
            printf("%d ", L.data[i]);
        }

        printf("\n\n");
    }
}

int main()
{
    LIST L;
    initList(&L);
    insert(&L, 1);
    insert(&L, 2);
    insert(&L, 3);
    Print(L);
    isPalindrome(L);

    return 0;

}