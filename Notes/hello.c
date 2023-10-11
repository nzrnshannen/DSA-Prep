#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef struct{
    DATATYPE elem[MAX];
    int top;
}STACK;

void emptyStackMsg();
void fullStackMsg();
DATATYPE Top(STACK S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
void Display(STACK S);
void Initialize(STACK *S);
bool isEmpty(STACK S);
bool isFull(STACK S);
bool checkIfSorted(STACK A;);
void Sort(STACK *S);
void Copy(STACK A, STACK *B);

void emptyStackMsg()
{
    printf("\n\n\tEmpty Stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}

void Push(STACK *S, DATATYPE elem)
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

        printf("\n\n");
    }
}

void Initialize(STACK *S)
{
    S->top=-1;
}

bool isEmpty(STACK S)
{
    return (S.top==-1);
}

bool isFull(STACK S)
{
    return (S.top==MAX-1);
}

bool checkIfSorted(STACK S)
{
    STACK T;
    Initialize(&T);
    Copy(S, &T);

    for(; !isEmpty(T) && Top(S) < Top(T); Pop(&T));

    return (isEmpty(T));
}

void Sort(STACK *S)
{
    if(!checkIfSorted(*S))
    {
        while(!checkIfSorted(*S))
        {
            STACK temp, copy_one, copy_two;
            Initialize(&copy_one);
            Initialize(&copy_two);
            Initialize(&temp);
            Copy(*S, &copy_one);
            Copy(*S, &copy_two);
            
            Pop(&copy_two);
            for(; !isEmpty(copy_two); Pop(&copy_one), Pop(&copy_two))
            {
                if(Top(copy_two) > Top(copy_one))
                {
                    Push(&temp, Top(copy_one));
                    Push(&temp, Top(copy_two));
                }
                else
                {
                    Push(&temp, Top(copy_two));
                    Push(&temp, Top(copy_one));
                }
            }

            Initialize(S);
            Copy(temp, S);
        }

        printf("\n\t>> Stack sorted. <<\n");
    }
    else
    {
        printf("\n\t>> Stack already sorted! <<\n");
    }
}

void Copy(STACK A, STACK *B)
{
    STACK temp;
    Initialize(&temp);

    while(!isEmpty(A))
    {
        Push(&temp, Top(A));
        Pop(&A);
    }

    while(!isEmpty(temp))
    {
        Push(B, Top(temp));
        Pop(&temp);
    }
}
int main()
{
    STACK myStack;
    Initialize(&myStack);
    Push(&myStack, 'A');
    Push(&myStack, 'B');
    Push(&myStack, 'C');
    Push(&myStack, 'D');
    Push(&myStack, 'E');

    Display(myStack);
    Sort(&myStack);
    Display(myStack);
    return 0;
}