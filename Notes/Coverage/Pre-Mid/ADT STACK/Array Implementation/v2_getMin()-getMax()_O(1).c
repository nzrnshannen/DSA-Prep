#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE elem[MAX];
    int top;
    DATATYPE minElem;
    DATATYPE maxElem;
}node, *STACK;

void emptyStackMsg();
void fullStackMsg();
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Display(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void getMax(STACK S);
void getMin(STACK S);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

void Initialize(STACK *S)
{
    (*S)->top=-1;
    (*S)->minElem = 'z';
    (*S)->maxElem = '\0';
}

void Push(STACK *S, DATATYPE elem)
{
    if(isFull(*S))
    {
        fullStackMsg();
    }
    else
    {
        if(elem > (*S)->maxElem)
        {
            (*S)->maxElem = elem;
        }

        if(elem < (*S)->minElem)
        {
            (*S)->minElem = elem;
        }

        (*S)->top++;
        (*S)->elem[(*S)->top] = elem;
    }
}

bool isFull(STACK S)
{
    return (S->top==MAX-1);
}

bool isEmpty(STACK S)
{
    return (S->top==-1);
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

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        node tempStack;
        STACK T;
        T = &tempStack;
        Initialize(&T);

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&T, Top(S));
            Pop(&S);
        }

        while(!isEmpty(T))
        {
            printf("%c ", Top(T));
            Push(&S, Top(T));
            Pop(&T);
        }

        printf("\n\n");
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
        printf("\n=====\nMax = %c\n", S->maxElem);
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
        printf("\n=====\nMin = %c\n", S->minElem);
    }
}

int main()
{   
    node stackOne, stackTwo;
    STACK stackA = &stackOne;
    STACK stackB = &stackTwo;

    Initialize(&stackA);
    Initialize(&stackB);

    Push(&stackA, 'A');
    Push(&stackA, 'B');
    Push(&stackA, 'C');
    Push(&stackA, 'D');
    Push(&stackA, 'E');

    Display(stackA);

    Push(&stackB, 'F');
    Push(&stackB, 'G');
    Push(&stackB, 'H');
    Push(&stackB, 'I');
    Push(&stackB, 'J');

    Display(stackB);

    getMin(stackA);
    getMax(stackA);

    getMin(stackB);
    getMax(stackB);

    return 0;
}

