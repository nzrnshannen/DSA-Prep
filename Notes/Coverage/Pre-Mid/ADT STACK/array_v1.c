/*
    STACK (ARRAY IMPLEMENTATION: VERSION 1)
    - STACK is a structure containing an array and variable top
*/

#include<stdbool.h>
#include<stdio.h>
#define MAX 5
typedef struct{
    int data[MAX];
    int top;
}STACK;

void initStack(STACK *S);
void push(STACK *S, int x);
void fullStackMsg();
void emptyStackMsg();
int top(STACK S);
bool isFull(STACK S);
bool isEmpty(STACK S);
void display(STACK S);

void initStack(STACK *S)
{
    S->top=-1;
}

void push(STACK *S, int x)
{
    if(S->top==MAX-1)
    {
        fullStackMsg();
    }
    else
    {
        S->top++;
        S->data[S->top] = x;
        printf("\n\tSuccessfully pushed element %d.\n\n", x);
    }
}

void pop(STACK *S)
{
    if(S->top==-1)
    {
        emptyStackMsg();
    }
    else
    {
        int retVal = top(*S);
        S->top--;
        printf("\n\n\tSuccessfully popped out element %d.\n\n", retVal);
    }
}

int top(STACK S)
{
    return S.data[S.top];
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        initStack(&temp);
        while(S.top!=-1)
        {
            temp.top++;
            temp.data[temp.top] = S.data[S.top--];
        }

        printf("-----\nStack: ");
        while(temp.top!=-1)
        {
            printf("%d ", top(temp));
            temp.top--;
        }

        printf("\n");
    }
}
int main()
{
    STACK S;
    initStack(&S);
    push(&S, 5);
    push(&S, 4);
    push(&S, 9);
    push(&S, 20);
    push(&S, 10);
    push(&S, 1);
    display(S);
    pop(&S);
    display(S);

    return 0;
}