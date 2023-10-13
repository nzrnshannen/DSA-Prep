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
int returnPos(STACK S, DATATYPE elem);
void Search(STACK S, DATATYPE elem);

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

    printf("\nMemory freed.\n\n");
}

int returnPos(STACK S, DATATYPE elem)
{
    int pos = 1;
    int found = -1;
    int count = 1;
    STACK temp;
    Initialize(&temp);
    while(!isEmpty(S))
    {
        Push(&temp, Top(S));
        Pop(&S);
    }

    for(; !isEmpty(temp) && Top(temp)!=elem; Pop(&temp), count++){}
    
    if(!isEmpty(temp) && Top(temp)==elem)
    {
        found=1;
        pos = count;
    }
    
    if(isEmpty(temp) && found==-1)
    {
        pos = found;
    }

    return pos;
}

void Search(STACK S, DATATYPE elem)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp1, temp2;
        Initialize(&temp1); 
        Initialize(&temp2);

        while(!isEmpty(S))
        {
            Push(&temp1, Top(S));
            Pop(&S);
        }

        while(!isEmpty(temp1))
        {
            Push(&temp2, Top(temp1));
            Push(&S, Top(temp1));
            Pop(&temp1);
        }

        int retval = returnPos(temp2, elem);

        if(retval!=-1)
        {
            printf("\n\t>> Element %c found at position %d. <<\n\n", elem, retval);
        }
        else
        {
            printf("\n\t>> Element %c doesn't exists!\n\n", elem);
        }
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

    Print(myStack);
    Print(myStack);
    Search(myStack, 'C');
    makeNull(&myStack);
    return 0;
}   