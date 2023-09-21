#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5
typedef struct{
    int data[MAX];
    int count;
}LIST, *PLIST;


void initList(PLIST A);
bool isEmpty(PLIST A);
bool isFull(PLIST A);
void Print(PLIST A);
void emptyListMsg();
void fullListMsg();
void Insert(PLIST A, int x);
bool checkIfPalindrome(PLIST A);
void isPalindrome(PLIST A);

void isPalindrome(PLIST A)
{
    if(isEmpty(A)) 
    {
        emptyListMsg();
    }
    else
    {
        int r = checkIfPalindrome(A);
        if(r==1)
        {
            printf("\n\n\tPalindrome");
        }
        else
        {
            printf("\n\n\tNot a Palindrome");
        }
    }
}

bool checkIfPalindrome(PLIST A)
{
    LIST temp;
    initList(&temp);
    int i;

    for(i=A->count-1; i>=0; i--)
    {
        temp.data[temp.count++] = A->data[i];
    }

    for(i=0; i<A->count && A->data[i]==temp.data[i]; i++);

    return (i==A->count);
}

void initList(PLIST A)
{
    A->count=0;
}

bool isEmpty(PLIST A)
{
    return (A->count==0);
}

bool isFull(PLIST A)
{
    return (A->count==MAX);
}

void Print(PLIST A)
{
    if(isEmpty(A))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        int i;
        for(i=0; i<A->count; i++)
        {
            printf("%d ", A->data[i]);
        }

        printf("\n");
    }
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is already full!\n\n");
}

void Insert(PLIST A, int x)
{
    if(isFull(A))
    {
        fullListMsg();
    }
    else
    {
        A->data[A->count++] = x;
    }
}

int main()
{
    LIST L;
    PLIST A = &L;
    initList(A);
    Insert(A, 1);
    Insert(A, 2);
    Insert(A, 1);
    Print(A);
    isPalindrome(A);
    printf("\n");

    return 0;
}