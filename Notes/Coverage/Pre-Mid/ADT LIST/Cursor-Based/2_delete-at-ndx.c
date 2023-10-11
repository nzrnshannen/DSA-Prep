/*
    Name: Shannen T. Nazareno

    A program implementing deletion (with deallocSpace acting as free()).

    * needs to be reviewed
    
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX 5
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
int allocSpace(VirtualHeap* VH);
void deallocSpace(VirtualHeap *VH, int ndx);
void Insert(VirtualHeap* VH, CLIST *C, char elem);
void Delete(VirtualHeap *VH, CLIST *C, int ndx);
bool isEmpty(CLIST C);
bool isFull(VirtualHeap VH);
bool isOccupied(VirtualHeap VH, int ndx, CLIST C);
void Print(VirtualHeap VH, CLIST C);
void InitList(CLIST *C);
void InitVirtualHeap(VirtualHeap *VH);

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

int allocSpace(VirtualHeap * VH)
{
    int retVal = -1;
    if(VH->Avail!=-1)
    {
        retVal = VH->Avail;
        VH->Avail = VH->Nodes[retVal].link;
    }

    return retVal;
}

void deallocSpace(VirtualHeap *VH, int ndx)
{
    if(ndx>=0 && ndx<MAX) //redundant if() statement
    {
        VH->Nodes[ndx].link = VH->Avail;
        VH->Avail = ndx;
    }
}

bool isOccupied(VirtualHeap VH, int ndx, CLIST C)
{
    int x;
    for(x=C; x!=-1 && x!=ndx; x=VH.Nodes[x].link){}

    //If x == ndx, meaning, space has been allocated for that index
    // because one of the nodes have the value of ndx on its link part
    return(x==ndx && VH.Nodes[x].elem!='\0');
}

void Delete(VirtualHeap *VH, CLIST *C, int ndx)
{
    if(isEmpty(*C))
    {
        emptyListMsg();
    }
    else if(ndx<0 || ndx>=MAX)
    {
        printf("\n\n\tInvalid index!\n\n");
    }
    else if(!isOccupied(*VH, ndx, *C))
    {
        printf("\n\n\tNo data/Empty Space!\n\n");
    }
    else
    {
        if(ndx==*C)
        {
            *C = VH->Nodes[ndx].link;
        }
        else
        {
            int x;
            for(x=*C; VH->Nodes[x].link!=ndx; x = VH->Nodes[x].link){}
            VH->Nodes[x].link = VH->Nodes[ndx].link;
        }

        deallocSpace(VH, ndx);
        printf("\n\n\t>> Element removed. <<\n\n");
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
        int ndx;
        printf("\n-----\nList: ");
        for(ndx=C; ndx!=-1 ; ndx = VH.Nodes[ndx].link)
            printf("%c ", VH.Nodes[ndx].elem);
        
        printf("\n\n");
    }
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
        VH->Nodes[x].link = x+1;
    
    VH->Nodes[x].link = - 1;
}

void Insert(VirtualHeap *VH, CLIST *C, char elem)
{
    if(isFull(*VH))
    {
        fullListMsg();
    }
    else
    {
        int retVal = allocSpace(VH);
        if(retVal!=-1)
        {
            VH->Nodes[retVal].elem = elem;
            if(isEmpty(*C))
            {
                *C = retVal;
            }

        }
    }
}
int main()
{
    VirtualHeap VH;
    CLIST C;
    InitList(&C);
    InitVirtualHeap(&VH);
    Insert(&VH, &C, 'A');
    Insert(&VH, &C, 'B');
    Insert(&VH, &C, 'C');
    Insert(&VH, &C, 'D');
    Insert(&VH, &C, 'E');
    Delete(&VH, &C, 0);
    // Delete(&VH, &C, 0);
    Delete(&VH, &C, 1);
    Delete(&VH, &C, 2);
    Delete(&VH, &C, 3);
    Delete(&VH, &C, 4);
    Print(VH, C);
    return 0;
}