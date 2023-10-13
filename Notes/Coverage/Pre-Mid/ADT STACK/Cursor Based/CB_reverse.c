#include<stdio.h>
#include<stdbool.h>
#define MAX 10

typedef char DATATYPE;
typedef int STACK;
typedef struct{
    DATATYPE elem;
    int link;
}nodetype;

typedef struct{
    nodetype Nodes[MAX];
    int Avail;
}VHeap;

void emptyStackMsg();
void fullStackMsg();
void InitStack(STACK *S);
void InitVirtualHeap(VHeap *VH);
bool isEmpty(STACK S);
bool isFull(VHeap VH);
DATATYPE Top(STACK S, VHeap VH);
void Push(STACK *S, VHeap *VH, DATATYPE elem);
void Pop(STACK *S, VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
int allocSpace(VHeap *VH);
void Display(STACK S, VHeap VH);
void Reverse(STACK *s, VHeap *VH);

void emptyStackMsg()
{
    printf("\n\n\tEmpty stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

void InitStack(STACK *S)
{
    *S = -1;
}

void InitVirtualHeap(VHeap *VH)
{
    int x;
    VH->Avail = MAX-1;
    for(x=0; x<MAX; x++)
        VH->Nodes[x].link = x-1;
}

bool isEmpty(STACK S)
{
    return (S==-1);
}

bool isFull(VHeap VH)
{
    return (VH.Avail==-1);
}

DATATYPE Top(STACK S, VHeap VH)
{
    return VH.Nodes[S].elem;
}

void Push(STACK *S, VHeap *VH, DATATYPE elem)
{
    int ndx = allocSpace(VH);
    if(ndx!=-1)
    {
        VH->Nodes[ndx].elem = elem;
        VH->Nodes[ndx].link = *S;
        *S = ndx;
    }
    else
    {
        fullStackMsg();
    }
}

void Pop(STACK *S, VHeap *VH)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK temp = *S;
        *S = VH->Nodes[temp].link;
        deallocSpace(VH, temp);
    }
}

void deallocSpace(VHeap *VH, int ndx)
{
    if(ndx<MAX && ndx>=0)
    {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void Display(STACK S, VHeap VH)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK T;
        VHeap tempVH;
        DATATYPE ch;

        InitStack(&T);
        InitVirtualHeap(&tempVH);

        printf("\n-----\nSTACK: ");
        while(!isEmpty(S))
        {   
            ch = Top(S, VH);
            Push(&T, &tempVH, ch);
            Pop(&S, &VH);
        }

        while(!isEmpty(T))
        {
            ch = Top(T, tempVH);
            printf("%c ", ch);
            Pop(&T, &tempVH);
        }

        printf("\n\n");
    }
}

int allocSpace(VHeap *VH)
{
    int retval = VH->Avail;

    if(retval!=-1)
    {
        VH->Avail = VH->Nodes[retval].link;
        VH->Nodes[retval].link = -1;
    }

    return retval;
}

void Reverse(STACK *S, VHeap *VH)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK T1, T2;
        VHeap temp1, temp2;
        DATATYPE ch;

        InitStack(&T1);
        InitStack(&T2);
        InitVirtualHeap(&temp1);
        InitVirtualHeap(&temp2);

        while(!isEmpty(*S))
        {
            ch = Top(*S, *VH);
            Push(&T1, &temp1, ch);
            Pop(S, VH);
        }
        
        while(!isEmpty(T1))
        {
            ch = Top(T1, temp1);
            Push(&T2, &temp2, ch);
            Pop(&T1, &temp1);
        }

        while(!isEmpty(T2))
        {
            ch = Top(T2, temp2);
            Push(S, VH, ch);
            Pop(&T2, &temp2);
        }

        printf("\n\n\t>> Stack successfully reversed. <<\n\n");
    }
}

int main()
{
    VHeap VH;
    STACK S;
    InitStack(&S);
    InitVirtualHeap(&VH);

    Push(&S, &VH, 'A');
    Push(&S, &VH, 'B');
    Push(&S, &VH, 'C');
    Push(&S, &VH, 'D');
    Push(&S, &VH, 'E');

    Display(S, VH);
    Reverse(&S, &VH);
    Display(S, VH);

    return 0;
}   