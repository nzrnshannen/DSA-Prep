//needs fixing

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char DATATYPE;
typedef struct node{
    DATATYPE elem;
    struct node *link;
}nodeType, *STACK;

void emptyStackMsg();
void Initialize(STACK *S);
void Push(STACK *S, DATATYPE elem);
void Pop(STACK *S);
DATATYPE Top(STACK S);
void Print(STACK S);
bool isEmpty(STACK S);
void makeNull(STACK *S);
void Combine(STACK *A, STACK *B, STACK *C);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void Initialize(STACK *S)
{
    *S = NULL;
}

void Push(STACK *S, DATATYPE elem)
{
    STACK newNode = (STACK)malloc(sizeof(nodeType));
    if(newNode==NULL)
    {
        printf("\nMemory allocation failure!\n\n");
        exit(1);
    }

    newNode->elem = elem;
    newNode->link = *S;
    *S = newNode;
}

void Pop(STACK *S)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

DATATYPE Top(STACK S)
{
    return S->elem;
}

void Print(STACK S)
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

bool isEmpty(STACK S)
{
    return (S==NULL);
}

void makeNull(STACK *S)
{
    while(!isEmpty(*S))
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }

    printf("\n\t>> Memory freed. <<\n\n");
}

void Combine(STACK *A, STACK *B, STACK *C)
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
        Initialize(C);

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
            Push(A, Top(temp1));
            Push(C, Top(temp1));
            Pop(&temp1);
        }

        while(!isEmpty(temp2))
        {
            Push(B, Top(temp2));
            Push(C, Top(temp2));
            Pop(&temp2);
        }
        makeNull(&temp1);
        makeNull(&temp2);

        printf("\n\n\t>> Stacks successfully combined. <<\n\n");
    }
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

    Push(&B, 'E');
    Push(&B, 'F');
    Push(&B, 'G');
    Push(&B, 'H');

    Print(A);
    Print(B);
    Combine(&A, &B, &C);

    Print(A);
    Print(B);
    Print(C);

    //needs to be fixed
    return 0;
}   