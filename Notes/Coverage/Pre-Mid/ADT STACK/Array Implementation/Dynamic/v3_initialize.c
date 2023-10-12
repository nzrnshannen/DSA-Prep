#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE *elemPtr;
    int top;
}STACK;

void Initialize(STACK *S);
void Display(STACK S);
void Pop(STACK *S);
void Push(STACK *S, DATATYPE elem);
DATATYPE Top(STACK S);
void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(STACK S);
void errorMsg();
void makeNull(STACK *S);

void errorMsg()
{
    printf("\n\nMemory allocation failure!\n\n");
    exit(1);
}

void Initialize(STACK *S)
{
    S->top=-1;
    S->elemPtr = (DATATYPE *)malloc(sizeof(DATATYPE) * MAX);
    if(S->elemPtr==NULL)
    {
        errorMsg();
    }
}

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        Initialize(&temp);
        DATATYPE ch;

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&temp, Top(S));
            Pop(&S);
        }

        while(!isEmpty(temp))
        {
            ch = Top(temp);
            printf("%c ", ch);
            Push(&S, ch);
            Pop(&temp);
        }

        printf("\n\n");
    }
}

void Pop(STACK *S)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        S->top--;
    }
}

void Push(STACK *S, DATATYPE elem)
{
    if(isFull(*S))
    {
        int newMax = MAX * 2;
        S->elemPtr = (DATATYPE *)realloc(S->elemPtr, sizeof(DATATYPE) * newMax);
        if(S->elemPtr==NULL)
        {
            errorMsg();
        }

        S->top++;
        S->elemPtr[S->top] = elem;
    }
    else
    {
        S->top++;
        S->elemPtr[S->top] = elem;
    }
   
}

DATATYPE Top(STACK S)
{
    return S.elemPtr[S.top];
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

void makeNull(STACK *S)
{
    S->top = -1;
    free(S->elemPtr);
}

int main()
{
    STACK myStack;
    Initialize(&myStack);
    Push(&myStack, 'A');
    Push(&myStack, 'B');
    Push(&myStack, 'C');
    Push(&myStack, 'D');
    Push(&myStack, 'E');
    Push(&myStack, 'F');
    Push(&myStack, 'G');

    Display(myStack);

    makeNull(&myStack);
    return 0;
}