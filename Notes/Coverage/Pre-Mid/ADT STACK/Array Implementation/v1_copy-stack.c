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
void Push(STACK *S, char elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Display(STACK S);
void Initialize(STACK *S);
void Copy(STACK *A, STACK *B);

void Initialize(STACK *S)
{
    S->top=-1;
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

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
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

void Copy(STACK *A, STACK *B)
{
    if(isEmpty(*A))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        Initialize(&temp);

        while(!isEmpty(*A))
        {
            Push(&temp, Top(*A));
            Pop(A);
        }

        while(!isEmpty(temp))
        {
            Push(B, Top(temp));
            Pop(&temp);
        }
    }
}

int main()
{
    STACK stackOne;
    STACK copyStack;
    Initialize(&stackOne);
    Initialize(&copyStack);
    Push(&stackOne, 'A');
    Push(&stackOne, 'B');
    Push(&stackOne, 'C');
    Push(&stackOne, 'D');
    Push(&stackOne, 'E');
    Copy(&stackOne, &copyStack);
    Display(copyStack);
    return 0;
}