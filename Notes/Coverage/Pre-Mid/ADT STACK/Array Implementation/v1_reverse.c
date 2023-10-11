#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    char elem[MAX];
    int top;
}STACK;

void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(STACK S);
void Initialize(STACK *S);
void Push(STACK *S, char elem);
void Pop(STACK *S);
void Display(STACK S);
void Reverse(STACK *S);
DATATYPE Top(STACK S);
STACK newForm(STACK S);

void emptyStackMsg()
{
    printf("\n\n\tStack is empty!\n\n");
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

void Initialize(STACK *S)
{
    S->top=-1;
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

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&temp, Top(S));
            Pop(&S);
        }

        while(!isEmpty(temp))
        {
            printf("%c ", Top(temp));
            Pop(&temp);
        }

        printf("\n");
    }
}

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}

void Reverse(STACK *S)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        *S = newForm(*S);
        printf("\n\t>> Stack reversed. <<\n");
    }
}

STACK newForm(STACK S)
{
    STACK temp;
    Initialize(&temp);
    while(!isEmpty(S))
    {
        Push(&temp, Top(S));
        Pop(&S);
    }

    return temp;
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
    Display(myStack);
    Reverse(&myStack);
    Display(myStack);
    return 0;
}