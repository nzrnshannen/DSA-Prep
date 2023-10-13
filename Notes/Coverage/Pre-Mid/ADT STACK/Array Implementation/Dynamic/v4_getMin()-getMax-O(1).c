#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE *elemPtr;
    int top;
    DATATYPE minElem;
    DATATYPE maxElem;
}node,*STACK;


void emptyStackMsg();
void errorMsg();
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Display(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void makeNull(STACK *S);
void getMin(STACK S);
void getMax(STACK S);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void errorMsg()
{
    printf("\n\n\tMemory allocation failure!\n\n");
}

void Initialize(STACK *S)
{
    (*S)->top=-1;
    (*S)->elemPtr = (DATATYPE*)malloc(sizeof(DATATYPE) * MAX);
    if((*S)->elemPtr == NULL)
    {
        errorMsg();
    }

    (*S)->minElem = 'z';
    (*S)->maxElem = '\0';
}

void Push(STACK *S, DATATYPE elem)
{
    if(isEmpty(*S))
    {
        int newMax = ((*S)->top) + 1 * 2;
        (*S)->elemPtr = (DATATYPE*)realloc((*S)->elemPtr, sizeof(DATATYPE) * newMax);
        if((*S)->elemPtr==NULL)
        {
            errorMsg();
        }

        (*S)->top++;
        (*S)->elemPtr[(*S)->top] = elem;
    }
    else
    {
        (*S)->top++;
        (*S)->elemPtr[(*S)->top] = elem;
    }

    if(elem > (*S)->maxElem)
        (*S)->maxElem = elem;
    
    if(elem < (*S)->minElem)
        (*S)->minElem = elem;
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

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        node tempStack;
        STACK temp = &tempStack;
        Initialize(&temp);

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&temp, Top((S)));
            Pop(&S);
        }

        while(!isEmpty(temp))
        {
            printf("%c ", Top(temp));
            Push(&S, Top(temp));
            Pop(&temp);
        }

        makeNull(&temp);
        printf("\n\n");
    }
}
DATATYPE Top(STACK S)
{
    return S->elemPtr[S->top];
}

bool isEmpty(STACK S)
{
    return (S->top==-1);
}

bool isFull(STACK S)
{
    return (S->top==MAX-1);
}

void makeNull(STACK *S)
{
    (*S)->top=-1;
    free((*S)->elemPtr);
}

void getMin(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        printf("\n===\nMin = %c\n", S->minElem);
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
        printf("\n===\nMax = %c\n", S->maxElem);
    }
}
int main()
{
    node stackOne;
    STACK A;
    A = &stackOne;

    Initialize(&A);
    Push(&A, 'A');
    Push(&A, 'B');
    Push(&A, 'C');
    Push(&A, 'D');
    Push(&A, 'E');
    Push(&A, 'F'); 
    Push(&A, 'G');
    Display(A);
    getMax(A);
    getMin(A);
    makeNull(&A);
    return 0;
}