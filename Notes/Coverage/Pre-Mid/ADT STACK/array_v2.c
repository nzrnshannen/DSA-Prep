#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    int data[MAX];
    int top;
}STACK, *pSTACK;

void initStack(pSTACK S);
bool isFull(pSTACK S);
bool isEmpty(pSTACK S);
void fullStackMsg();
void emptyStackMsg();
void display(pSTACK S);
void pop(pSTACK S);
void push(pSTACK S, int x);
int top(pSTACK S);

void initStack(pSTACK S)
{
    S->top=-1;
}

bool isFull(pSTACK S)
{
    return (S->top==MAX-1);
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

bool isEmpty(pSTACK S)
{
    return (S->top==-1);
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
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
        int retVal;
        initStack(&temp);
        while(!(isEmpty(S)))
        {
            temp.top++;
            temp.data[temp.top] = S->data[S->top]; 
            S->top--;
        } 

        while(!(isEmpty(&temp)))  
        {
            S->top++;
            S->data[S->top] = retVal = top(&temp);
            printf("%d ", retVal);
            temp.top--;
        }

        printf("\n");
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

void push(pSTACK S, int x)
{
    if(isFull(S))
    {
        fullStackMsg();
    }
    else
    {
        S->top++;
        S->data[S->top] = x;
        printf("\n\n\tSuccessfully pushed element %d.\n\n", x);
    }
}

int top(pSTACK S)
{
    return S->data[S->top];
}

int main()
{
    STACK myStack;
    pSTACK S= &myStack;
    initStack(S);
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    pop(S);
    pop(S);
    pop(S);

    

    display(S);



    while(i<10)
    {
        i++;
        if(i==5)
        {
            break;
        }
    }


    
    for(i=1; i<10 && i!=5; i++){}




    return 0;
}
