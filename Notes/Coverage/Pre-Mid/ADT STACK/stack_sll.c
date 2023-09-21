#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}Node, *STACK;

void initStack(STACK *S);
void push(STACK *S, int x);
void pop(STACK *S);
void display(STACK *S);
void clear(STACK *S);
bool isEmpty(STACK *S);
void emptyStackMsg();
int top(STACK *S);

void initStack(STACK* S)
{
    *S = NULL;
}

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void display(STACK *S)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        //temp stack
        printf("\n---\nStack: ");
        STACK temp;
        int retVal;
        initStack(&temp);
        while(!(isEmpty(S)))
        {
            retVal = top(S);
            push(&temp, retVal);
            pop(S);
        }

        while(!(isEmpty(&temp)))
        {
            retVal = top(&temp);
            printf("%d ", retVal);
            push(S, retVal);
            pop(&temp);
        }
      
        printf("\n");

    }
}

bool isEmpty(STACK *S)
{
    return (*S==NULL);
}

void push(STACK *S, int x)
{
    STACK newNode = (STACK)malloc(sizeof(Node));
    if(newNode==NULL)
    {
        printf("\n\nMemory allocation failed!\n\n");
        //clear
        exit(1);
    }
    else
    {
        newNode->data = x;
        newNode->link= (*S);
        *S = newNode;

    }
}

void pop(STACK *S)
{
    if(isEmpty(S))
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

void clear(STACK *S)
{
    while(*S!=NULL)
    {
        STACK temp;
        temp = *S;
        *S = (*S)->link;
        free(temp);
    }
}

int top(STACK *S)
{
    return (*S)->data;
}

int main()
{
    STACK top;
    initStack(&top);
    push(&top, 1);
    push(&top, 2);
    push(&top, 3);
    push(&top, 4);
    pop(&top);
    display(&top);
    clear(&top);

    return 0;
}