//union and intersection

/*
    Name: Shannen T. Nazareno
    
    The program isn't strict about duplicating elements as lists can have
    duplicates unlike ADT Sets.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    char elem;
    struct node *link;
}nodeType, *LIST;

bool isEmpty(LIST S);
void emptyListMsg();
void errorMsg();
void Initialize(LIST *S);
void Print(LIST *S);
void Insert(LIST *S, char elem);
void makeNull(LIST *S);
void unionSorted(LIST *A, LIST *B); //performing ppn
void intersectionSorted(LIST *A, LIST *B); //performing ppn
void unionUnsorted(LIST *A, LIST *B); //performing ppn
bool checkIfSorted(LIST *S); //using ppn for checking
void intersectionUnsorted(LIST *A, LIST *B); //performing ppn

bool isEmpty(LIST S)
{
    return (S==NULL);
}

void emptyListMsg()
{
    printf("\n\n\tList is empty!\n\n");
}

void errorMsg()
{
    printf("\n\n\tMemory allocation failure.\n\n");
    //call makeNull()
    exit(1);
}

void Initialize(LIST *S)
{
    *S=NULL;
}

void Print(LIST *S)
{
    if(isEmpty(*S))
    {
        emptyListMsg();
    }
    else
    {
        printf("\n-----\nList: ");
        LIST *p;
        for(p=S; (*p)!=NULL; p=&(*p)->link)
            printf("%c ", (*p)->elem);
        
        printf("\n");
    }
}

void Insert(LIST *S, char elem)
{
    LIST newNode = (LIST)malloc(sizeof(nodeType));
    if(newNode==NULL)
    {
        errorMsg();
    }
    else
    {
        newNode->elem=elem;
        newNode->link=NULL;
        if(*S==NULL)
        {
            *S = newNode;
        }
        else
        {
            LIST *trav;
            for(trav=S; (*trav)!=NULL; trav=&(*trav)->link){}

            (*trav) = newNode;
        }
    }
}

void makeNull(LIST *S)
{
    LIST temp;
    while(*S!=NULL)
    {
        temp=*S;
        *S = (*S)->link;
        free(temp);
    }

    *S = temp = NULL;
    printf("\n\n\tMemory freed.\n\n");
}

bool checkIfSorted(LIST *S)
{

    LIST *p, *n;
    for(p=S, n=&(*p)->link; *n!=NULL && (*p)->elem<=(*n)->elem; p=n, n=&(*n)->link){}

    return (*n==NULL);
}

void unionSorted(LIST *A, LIST *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyListMsg();
    }
    else if(!checkIfSorted(A) || !checkIfSorted(B))
    {
        printf("\n\n\t>> Unsorted list! <<\n\n");
        //trigger unionUnsorted()

        unionUnsorted(A, B);
    }
    else
    {   
        LIST C, *p1, *p2;
        Initialize(&C);

        for(p1=A, p2=B; (*p1)!=NULL && (*p2)!=NULL; )
        {
            if((*p1)->elem<(*p2)->elem)
            {
                Insert(&C, (*p1)->elem);
                p1=&(*p1)->link;
            }
            else if((*p2)->elem<(*p1)->elem)
            {
                Insert(&C, (*p2)->elem);
                p2=&(*p2)->link;
            }
            else
            {
                Insert(&C, (*p1)->elem);
                p1=&(*p1)->link;
                p2=&(*p2)->link;
            }
        }

        if(*p1==NULL)
        {
            for(; (*p2)!=NULL; p2=&(*p2)->link)
                Insert(&C, (*p2)->elem);
        }

        if(*p2==NULL)
        {
            for(; (*p1)!=NULL; p1=&(*p1)->link)
                Insert(&C, (*p1)->elem);
        }

        printf("\n=====\nUnion of two sorted lists: ");
        Print(&C);

        makeNull(&C);
    }
}

void unionUnsorted(LIST *A, LIST *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyListMsg();
    }
    else if(!checkIfSorted(A) || !checkIfSorted(B))
    {
        LIST C;
        LIST *p;

        Initialize(&C);

        for(p=A; (*p)!=NULL; p=&(*p)->link)
            Insert(&C, (*p)->elem);
        
        for(p=B; (*p)!=NULL; p=&(*p)->link)
            Insert(&C, (*p)->elem);
        
        printf("\n=====\nUnion of unsorted lists: ");
        Print(&C);

        makeNull(&C);
    }
}

void intersectionSorted(LIST *A, LIST *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyListMsg();
    }
    else if(!checkIfSorted(A) || !checkIfSorted(B))
    {
        printf("\n\n\t>> Unsorted list! << \n\n");
        intersectionUnsorted(A, B);
    }
    else
    {
        LIST C;
        Initialize(&C);
        LIST *p1, *p2;

        for(p1=A, p2=B; *p1!=NULL && *p2!=NULL; )
        {
            if((*p1)->elem<(*p2)->elem)
            {
                p1=&(*p1)->link;
            }
            else if((*p2)->elem<(*p1)->elem)
            {
                p2=&(*p2)->link;
            }
            else 
            {
                Insert(&C, (*p1)->elem);
                p1=&(*p1)->link;
                p2=&(*p2)->link;
            }
        }

        printf("\n=====\nIntersection of two sorted lists: ");
        Print(&C);
        makeNull(&C);
    }
}

void intersectionUnsorted(LIST *A, LIST *B)
{
    if(isEmpty(*A) || isEmpty(*B))
    {
        emptyListMsg();
    }
    else if(!(checkIfSorted(A)) || !(checkIfSorted(B)))
    {
        LIST C;
        LIST *p, *t;
        Initialize(&C);

        for(p=A; *p!=NULL; p=&(*p)->link)
        {
            for(t=B; *t!=NULL; t=&(*t)->link)
            {
                if((*p)->elem==(*t)->elem)
                {
                    Insert(&C, (*t)->elem);
                }
            }
        }

        printf("\n=====\nIntersection of unsorted lists: ");
        Print(&C);

        makeNull(&C);
    }
}
int main()
{
    LIST p1, p2;
    Initialize(&p1);
    Insert(&p1, 'A');
    Insert(&p1, 'B');
    Insert(&p1, 'A');
    Print(&p1);

    Initialize(&p2);
    Insert(&p2, 'B');
    Insert(&p2, 'C');
    Insert(&p2, 'A');
    Print(&p2);

    intersectionSorted(&p1, &p2);

    makeNull(&p1);
    makeNull(&p2);

    return 0;
}