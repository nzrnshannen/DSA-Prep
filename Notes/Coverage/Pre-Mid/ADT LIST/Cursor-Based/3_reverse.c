/*
    Name: Shannen T. Nazareno
    
    deallocSpace is not applicable in this program as
    it solely focus on reversing the list only. 
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

typedef int CLIST;

void emptyListMsg();
void fullListMsg();
bool isEmpty(CLIST C);
bool isFull(VirtualHeap VH); //redundant
void InitVirtualHeap(VirtualHeap *VH);
void InitList(CLIST *C);
void Insert(VirtualHeap *VH, CLIST *C, char elem);
void Print(VirtualHeap VH, CLIST C);
void Reverse(VirtualHeap *VH, CLIST *C);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void fullListMsg()
{
    printf("\n\n\tList is full!\n\n");
}

bool isEmpty(CLIST C)
{
    return (C==-1);
}

bool isFull(VirtualHeap VH)
{
    return (VH.Avail==-1);
}

void InitList(CLIST *C)
{
    *C = -1; //empty list
}

void InitVirtualHeap(VirtualHeap *VH)
{
    VH->Avail = MAX-1;
    int x;
    for(x=MAX-1; x>=0; x--)
    {
        VH->Nodes[x].link = x-1;
    }
}

int allocSpace(VirtualHeap *VH)
{
    int retval=-1; 
    if(VH->Avail!=-1)
    {
        retval = VH->Avail;
        VH->Avail = VH->Nodes[retval].link;
    }

    return retval;
}

void Insert(VirtualHeap *VH, CLIST *C, char elem)
{
    int ndx = allocSpace(VH);
    if(ndx!=-1)
    {
        VH->Nodes[ndx].elem = elem;

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

void Print(VirtualHeap VH, CLIST C)
{
    if(isEmpty(C))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        int x;
        for(x=C; x!=-1; x=VH.Nodes[x].link)
            printf("%c ", VH.Nodes[x].elem);
        
        printf("\n");
    }
}

void Reverse(VirtualHeap *VH, CLIST *C)
{
    if(isEmpty(*C))
    {
        emptyListMsg();
    }
    else
    {
        int y;
        for(y=MAX-1; VH->Nodes[y].link!=-1; y=VH->Nodes[y].link){}

        *C=y;

        for(; y<MAX-1; y++)
            VH->Nodes[y].link = y+1;
            
        VH->Nodes[y].link=-1;

        printf("\n\n\t>> List reversed. <<\n\n");
    }
}

int main()
{
    CLIST C;
    VirtualHeap VH;
    InitList(&C);
    InitVirtualHeap(&VH);
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'B');
    Insert(&VH, &C, 'C');
    Insert(&VH, &C, 'D');
    Insert(&VH, &C, 'E');
    Insert(&VH, &C, 'F');
    Insert(&VH, &C, 'G');
    Print(VH, C);
    Reverse(&VH, &C);
    Print(VH, C);
    return 0;
}