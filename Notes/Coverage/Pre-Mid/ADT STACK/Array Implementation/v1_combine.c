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
bool isEmpty(STACK S);
bool isFull(STACK S);
void Initialize(STACK *S);
void Display(STACK S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Combine(STACK A, STACK B, STACK *C);

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

void Display(STACK S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        printf("\n----\nStack: ");
        STACK temp;
        Initialize(&temp);
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

DATATYPE Top(STACK S)
{
    return S.elem[S.top];
}

void Combine(STACK A, STACK B, STACK *C)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyStackMsg();
    }
    else
    {
        if((A.top + B.top)+2>MAX)
        {
            DATATYPE tempArr[(A.top + B.top)+2];
            int x=0;

            fullStackMsg();
            printf("\nCannot combine using stack due to MAX.\n");
            printf("Array: ");

            while(!isEmpty(B))
            {
                tempArr[x++] = Top(B);
                Pop(&B);
            }

            while(!isEmpty(A))
            {
                tempArr[x++] = Top(A);
                Pop(&A);
            }
            
            printf("\n-----\nArray: ");
            for(x=x-1; x>=0; x--)
                printf("%c ", tempArr[x]);
            printf("\n");
        }
        else
        {
            STACK temp;
            Initialize(&temp);

            while(!isEmpty(B))
            {
                Push(&temp, Top(B));
                Pop(&B);
            }

            while(!isEmpty(A))
            {
                Push(&temp, Top(A));
                Pop(&A);
            }

            while(!isEmpty(temp))
            {
                Push(C, Top(temp));
                Pop(&temp);
            }

            Display(*C);
        }

        printf("\n\n>> Successfully combined two stacks. <<\n\n");
    }
}

int main()
{
    STACK stackOne, stackTwo, myStack;
    Initialize(&stackOne);
    Initialize(&stackTwo);
    Initialize(&myStack);

    Push(&stackOne, 'A');
    Push(&stackOne, 'B');;

    Push(&stackTwo, 'F');
    Push(&stackTwo, 'G');
    Push(&stackTwo, 'H');

    Display(stackOne);
    Display(stackTwo);

    Combine(stackOne, stackTwo, &myStack);
    return 0;
}