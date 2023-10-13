#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char DATATYPE;
typedef struct node{
    DATATYPE elem;
    struct node *link;
}nodeType, *STACK;

void emptyStackMsg();
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Print(STACK S);
bool isEmpty(STACK S);
void makeNull(STACK *S);
void Copy(STACK A, STACK *B);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void Initialize(STACK *S)
{
    *S = NULL;
}

void Push(STACK *S, DATATYPE elem)
{
    STACK newNode = (STACK)malloc(sizeof(nodeType));
    if(newNode==NULL)
    {
        printf("\nMemory allocation failure!\n\n");
        exit(1);
    }

    newNode->elem = elem;
    newNode->link = *S;
    *S = newNode;
}

void Pop(STACK *S)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

DATATYPE Top(STACK S)
{
    return S->elem;
}

void Print(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        Initialize(&temp);

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&temp, Top(S));
            Pop(&S);
        }

        while(!isEmpty(temp))
        {
            printf("%c ", Top(temp));
            Push(&S, Top(temp));
            Pop(&temp);
        }

        printf("\n");
    }
}

bool isEmpty(STACK S)
{
    return (S==NULL);
}

void makeNull(STACK *S)
{
    while(!isEmpty(*S))
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }

    printf("\n\t>> Memory freed. <<\n\n");
}

void Copy(STACK A, STACK *B)
{
    if(isEmpty(A))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        Initialize(&temp);
        Initialize(B);

        while(!isEmpty(A))
        {
            Push(&temp, Top(A));
            Pop(&A);
        }

        while(!isEmpty(temp))
        {
            Push(&A, Top(temp));
            Push(B, Top(temp));
            Pop(&temp);
        }

        printf("\n\t>> Successfully copied stack. <<\n\n");
    }
}

int main()
{
    STACK myStack, exampleStack;
    Initialize(&myStack);
    Push(&myStack, 'A');
    Push(&myStack, 'B');
    Push(&myStack, 'C');
    Push(&myStack, 'D');
    Push(&myStack, 'E');

    Print(myStack);
    Print(myStack);

    Copy(myStack, &exampleStack);

    Print(exampleStack);
    makeNull(&myStack);
    return 0;
}   