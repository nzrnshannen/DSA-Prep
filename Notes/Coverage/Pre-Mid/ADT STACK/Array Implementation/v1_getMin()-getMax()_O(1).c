#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    char elem[MAX];
    int top;
    DATATYPE min_elem;
    DATATYPE max_elem;
}STACK;

void emptyStackMsg();
void fullStackMsg();
bool isFull(STACK S);
bool isEmpty(STACK S);
void Initialize(STACK *S);
void Push(STACK *S, char elem);
void Pop(STACK *S);
void Display(STACK S);
void getMin(STACK S);
void getMax(STACK S);
DATATYPE Top(STACK S);

void emptyStackMsg()
{
    printf("\n\n\tStack is empty!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}
void Initialize(STACK *S)
{
    S->top=-1;
    S->min_elem = 'z';
    S->max_elem = '\0';
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

        if(elem < S->min_elem)
            S->min_elem = elem;
        
        if(elem > S->max_elem)  
            S->max_elem = elem;
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
            Push(&S, Top(temp));
            Pop(&temp);
        }

        printf("\n");
    }
}

void getMax(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        printf("\n=========\nMax = %c", S.max_elem);
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
        printf("\n==========\nMin = %c", S.min_elem);
    }
}

int main()
{
    STACK myStack;
    Initialize(&myStack);
    Push(&myStack, 'A');
    Push(&myStack, 'B');
    Push(&myStack, 'o');
    Display(myStack);
    getMax(myStack);
    getMin(myStack);
    return 0;
}