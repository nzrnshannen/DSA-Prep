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
void Display(STACK S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);

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
        STACK tempStack = &temp;
        Initialize(&tempStack);

        printf("\n-----\nSTACK: ");
        while(!isEmpty(S))
        {
            Push(tempStack, Top(S));
            Pop(&S);
        }

        while(!isEmpty(tempStack))
        {
            printf("%c ", Top(tempStack));
            Push(&S, Top(tempStack));
            Pop(&tempStack);
        }

        printf("\n\n");
    }
}

void Combine(STACK A, STACK B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyStackMsg();
    }
    else
    {

    }
}
int main()
{
    return 0;
}