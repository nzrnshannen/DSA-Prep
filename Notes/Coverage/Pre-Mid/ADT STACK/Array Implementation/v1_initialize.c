#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    char elem[MAX];
    int top;
}STACK;

void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(STACK S);
void Push(STACK *S, char elem);
void Print(STACK S);
void Initialize(STACK *S);
char Top(STACK S);
void Pop(STACK *S);

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

char Top(STACK S)
{
    return (S.elem[S.top]);
}

void Push(STACK *S, char elem)
{
    if(isFull(*S))
    {
        fullStackMsg();
    }
    else
    {
        S->top++;
        S->elem[S->top] = elem;
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

void Initialize(STACK *S)
{
    S->top=-1;
}

void Print(STACK S)
{
    if (isEmpty(S))
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
            Push(&S, Top(temp));
            printf("%c ", Top(temp));
            Pop(&temp);
        }

        printf("\n");
    }
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
    // Push(&myStack, 'F'); stack overflow
    Print(myStack);
    return 0;
}