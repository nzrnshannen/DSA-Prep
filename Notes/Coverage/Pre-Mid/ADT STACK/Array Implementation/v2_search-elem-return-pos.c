#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE elem[MAX];
    int top;
}node, *STACK;

void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(STACK S);
void Initialize(STACK *S);
void Display(STACK S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
int posReturn(STACK S, DATATYPE elem);

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
    return (S->top==-1);
}

bool isFull(STACK S)
{
    return (S->top==MAX-1);
}

void Initialize(STACK *S)
{
    (*S)->top=-1;
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
        STACK tempPtr = &temp;
        Initialize(&tempPtr);

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&tempPtr, Top(S));
            Pop(&S);
        }

        while(!isEmpty(tempPtr))
        {
            printf("%c ", Top(tempPtr));
            Push(&S, Top(tempPtr));
            Pop(&tempPtr);
        }
        printf("\n\n");
    }
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

DATATYPE Top(STACK S)
{
    return S->elem[S->top];
}

int posReturn(STACK S, DATATYPE elem)
{
    int pos;
    node temp;
    STACK tempPtr = &temp;
    Initialize(&tempPtr); 

    while(!isEmpty(S))
    {
        Push(&tempPtr, Top(S));
        Pop(&S);
    }

    for(pos=1; !isEmpty(tempPtr) && Top(tempPtr)!= elem; Push(&S, Top(tempPtr)), Pop(&tempPtr), pos++){}

    if(!isEmpty(tempPtr) && pos<=MAX)
    {
        for(; !(isEmpty(tempPtr)); Push(&S, Top(tempPtr)), Pop(&tempPtr)){}
    }
    
    return pos;
}
void Search(STACK S, DATATYPE elem)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        int retval = posReturn(S, elem);
        if(retval<=MAX)
        {
            printf("\n\t>> Element %c at position %d. <<\n\n", elem, retval);
        }
        else
        {
            printf("\n\t>> Element %c does not exist! <<\n\n", elem);
        }
    }
}

int main()
{
    node myStack;
    STACK S = &myStack;
    Initialize(&S);
    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');
    Push(&S, 'D');
    Push(&S, 'E');

    Display(S);
    Search(S, 'E');
    Display(S);
    return 0;
}