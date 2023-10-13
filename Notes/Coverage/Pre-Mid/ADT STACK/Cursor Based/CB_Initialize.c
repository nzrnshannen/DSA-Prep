#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;

typedef struct{
    DATATYPE elem;
    int link;
}nodeType;

typedef struct{
    nodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int STACK;

void InitStack(STACK *S);
void InitVirtualHeap(VirtualHeap *VH);
void emptyStackMsg();
void fullStackMsg();
bool isEmpty(STACK S);
bool isFull(VirtualHeap VH);
DATATYPE Top(STACK S, VirtualHeap VH);
void Display(STACK S, VirtualHeap VH);
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void Push(VirtualHeap *VH, STACK *S, DATATYPE elem);
void Pop(VirtualHeap* VH, STACK *S);

void InitStack(STACK* S)
{
    *S = -1;
}

void InitVirtualHeap(VirtualHeap *VH)
{
    int x;
    VH->Avail = MAX-1;
    for(x=0; x<MAX; x++)
        VH->Nodes[x].link = x-1;
}

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
    return (S==-1);
}

bool isFull(VirtualHeap VH)
{
    return (VH.Avail==-1);
}

DATATYPE Top(STACK S, VirtualHeap VH)
{
    return VH.Nodes[S].elem;
}

int allocSpace(VirtualHeap *VH)
{
    int retval = VH->Avail;
    if(retval!=-1)
    {
        VH->Avail = VH->Nodes[retval].link;
        VH->Nodes[retval].link = -1;
    }
    
    return retval;
}

void deallocSpace(VirtualHeap *VH, int ndx)
{
    if(ndx<MAX && ndx>=0)
    {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void Display(STACK S, VirtualHeap VH)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        VirtualHeap tempVH;
        STACK T;
        InitStack(&T);
        InitVirtualHeap(&tempVH);

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            Push(&tempVH, &T, Top(S, VH));
            Pop(&VH, &S);
        }

        while(!isEmpty(T))
        {
            printf("%c ", Top(T, tempVH));
            Pop(&tempVH, &T);
        }
        printf("\n");
    }
}

void Push(VirtualHeap *VH, STACK *S, DATATYPE elem)
{
    int ndx;
    ndx = allocSpace(VH);

    if(ndx!=-1)
    {
        VH->Nodes[ndx].elem = elem;
        VH->Nodes[ndx].link = *S;
        *S = ndx;
    }
}


void Pop(VirtualHeap *VH, STACK *S)
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


int main()
{
    VirtualHeap VH;
    STACK S;
    InitStack(&S);
    InitVirtualHeap(&VH);
    Push(&VH, &S, 'A');
    Push(&VH, &S, 'B');
    Push(&VH, &S, 'C');
    Push(&VH, &S, 'D');
    Push(&VH, &S, 'E');

    Display(S, VH);
    return 0;
}