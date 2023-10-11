#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;

typedef struct{
    char elem[MAX];
    int top;
}STACK;

void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(STACK S);
void Initialize(STACK *S);
void Push(STACK *S, char elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Display(STACK S);
int posOfElem(STACK S, char elem);
void Search(STACK S, char elem);

void emptyStackMsg()
{
    printf("\n\n\tStack is empty!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

void Initialize(STACK *S)
{
    S->top=-1;
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

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
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

int posOfElem(STACK S, char elem)
{
    int count = MAX;
    for(; !isEmpty(S) && Top(S)!=elem; Pop(&S), count--){}

    return count;
}

void Search(STACK S, char elem)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        int pos = posOfElem(S, elem);
        if(pos!=0)
        {
            printf("\nElement %c is at position %d.\n", elem, pos);
        }
        else
        {
            printf("\nElement %c does not exist.\n", elem);
        }
    }
}

int main()
{
    STACK myStack;
    Initialize(&myStack);
    Push(&myStack, 'A');
    Push(&myStack, 'S');
    Push(&myStack, 'B');
    Push(&myStack, 'H');
    Push(&myStack, 'N');
    Display(myStack);
    Search(myStack, 'N');
    return 0;
}