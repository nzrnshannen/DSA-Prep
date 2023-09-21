#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

typedef struct{
    int *elemPtr;
    int top;
}STACK, *pSTACK;

void initStack(pSTACK S);
bool isFull(pSTACK S);
bool isEmpty(pSTACK S);
void fullStackMsg();
void emptyStackMsg();
void push(pSTACK S, int x);
void pop(pSTACK S);
int top(pSTACK S);
void display(pSTACK S);
void clear(pSTACK S);

void initStack(pSTACK S)
{
    S->top=-1;
    S->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if(S->elemPtr==NULL)
    {
        printf("\n\n\tMemory allocated failed.\n\n");
        exit(1);
    }
}

bool isFull(pSTACK S)
{
    return (S->top==MAX-1);
}

bool isEmpty(pSTACK S)
{
    return (S->top==-1);
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void push(pSTACK S, int x)
{
    if(isFull(S))
    {
        fullStackMsg();
    }
    else
    {
        S->top++;
        S->elemPtr[S->top] = x;
        printf("\n\n\tSuccessfully pushed element %d.\n\n", x);
    }
}

void pop(pSTACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        int retVal = top(S);
        S->top--;
        printf("\n\n\tSuccessfully popped out element %d.\n\n", retVal);
    }
}

int top(pSTACK S)
{
    return S->elemPtr[S->top];
}

void display(pSTACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        printf("\n-----\nStack: ");
        STACK temp;
        initStack(&temp);
        while(!(isEmpty(S)))
        {
            temp.top++;
            temp.elemPtr[temp.top] = S->elemPtr[S->top--];
        }

        while(!(isEmpty(&temp)))
        {
            int retVal;
            S->top++;
            S->elemPtr[S->top] = retVal = temp.elemPtr[temp.top--];
            printf("%d ", retVal);
        }

        printf("\n");
    }
}

void clear(pSTACK S)
{
    free(S->elemPtr);
    S->elemPtr=NULL;
}

int main()
{
    STACK myStack;
    pSTACK S = &myStack;
    initStack(S);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    push(S, 7);
    pop(S);
    pop(S);

    display(S);
    pop(S);
    pop(S);
    pop(S);
    display(S);

    clear(S);
    return 0;
}