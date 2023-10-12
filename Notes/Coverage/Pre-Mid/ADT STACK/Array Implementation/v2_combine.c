
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
            Push(&tempStack, Top(S));
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

void Combine(STACK A, STACK B, STACK *C)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyStackMsg();
    }
    else if((A->top + B->top)+2>MAX)
    {
        printf("\nCombined stack would exceed to the given MAX.\n");
        printf("\nUsing an array instead...\n");
        
        DATATYPE tempArr[(A->top + B->top)+2];
        node temp1, temp2;
        STACK t1, t2;
        t1 = &temp1;
        t2 = &temp2;
        Initialize(&t1);
        Initialize(&t2);
        int k;
        k=0;

        while(!isEmpty(A))
        {
            Push(&t1, Top(A));
            Pop(&A);
        }

        while(!isEmpty(B))
        {
            Push(&t2, Top(B));
            Pop(&B);
        }

        while(!isEmpty(t1))
        {
            tempArr[k++] = Top(t1);
            Push(&A, Top(t1));
            Pop(&t1);
        }

        while(!isEmpty(t2))
        {
            tempArr[k++] = Top(t2);
            Push(&B, Top(t2));
            Pop(&t2);
        }

        printf("\n-----\nArray: ");
        for(k=0; k<(A->top+B->top)+2; k++)
            printf("%c ", tempArr[k]);
        
        printf("\n\n");
    }
    else
    {
        Initialize(C);
        node temp1, temp2;
        STACK t1, t2;
        t1 = &temp1;
        t2 = &temp2;
        Initialize(&t1);
        Initialize(&t2);

        while(!isEmpty(A))
        {
            Push(&t1, Top(A));
            Pop(&A);
        }

        while(!isEmpty(B))
        {
            Push(&t2, Top(B));
            Pop(&B);
        }

        while(!isEmpty(t1))
        {
            Push(&A, Top(t1));
            Push(C, Top(t1));
            Pop(&t1);
        }

        while(!isEmpty(t2))
        {
            Push(&B, Top(t2));
            Push(C, Top(t2));
            Pop(&t2);
        }

        printf("\n\t>> Stacks successfully combined. <<\n\n");
    }
}
int main()
{
    node stackOne, stackTwo, result;
    STACK S, T, R;
    S = &stackOne;
    T = &stackTwo;
    R = &result;

    Initialize(&S);
    Initialize(&T);
    Initialize(&R);

    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');

    Push(&T, 'D');
    Push(&T, 'E');
    Push(&T, 'F');
    
    Combine(S, T, &R);

    // Display(R);

    return 0;
}