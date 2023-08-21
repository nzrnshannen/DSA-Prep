//stack: last-in-first-out (LIF0)

/*
    STACK ADT (LIFO)
    - list with the restriction that insertion and deletion
    can be performed only from one end, called the top

    OPERATIONS
    1. Push(x) <-- insert element at the top of stack
    2. Pop() <-- delete element at the top of stack
    3. Top() <-- returns the element on top of the stack
    4. IsEmpty() <-- returns true if the stack is empty, false otherwise

    Time complexity of these operations is 0(1) or constant time

    Applications
        - Function calls/recursions
        - undo operation
        - balanced parenthesis
*/  

//implementation of stacks: a) arrays b) linked lists

//array-based: basic implementation of stack (NOT IDEAL IMPLEMENTATION, THIS IS FOR TESTING PURPOSES ONLY)

#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top=-1; //empty stack 

void Push(int x);
void Pop();
int IsEmpty();
int Top();

void Push(int x) //x is the data to be inserted
{
    //handle overflow
    //MAX_SIZE-1 is the highest index in the array

    if(top==MAX_SIZE-1) //we are comparing indexes so MAX_SIZE-1
    {
        printf("Error: Stack overflow\n");
        return; //code below if() statement won't be executed
    }

    top++; //top=top+1;
    A[top] = x; 

    //or you can do A[++top]=x as pre incre will happen first
}

void Pop()
{
    if(IsEmpty())
    {
        printf("Error: No element to pop\n");
        return;
    }

    top--; //top=top-1;
}

int IsEmpty()
{
    if(top==-1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int Top()
{
    return A[top]; //returns the top of the stack or the last element in the array
}

void Print()
{
    printf("\nStack: ");
    for(int i=0;i<=top; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");
}

int main()
{
    Push(2); 
    Print();

    Push(5); 
    Print();

    Push(10); 
    Print();

    Pop(); 
    Print();

    Push(12); 
    Print();

    return 0;
}

