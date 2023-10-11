/*
    Name: Shannen T. Nazareno

    The program is all about the union and intersection of two lists, both sorted
    and unsorted. In this program, unique elements are only stored for both 
    union and intersection.
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
int allocSpace(VirtualHeap *VH);
void InitList(CLIST *C);
void InitVirtualHeap(VirtualHeap *VH);
void Insert(VirtualHeap *VH, CLIST *C, char elem);
void Print(VirtualHeap VH, CLIST C);
bool checkIfSorted(VirtualHeap VH, CLIST C);
void unionSorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B);
void intersectionSorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B);
void unionUnsorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B);
void intersectionUnsorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B);
bool checkIfPresentUnion(char elem, int size, char unionArr[]);
bool checkIfPresentIntersection(VirtualHeap VH, CLIST C, char elem);
void intersectionUnsorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B);

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

bool checkIfPresentUnion(char elem, int size, char unionArr[])
{
    int x;
    for(x=0; x<size+1 && elem!=unionArr[x]; x++){}
    return (elem==unionArr[x]);
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
        printf("Cannot inserted element %c anymore.\n\n", elem);
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

bool checkIfSorted(VirtualHeap VH, CLIST C)
{
    int x;
    for(x=C; VH.Nodes[x].link!=VH.Avail && VH.Nodes[x].elem <= VH.Nodes[x+1].elem; x=VH.Nodes[x].link){}

    return (VH.Nodes[x].link==VH.Avail);
}

void unionSorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B)
{
    if(isEmpty(A) || isEmpty (B))
    {
        emptyListMsg();
    }
    else if(!checkIfSorted(VHone, A) || !checkIfSorted(VHtwo, B))
    {
        printf("\n\t>> Unsorted list\\s! <<\n");
        //trigger unionUnsorted
        unionUnsorted(VHone, VHtwo, A, B);
    }
    else
    {
        int x, y, z;
        char unionArr[MAX*2];
        z=0;
        for(x=A, y=B; x!=VHone.Avail&& y!=VHtwo.Avail; )
        {
            if(VHone.Nodes[x].elem < VHtwo.Nodes[y].elem)
            {
                if(!checkIfPresentUnion(VHone.Nodes[x].elem, z, unionArr))
                    unionArr[z++]=VHone.Nodes[x].elem;
                x=VHone.Nodes[x].link;
            }
            else if(VHtwo.Nodes[y].elem < VHone.Nodes[x].elem)
            {
                if(!checkIfPresentUnion(VHtwo.Nodes[y].elem, z, unionArr))
                    unionArr[z++]=VHtwo.Nodes[y].elem;
                y=VHtwo.Nodes[y].link;
            }
            else
            {
                if(!checkIfPresentUnion(VHtwo.Nodes[x].elem, z, unionArr))
                    unionArr[z++]=VHtwo.Nodes[y].elem;
                x=VHone.Nodes[x].link;
                y=VHtwo.Nodes[y].link;
            }
        }

        if(x==VHone.Avail)
        {
            for(; y!=VHtwo.Avail; y=VHtwo.Nodes[y].link)
            {
                if(!checkIfPresentUnion(VHtwo.Nodes[y].elem, z, unionArr))
                {
                    unionArr[z++]=VHtwo.Nodes[y].elem;
                }
            }
        }

        if(y==VHtwo.Avail)
        {
            for(; x!=VHone.Avail; x=VHone.Nodes[x].link)
            {
                if(!checkIfPresentUnion(VHone.Nodes[x].elem, z, unionArr))
                {
                    unionArr[z++]=VHone.Nodes[x].elem;
                }
            }
        }

        printf("\n===========================\nUnion of two sorted lists: ");
        int i;
        for(i=0; i<z; i++)
            printf("%c ", unionArr[i]);
        printf("\n\n");
    }
}

void unionUnsorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyListMsg();
    }
    else
    {
        char unionArr[MAX*2];
        int x, y, z;
        z=0;
        for(x=A; x!=VHone.Avail; x=VHone.Nodes[x].link)
        {
            if(!checkIfPresentUnion(VHone.Nodes[x].elem, z, unionArr))
            {
                unionArr[z++]=VHone.Nodes[x].elem;
            }
        }

        for(y=B; y!=VHtwo.Avail; y=VHtwo.Nodes[y].link)
        {
            if(!checkIfPresentUnion(VHtwo.Nodes[y].elem, z, unionArr))
            {
                unionArr[z++]=VHtwo.Nodes[y].elem;
            }
        }

        printf("\n===============================\nUnion of two unsorted lists: ");
        int i;
        for(i=0; i<z; i++)
            printf("%c ", unionArr[i]);
        
        printf("\n");
    }   
}

void intersectionSorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyListMsg();
    }
    else if(!checkIfSorted(VHone, A) || !checkIfSorted(VHtwo, B))
    {
        printf("\n>> \tUnsorted list\\s! <<\n");
        //trigger intersectionUnsorted

    }
    else
    {
        int x, y;
        VirtualHeap VH;
        CLIST C;
        InitList(&C);
        InitVirtualHeap(&VH);

        for(x=A, y=B; x!=VHone.Avail && y!=VHtwo.Avail; )
        {
            if(VHone.Nodes[x].elem < VHtwo.Nodes[y].elem)
            {
                x=VHone.Nodes[x].link;
            }
            else if(VHtwo.Nodes[y].elem < VHone.Nodes[x].elem)
            {
                y=VHtwo.Nodes[y].link;
            }
            else
            {
                if(!checkIfPresentIntersection(VH, A,  VHone.Nodes[x].elem))
                {
                    Insert(&VH, &C, VHone.Nodes[x].elem);
                }
                x = VH.Nodes[x].link;
                y = VH.Nodes[y].link;
            }

        if(isEmpty(C))
        {
            printf("\n\n\tNo intersection between two lists!\n\n");
        }
        else
        {
            printf("\n=========================================================\nIntersection of two sorted lists: ");
            Print(VH, C);
        }
      }
    }
}

bool checkIfPresentIntersection(VirtualHeap VH, CLIST C, char elem)
{
    int x;
    for(x=C; x!=VH.Avail && VH.Nodes[x].elem!=elem; x=VH.Nodes[x].link){}

    return (VH.Nodes[x].elem==elem);
}

void intersectionUnsorted(VirtualHeap VHone, VirtualHeap VHtwo, CLIST A, CLIST B)
{
    if(isEmpty(A) || isEmpty(B))
    {
        emptyListMsg();
    }
    else
    {
        VirtualHeap VH;
        CLIST C;
        InitList(&C);
        InitVirtualHeap(&VH);
        int x;
        for(x=A; x!=VHone.Avail; x=VH.Nodes[x].link)
        {
            if(checkIfPresentIntersection(VHtwo, B, VHone.Nodes[x].elem))
            {
                if(C!=-1)
                {
                    if(!checkIfPresentIntersection(VH, C, VHone.Nodes[x].elem))
                    {
                        Insert(&VH, &C, VHone.Nodes[x].elem);
                    }
                }
                else
                {
                    Insert(&VH, &C, VHone.Nodes[x].elem);
                }
            }
        }

        if(isEmpty(C))
        {
            printf("\n\n\tNo intersection between two lists!\n\n");
        }
        else
        {
            printf("\n==================================================================\nIntersection of two lists: ");
            Print(VH, C);
        }
    }
}

int main()
{
    VirtualHeap VH_one;
    CLIST C1;
    InitList(&C1);
    InitVirtualHeap(&VH_one); 
    Insert(&VH_one, &C1, 'D');
    Insert(&VH_one, &C1, 'A');
    Insert(&VH_one, &C1, 'D');
    Insert(&VH_one, &C1, 'E');

    VirtualHeap VH_two;
    CLIST C2;
    InitList(&C2);
    InitVirtualHeap(&VH_two);
    Insert(&VH_two, &C2, 'D');
    Insert(&VH_two, &C2, 'H');
    Insert(&VH_two, &C2, 'A');
    Insert(&VH_two, &C2, 'C');

    Print(VH_one, C1);
    Print(VH_two, C2);

    intersectionUnsorted(VH_one, VH_two, C1, C2);
    
    return 0;
}