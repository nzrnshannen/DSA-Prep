/*
    Name: Shannen T. Nazareno
    
    deallocSpace() is not implemented as deletion function is not used in
    the program. The program is merely for insertion (at end), initialize (both virtual
    heap and list), and display.
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 6

typedef struct{
    char elem;
    int link;
}node;

typedef struct{
    node Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int CLIST; //head

bool isEmpty(CLIST C);
bool isFull(VirtualHeap V);
void emptyListMsg();
void fullListMsg();
void InitVirtualHeap(VirtualHeap *V);
void Print(VirtualHeap V, CLIST C);
void Insert(VirtualHeap *V, CLIST *C, char elem); //insert at end
int allocSpace(VirtualHeap *V);
void InitList(CLIST* C);

void InitList(CLIST* C)
{
    *C = -1; //head is null
}

int allocSpace(VirtualHeap *V)
{
    int retVal = -1;
    if(V->Avail!=-1)
    {
        retVal = V->Avail;
        V->Avail = V->Nodes[retVal].link;
    }
    
    return retVal;
}

bool isEmpty(CLIST C)
{
    return (C==-1);
}

bool isFull(VirtualHeap V)
{
    return (V.Avail==-1);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

void InitVirtualHeap(VirtualHeap *V)
{
    V->Avail = 0;
    int x;
    for(x=0; x<MAX-1; x++)
        V->Nodes[x].link = x+1;
    
    V->Nodes[x].link = -1;
}

void Print(VirtualHeap V, CLIST C)
{
    if(isEmpty(C))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        int ndx;
        for(ndx = C; ndx!= V.Avail; ndx = V.Nodes[ndx].link)
            printf("%c ", V.Nodes[ndx].elem);
        
        printf("\n");
    }
}

void Insert(VirtualHeap *V, CLIST *C, char elem)
{
    int ndx = allocSpace(V);
    if(ndx!=-1)
    {
        V->Nodes[ndx].elem = elem;
        if(isEmpty(*C))
        {
            *C = ndx;
        }
    }
    else
    {
        fullListMsg();
    }
}

int main()
{
    VirtualHeap V;
    CLIST C;
    InitList(&C);
    InitVirtualHeap(&V);
    Insert(&V, &C, 'A');
    Insert(&V, &C, 'B');
    Insert(&V, &C, 'C');
    Insert(&V, &C, 'D');
    Insert(&V, &C, 'E');
    Insert(&V, &C, 'F');
    Insert(&V, &C, 'G');
    Print(V, C);
    return 0;
}