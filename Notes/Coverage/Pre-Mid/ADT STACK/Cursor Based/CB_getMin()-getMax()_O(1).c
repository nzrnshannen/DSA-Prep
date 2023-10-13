#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef char DATATYPE;
typedef int STACK;

typedef struct{
    DATATYPE elem;
    int link;
}node;

typedef struct{
    node Nodes[MAX];
    int Avail;
    DATATYPE maxElem;
    DATATYPE minElem;
}VirtualHeap;

void emptyStackMsg();
void fullStackMsg();
void InitStack(STACK *S);
void InitVirtualHeap(VirtualHeap *VH);
void Display(STACK S, VirtualHeap VH);
void Push(STACK *S, VirtualHeap *VH, DATATYPE elem);
void Pop(STACK *S, VirtualHeap* VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);
bool isEmpty(STACK S);
bool isFull(VirtualHeap VH);
DATATYPE Top(VirtualHeap VH, STACK S);
void getMax(VirtualHeap VH);
void getMin(VirtualHeap VH);

void emptyStackMsg()
{
    printf("\n\n\tEmpty Stack!\n\n");
}

void fullStackMsg()
{
    printf("\n\n\tStack overflow!\n\n");
}

void InitStack(STACK *S)
{
    *S = -1;
}

void InitVirtualHeap(VirtualHeap *VH)
{
    int x;
    VH->Avail = MAX-1;
    for(x=0; x<MAX; x++)
        VH->Nodes[x].link = x-1;

    VH->maxElem = '\0';
    VH->minElem = 'z';
}

void Display(STACK S, VirtualHeap VH)
{
    if(isEmpty(S))
    {
        emptyStackMsg();
    }
    else
    {
        STACK T;
        VirtualHeap temp;
        InitStack(&T);
        InitVirtualHeap(&temp);
        DATATYPE ch;

        printf("\n-----\nStack: ");
        while(!isEmpty(S))
        {
            ch = Top(VH, S);
            Push(&T, &temp, ch);
            Pop(&S, &VH);
        }

        while(!isEmpty(T))
        {
            ch = Top(temp, T);
            printf("%c ", ch);
            Pop(&T, &temp);
        }

        printf("\n\n");
    }
}

void Push(STACK *S, VirtualHeap *VH, DATATYPE elem)
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

    if(elem > VH->maxElem)
        VH->maxElem = elem;
    
    if(elem < VH->minElem)
        VH->minElem = elem;
}

void Pop(STACK *S, VirtualHeap *VH)
{
    if(isEmpty(*S))
    {
        emptyStackMsg();
    }
    else
    {
        int temp;
        temp = *S;
        *S = VH->Nodes[*S].link;
        deallocSpace(VH, temp);
    }
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
    if(ndx>=0 && ndx<MAX)
    {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

bool isEmpty(STACK S)
{
    return (S==-1);
}

bool isFull(VirtualHeap VH)
{
    return (VH.Avail==-1);
}

DATATYPE Top(VirtualHeap VH, STACK S)
{
    return VH.Nodes[S].elem;
}

void getMin(VirtualHeap VH)
{
    printf("\n===\nMin = %c\n\n", VH.minElem);
}

void getMax(VirtualHeap VH)
{
    printf("\n===\nMax = %c\n\n", VH.maxElem);
}

int main()
{
    VirtualHeap VH;
    STACK S;
    InitStack(&S);
    InitVirtualHeap(&VH);

    Push(&S, &VH, 'A');
    Push(&S, &VH, 'B');
    Push(&S, &VH, 'C');
    Push(&S, &VH, 'D');
    Push(&S, &VH, 'E');

    Display(S, VH);
    getMax(VH);
    getMin(VH);
    Display(S, VH);

    return 0;
}