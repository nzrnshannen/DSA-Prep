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
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Initialize(STACK *S);
void Display(STACK S);
void Copy(STACK *A, STACK B);

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

void Copy(STACK *A, STACK B)
{
    if(isEmpty(B))
    {
        emptyStackMsg();
    }
    else
    {   
        node temp;
        STACK tempStack = &temp;
        Initialize(&tempStack);
        
        if(!isEmpty(*A))
        {
            Initialize(A);
        }

        while(!isEmpty(B))
        {
            Push(&tempStack, Top(B));
            Pop(&B);
        }

        while(!isEmpty(tempStack))
        {
            Push(A, Top(tempStack));
            Push(&B, Top(tempStack));
            Pop(&tempStack);
        }

        printf("\n\t>> Successfully copied stack. <<\n\n");
    }
}

int main()
{
    node stackOne, stackTwo;
    STACK S, T;
    S = &stackOne;
    T = &stackTwo;
    Initialize(&S);
    Initialize(&T);

    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');
    Push(&S, 'D');
    Push(&S, 'E');
    
    Copy(&T, S);
    Display(S);
    Display(T);
    
    return 0;
}