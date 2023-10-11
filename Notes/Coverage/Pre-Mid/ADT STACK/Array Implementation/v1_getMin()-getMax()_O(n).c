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
void Initialize(STACK *S);
void Print(STACK S);
void Push(STACK *S, char elem);
void Pop(STACK *S);
DATATYPE minElem(STACK S);
DATATYPE maxElem(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
DATATYPE Top(STACK S);
void getMax(STACK S);

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
            Push(&S, Top(temp));
            printf("%c ", S.elem[S.top]);
            Pop(&temp);
        }

        printf("\n");
    }
}

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}

DATATYPE maxElem(STACK S)
{
    DATATYPE max = '\0';
    while(!isEmpty(S))
    {
        if(Top(S)>max)
        {
            max=Top(S);
        }
        Pop(&S);
    }

    return max;
}

DATATYPE minElem(STACK S)
{
    DATATYPE min = 'z';
    while(!isEmpty(S))
    {
        if(Top(S)<min)
        {
            min = Top(S);
        }
        Pop(&S);
    }

    return min;
}
void getMax(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        DATATYPE max = maxElem(S);
        printf("\n***\nMax = %c\n", max);
    }
}

void getMin(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        DATATYPE min = minElem(S);
        printf("\n***\nMin = %c\n", min);
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
    Push(&myStack, 'f');
    Print(myStack);
    getMax(myStack);
    getMin(myStack);
    return 0;
}