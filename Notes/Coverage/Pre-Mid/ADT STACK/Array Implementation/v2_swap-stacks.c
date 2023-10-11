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
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
bool isEmpty(STACK S);
bool isFull(STACK S);
void Display(STACK S);
DATATYPE Top(STACK S);
void Swap(STACK *A, STACK *B);

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

DATATYPE Top(STACK S)
{
    return S->elem[S->top];
}

void Swap(STACK *A, STACK *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyStackMsg();
    }
    else
    {   
        node t1, t2;
        STACK temp1 = &t1, temp2 = &t2;
        Initialize(&temp1);
        Initialize(&temp2);
        
        while(!isEmpty(*A))
        {
            Push(&temp1, Top(*A));
            Pop(A);
        }

        while(!isEmpty(*B))
        {
            Push(&temp2, Top(*B));
            Pop(B);
        }

        while(!isEmpty(temp1))
        {
            Push(B, Top(temp1));
            Pop(&temp1);
        }

        while(!isEmpty(temp2))
        {
            Push(A, Top(temp2));
            Pop(&temp2);
        }

        printf("\n\n\t>> Successfully swapped stacks. << \n\n");
    }
}

int main()
{
    node myStack, example;
    STACK S = &myStack;
    STACK T = &example;
    Initialize(&S);
    Initialize(&T);

    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');
    Push(&S, 'D');
    Push(&S, 'E');

    Push(&T, 'F');
    Push(&T, 'G');
    Push(&T, 'H');
    Push(&T, 'I');
    Push(&T, 'J');

    Display(S);
    Display(T);

    Swap(&S, &T);
    Display(S);
    Display(T);
    return 0;
}