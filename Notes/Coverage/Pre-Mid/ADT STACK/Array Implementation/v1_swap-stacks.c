#include<stdio.h>
#include<stdbool.h>
#define MAX 6

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
void Display(STACK S);
void Initialize(STACK *S);
DATATYPE Top(STACK S);
void Swap(STACK *A, STACK *B);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\nStack overflow!\n\n");
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
        S->elem[S->top]=elem;
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
            Pop(&temp);
        }

        printf("\n");
    }
}

void Initialize(STACK *S)
{
    S->top=-1;
}

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}

void Swap(STACK *A, STACK *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp1, temp2;
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

        while(!isEmpty(temp2))
        {
            Push(A, Top(temp2));
            Pop(&temp2);
        }

        while(!isEmpty(temp1))
        {
            Push(B, Top(temp1));
            Pop(&temp1);
        }
        
        printf("\n\n\t>> Stacks reversed. << \n\n");
    }
}

int main()
{
    STACK stackOne, stackTwo;
    Initialize(&stackOne);
    Initialize(&stackTwo);
    Push(&stackOne, 'A');
    Push(&stackOne, 'B');
    Display(stackOne);

    Push(&stackTwo, 'C');
    Push(&stackTwo, 'D');
    Display(stackTwo);

    Swap(&stackOne, &stackTwo);
    Display(stackOne);
    Display(stackTwo);
    return 0;
}