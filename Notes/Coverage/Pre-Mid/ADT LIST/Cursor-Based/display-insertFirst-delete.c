/*
    initVirtualHeap (setting the link part)
    initList
    display
    deleteElem
    insertFirst
    
    deallocSpace
    allocSpace
*/

#include<stdio.h>
#define MAX 6

typedef struct{
    char data;
    int link;
}node;

typedef struct{
    node Nodes[MAX];
    int Avail;
}VirtualHeap;

typedef int CLIST;

int allocSpace(VirtualHeap *V)
{
    int retval=-1;
    if(V->Avail!=-1)
    {
        retval = V->Avail;
        V->Avail = V->Nodes[retval].link;
    }

    return retval;
}


void initList(CLIST *C)
{
    *C = -1;
}

void initVirtualHeap(VirtualHeap* VH) //setting the link part of Nodes
{
    int x;
    for(x=1; x<MAX; x++)
    {
        VH->Nodes[x-1].link = x;
    }   
    VH->Nodes[x-1].link = -1;
}

void deallocSpace(VirtualHeap *V, int ndx)
{
    if(ndx>=0 && ndx<MAX)
    {
        V->Nodes[ndx].link = V->Avail;
        V->Avail = ndx;
    }
}

void insertFirst(CLIST *C, char elem, VirtualHeap* V)
{
    int ndx=allocSpace(V);
    if(ndx!=-1)
    {
        V->Nodes[ndx].data = elem;
        V->Nodes[ndx].link = *C;
        *C = ndx;

        printf("\n\tElement inserted.\n");
    }
    else
    {
        printf("\n\tList is full.\n");
    }
}

void deleteElem(CLIST *C, char elem, VirtualHeap *V)
{
    if(*C!=-1)
    {
        int ndx; //int ndx = 0;
        for(ndx=*C; ndx!=-1 && V->Nodes[ndx].data!=elem; ndx = V->Nodes[ndx].link){} //locating the same elem
        if(ndx!=-1)
        {
            //using look-ahead method to set the link parts
            
            if(ndx!=*C)
            {
                int trav;
                for(trav=(*C); V->Nodes[trav].link!=ndx; trav=V->Nodes[trav].link){} //confusing somehow
                V->Nodes[trav].link = V->Nodes[ndx].link;
            }
            else
            {
                *C = V->Nodes[ndx].link;
            }

            deallocSpace(V, ndx);
            printf("\n\tElement removed.\n");
        }
        else
        {
            printf("\n\tElement does not exist.\n");
        }
    }
    else
    {
        printf("\n\tList is empty!\n");
    }
}


void display(CLIST C, VirtualHeap V)
{
    if(C!=-1)
    {
        printf("\nList: ");
        int ndx;
        for(ndx = C; ndx!=-1; ndx = V.Nodes[ndx].link)
        {
            printf("%c ", V.Nodes[ndx].data);
            // printf("%d\n\n", V.Nodes[ndx].link);
        }
        printf("\n");
    }
    else
    {
        printf("\n\tList is empty!\n");
    }
}

int main()
{
    VirtualHeap VH;
    initVirtualHeap(&VH); //setting links

    CLIST C; //head
    initList(&C); //set to -1 (meaning, list is empty)

    VH.Avail = 0; //preparing for insertFirst, first element inserted will be at index 0


    insertFirst(&C, 'A', &VH);
    insertFirst(&C, 'B', &VH);
    insertFirst(&C, 'C', &VH);
    insertFirst(&C, 'D', &VH);
    // insertFirst(&C, 'E', &VH);
    // insertFirst(&C, 'F', &VH);
  //  insertFirst(&C, 'G', &VH);
    deleteElem(&C, 'B', &VH);

    display(C, VH);

    return 0;
}



