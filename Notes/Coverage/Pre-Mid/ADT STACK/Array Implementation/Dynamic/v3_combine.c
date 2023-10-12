#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 5

typedef char DATATYPE;

typedef struct{
    DATATYPE *elemPtr;
    int top;
}STACK;

void errorMsg();
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
void Display(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
DATATYPE Top(STACK S);
void makeNull(STACK *S);
void Combine(STACK A, STACK B, STACK *C);
void emptyStackMsg();

void errorMsg()
{
    printf("\n\n\tMemory allocation failure!\n\n");
    exit(1);
}

void Initialize(STACK *S)
{
    S->top=-1;
    S->elemPtr = (DATATYPE *)malloc(sizeof(DATATYPE) * MAX);
    if(S->elemPtr==NULL)
    {
        errorMsg();
    }
}

void Push(STACK *S, DATATYPE elem)
{
    if(isFull(*S))
    {
        int newMax = (S->top+1) * 2; 
        S->elemPtr = (DATATYPE*)realloc(S->elemPtr, sizeof(DATATYPE) * newMax);
        if(S->elemPtr==NULL)
        {
            errorMsg();
        }

        S->top++;
        S->elemPtr[S->top] = elem;
    }
    else
    {
        S->top++;
        S->elemPtr[S->top] = elem;
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
            DATATYPE ch = Top(temp);
            printf("%c ", ch);
            Pop(&temp);
        }

        printf("\n\n");
        makeNull(&temp);
    }
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

DATATYPE Top(STACK S)
{
    return S.elemPtr[S.top];
}

void makeNull(STACK *S)
{
    free(S->elemPtr);
    S->top=-1;
}

void Combine(STACK A, STACK B, STACK *C)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp1, temp2;
        Initialize(&temp1);
        Initialize(&temp2);
        Initialize(C);
        while(!isEmpty(A))
        {
            Push(&temp1, Top(A));
            Pop(&A);
        }

        while(!isEmpty(B))
        {
            Push(&temp2, Top(B));
            Pop(&B);
        }

        while(!isEmpty(temp1))
        {
            Push(C, Top(temp1));
            Pop(&temp1);
        }

        while(!isEmpty(temp2))
        {
            Push(C, Top(temp2));
            Pop(&temp2);
        }

        makeNull(&temp1);
        makeNull(&temp2);

        printf("\n\t>> Successfully combined stacks. <<\n\n");
    }
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

int main()
{
    STACK A, B, C;
    Initialize(&A);
    Initialize(&B);
    Initialize(&C);

    Push(&A, 'A');
    Push(&A, 'B');
    Push(&A, 'C');
    Push(&A, 'D');
    Push(&A, 'E');
    Push(&A, 'F');

    Push(&B, 'G');
    Push(&B, 'H');
    Push(&B, 'I');
    Push(&B, 'J');
    Push(&B, 'K');
    Push(&B, 'L');

    Display(A);
    Display(B);
    Combine(A, B, &C);

    Display(C);

    makeNull(&A);
    makeNull(&B);
    makeNull(&C);

    return 0;
}  