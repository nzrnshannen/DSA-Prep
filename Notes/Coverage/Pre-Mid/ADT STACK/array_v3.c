#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5

typedef struct{
    int *elemPtr; //pointer to an integer array
    int top;
}STACK;

void initStack(STACK *S);
bool isFull(STACK S);
bool isEmpty(STACK S);
void fullStackMsg();
void emptyStackMsg();
void pop(STACK *S);
void push(STACK *S, int x);
void display(STACK S);
int top(STACK S);
void clear(STACK *S);

void initStack(STACK *S)
{
    S->top=-1;
    S->elemPtr = (int*)malloc(sizeof(int) * MAX);
    if(S->elemPtr==NULL)
    {
        printf("\n\n\tMemory allocation failed.\n\n");
        exit(1);
    }
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

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

void pop(STACK *S)
{
    if(isEmpty(*S))
    {   
        emptyStackMsg();
    }
    else
    {
        int retval = top(*S);
        S->top--;
        printf("\n\n\tSuccessfully popped out element %d.\n\n", retval);
    }
}

void push(STACK *S, int x)
{
    if(isFull(*S))
    {
        fullStackMsg();
    }
    else
    {
        S->top++;
        S->elemPtr[S->top] = x;
        printf("\n\n\tSuccessfully inserted element %d.\n\n", x);
    }
}

void clear(STACK *S)
{
    free(S->elemPtr);
}
void display(STACK S)
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
            temp.elemPtr[temp.top] = S.elemPtr[S.top--];
        }

        while(!(isEmpty(temp)))
        {
            S.top++;
            int retval = top(temp);
            S.elemPtr[S.top] = temp.elemPtr[temp.top--];
            printf("%d ", retval);
        }
    }
}   

int top(STACK S)
{
    return S.elemPtr[S.top];
}


int main()
{
    STACK myStack;
    initStack(&myStack);
    push(&myStack, 1);
    push(&myStack, 2);
    push(&myStack, 3);
    push(&myStack, 4);
    push(&myStack, 5);
    push(&myStack, 6);
    pop(&myStack);
    pop(&myStack);

    printf("\nTop = %d\n", top(myStack));
    display(myStack);

    clear(&myStack);

    return 0;
}