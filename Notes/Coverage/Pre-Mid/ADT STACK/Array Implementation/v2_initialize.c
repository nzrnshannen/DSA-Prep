#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE elem[MAX];
    int top;
}node, *STACK;

void Initialize(STACK *S);
void emptyStackMsg();
void fullStackMsg();
DATATYPE Top(STACK S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
void Display(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);

void Initialize(STACK *S)
{
    (*S)->top = -1;
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

DATATYPE Top(STACK S)
{
    return S->elem[S->top];
}

void Push(STACK *S, DATATYPE elem)
{
    if(isFull(*S))
    {
        fullStackMsg();
    }
    else
    {
        (*S)->top++;
        (*S)->elem[(*S)->top] = elem;
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
        (*S)->top--;
    }
}

bool isEmpty(STACK S)
{
    return (S->top==-1);
}


bool isFull(STACK S)
{
    return (S->top==MAX-1);
}

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        node temp;
        STACK t = &temp;
        Initialize(&t);
        
        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&t, Top(S));
            Pop(&S);
        }

        while(!isEmpty(&temp))
        {
            printf("%c ", Top(t));
            Push(&S, Top(t));
            Pop(&t);
        }

        printf("\n\n");
    }
}

int main()
{
    node myStack;
    STACK P = &myStack;
    Initialize(&P);
    Push(&P, 'A');
    Push(&P, 'B');
    Push(&P, 'C');
    Push(&P, 'D');
    Push(&P, 'E');
    Display(P);
    Display(P);

    return 0;
}