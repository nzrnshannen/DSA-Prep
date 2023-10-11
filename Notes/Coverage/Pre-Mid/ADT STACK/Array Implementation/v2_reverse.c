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
void Display(STACK S);
DATATYPE Top(STACK S);
bool isEmpty(STACK S);
bool isFull(STACK S);
STACK newForm(STACK S);
void Reverse(STACK *S);

void emptyStackMsg()
{
    printf("\n\n\tStack is empty!\n\n");
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

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        node tempStack;
        STACK temp;
        temp = &tempStack;
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

DATATYPE Top(STACK S)
{
    return S->elem[S->top];
}

bool isEmpty(STACK S)
{
    return (S->top==-1);
}

bool isFull(STACK S)
{
    return (S->top==MAX-1);
}

void Reverse(STACK *S) //modify this code
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        node temp1, temp2;
        STACK tempPtr1, tempPtr2;
        tempPtr1 = &temp1;
        tempPtr2 = &temp2;
        Initialize(&tempPtr1);
        Initialize(&tempPtr2);

        while(!isEmpty(*S))
        {
            Push(&tempPtr1, Top(*S));
            Pop(S);
        }

        while(!isEmpty(tempPtr1))
        {
            Push(&tempPtr2, Top(tempPtr1));
            Pop(&tempPtr1);
        }
        
        Initialize(S);
        while(!isEmpty(tempPtr2))
        {
            Push(S, Top(tempPtr2));
            Pop(&tempPtr2);
        }

        printf("\n\n\t>> Stack reversed. <<\n\n");
    }
}

int main()
{
    node stackOne;
    STACK P;
    P = &stackOne;
    Initialize(&P);
    Push(&P, 'A');
    Push(&P, 'B');
    Push(&P, 'C');
    Push(&P, 'D');
    Push(&P, 'E');
    Display(P);
    Reverse(&P);
    Display(P);
    return 0;
}