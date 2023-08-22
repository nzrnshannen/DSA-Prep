//stack - linked list implementation
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *link;
}* top;
//pointer to node; stack is empty first
void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    temp->link=top; //if top=NULL, the first node to be pushed, specifically its link part, will be NULL at first
    //this is due to the reason that top is pointing to NULL in the first place 
    top=temp; //top is now pointing to the first node
}

void Pop()
{
    struct Node *temp;

    if(top==NULL)
    {
        printf("\n\nStack is empty\n\n");
        return;
    }

    temp=top; //temp will first point to the first node
    top=top->link; //top will now point to the second node
    free(temp); //free the memory (deallocating)
}

void Print()
{
    struct Node *print = top;
    printf("\nLinked list: ");
    while(print!=NULL)
    {
        printf("%d ", print->data);
        print = print->link;
    }

    printf("\n\n");
}

void isEmpty()
{
    if(top==0)
    {
        printf("\nEmpty stack\n");
    }
    else
    {
        printf("\nNot an empty stack\n");
    }
}

int getTop()
{
    return top->data;
}

int main()
{
    top=NULL;
    isEmpty();
    Push(1);
    Push(2);
    Push(3);
    Pop();
    isEmpty();
    printf("Top = %d", getTop());
    Print();

    struct Node *temp;

    while(top!=0)
    {
        temp=top;
        top=top->link;
        free(temp);
    }
    return 0;
}


