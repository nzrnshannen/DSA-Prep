/*
    Name: Shannen T. Nazareno
    Program: Delete occurrence/s of an element.
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 5

typedef struct{
    char elem;
    int link;
}nodeType;

typedef struct{
    nodeType Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int CLIST;

void emptyListMsg();
void fullListMsg();
bool isEmpty(CLIST C);
bool isFull(VirtualHeap VH);
void InitList(CLIST *C);
void InitVirtualHeap(VirtualHeap *VH);
int allocSpace(VirtualHeap *VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void Insert(VirtualHeap *VH, CLIST *C, char elem);
void Delete(VirtualHeap *VH, CLIST *C, char elem);
void Print(VirtualHeap VH, CLIST C);

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
    *C = -1;
}

void InitVirtualHeap(VirtualHeap *VH)
{
    VH->Avail=0;
    int x;
    for(x=0; x<MAX-1; x++)
    {
        VH->Nodes[x].link = x+1;
    }
    VH->Nodes[x].link = -1;
}

int allocSpace(VirtualHeap *VH)
{
    int retval=-1;
    if(VH->Avail!=-1)
    {
        retval = VH->Avail;
        VH->Avail=VH->Nodes[retval].link;
    }

    return retval;
}

void deallocSpace(VirtualHeap *VH, int ndx)
{
    if(ndx>=0 && ndx < MAX)
    {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

void Insert(VirtualHeap *VH, CLIST *C, char elem)
{
    if(isFull(*VH))
    {
        fullListMsg();
    }
    else
    {
        int ndx;
        ndx = allocSpace(VH);
        VH->Nodes[ndx].elem = elem;
        if(isEmpty(*C))
        {
            *C = ndx;
        }
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
        for(x=C; x!=VH.Avail; x=VH.Nodes[x].link)
            printf("%c ", VH.Nodes[x].elem);
        
        printf("\n");
    }
}

void Delete(VirtualHeap *VH, CLIST *C, char elem)
{
    if(isEmpty(*C))
    {
        emptyListMsg();
    }
    else
    {
        int x, y, z;
        z = MAX;
        for(x=*C; x!=VH->Avail; )
        {
            if(VH->Nodes[x].elem==elem)
            {
                if(*C==x)
                {
                    *C=VH->Nodes[x].link;
                    x=*C;
                }
                else
                {
                    for(y=*C; VH->Nodes[y].link!=x; y=VH->Nodes[y].link){}
                        VH->Nodes[y].link = VH->Nodes[x].link;
                    
                    x=VH->Nodes[x].link;
                }
                z--;
            }
            else
            {
                x=VH->Nodes[x].link;
            }
        }

        if(z==MAX)
        {
            printf("\n\t>> Element %c does not exist. <<\n\n", elem);
        }
        else
        {
            printf("\n\t>> Element %c deleted. <<\n\n", elem);
        }
    }
}

int main()
{
    CLIST C;
    VirtualHeap VH;
    InitList(&C);
    InitVirtualHeap(&VH);
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'A');
    printf("\ntest C before = %d\n", C);
    Print(VH, C);
    Delete(&VH, &C, 'A');

    Print(VH, C);
    return 0;
}