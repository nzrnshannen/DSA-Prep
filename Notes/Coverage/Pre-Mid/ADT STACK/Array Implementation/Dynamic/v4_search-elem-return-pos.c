#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE *elemPtr;
    int top;
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
void Search(STACK S, DATATYPE elem);
int returnPos(STACK S, DATATYPE elem);

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

int returnPos(STACK S, DATATYPE elem)
{
    node tempStack, copyStack;
    STACK temp = &tempStack;
    STACK copy = &copyStack;
    Initialize(&temp);
    Initialize(&copy);
    
    while(!isEmpty(S))
    {
        Push(&temp, Top(S));
        Push(&copy, Top(S));
        Pop(&S);
    }

    while(!isEmpty(temp))
    {
        Push(&S, Top(temp));
        Pop(&temp);
    }

    int retval=S->top+1;

    for(; !isEmpty(S) && elem!=Top(S); Pop(&S), retval--){}

    Initialize(&S);

    makeNull(&temp);
    makeNull(&copy);

    return retval;
}

void Search(STACK S, DATATYPE elem)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        node tempStack1, tempStack2;
        STACK temp1 = &tempStack1;
        STACK temp2 = &tempStack2;
        Initialize(&temp1);
        Initialize(&temp2);

        while(!isEmpty(S))
        {
            Push(&temp1, Top(S));
            Pop(&S);
        }

        while(!isEmpty(temp1))
        {
            Push(&temp2, Top(temp1));
            Push(&S, Top(temp1));
            Pop(&temp1);
        }

        int retval = returnPos(temp2, elem);

        if(retval!=0)
        {
            printf("\n\t>> Element %c found at position %d.<< \n\n", elem, retval);
        }
        else
        {
            printf("\n\t>> Element %c doesn't exists! <<\n\n", elem);
        }

        makeNull(&temp1);
        makeNull(&temp2);
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
    Push(&A, 'H');

    Display(A);
    Search(A, 'A');
    Display(A);
    makeNull(&A);
    return 0;
}