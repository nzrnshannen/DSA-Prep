//pointer to node
//return type LIST 

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *link;
}nodeType, *LIST;

LIST createList(LIST, int);
LIST insertFunc(LIST, int*, int, int); //list, n, position, data
LIST deleteFunc(LIST, int*, int); //list, n, position
LIST reverseFunc(LIST);

void displayList(LIST);
void errorMsg();

int main()
{
    LIST L;
    L=NULL;

    int n;

inputN:
    printf("Enter the number of nodes for your linked list: ");
    scanf("%d", &n);

    if(n<=0)
    {
        errorMsg();
        goto inputN;
    }

    printf("Enter data (integer value) for your %d nodes\n", n);
    L = createList(L, n);

    int choice, data, pos;
    int menu=1;
    do{
        printf("\n============================\n");
        printf("[1] Display\n[2] Insert\n[3] Delete\n[4] Reverse\n\n[0] EXIT\n---\nChoice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            displayList(L);
            break;

            case 2: 
            printf("\n-- INSERTION --\n");
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
        enterInsertPos:
            printf("Enter a position: ");
            scanf("%d", &pos);
            if(pos<=0 || pos>n+1)
            {
                errorMsg();
                goto enterInsertPos;
            }
            L=insertFunc(L, &n, pos, data);
            break;

            case 3: 
            printf("\n-- DELETION --\n");
        enterDeletePos:
            printf("Enter a position: ");
            scanf("%d", &pos);
            if(pos<=0 || pos>=n+1)
            {
                errorMsg();
                goto enterDeletePos;
            }

           L=deleteFunc(L, &n, pos);
            break;  

            case 4: 
            L=reverseFunc(L);
            break;

            case 0: 
            menu=0;
            break;

            default: errorMsg(); break;
        }
    }while(menu);

    printf("\n********************************\n\tPROGRAM TERMINATED\n\n");
    LIST temp = L;
    
    while(L!=NULL)
    {
        temp=L;
        L=L->link;
        free(temp);
    }

    return 0;

}

LIST createList(LIST A, int n)
{
    int i=1;
    int data;

    while(i<=n)
    {
        printf("Data %d: ", i++);
        scanf("%d", &data);
        nodeType *newNode=(nodeType*)malloc(sizeof(nodeType));
        if(newNode==NULL)
        {
            printf("Memory allocation error");
            exit(1);
        }

        newNode->data = data;
        newNode->link=NULL;
        
        if(A==NULL)
        {
            A=newNode;
        }
        else
        {
            LIST temp=A;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newNode;
        }
    }

    printf("\n\tList created.\n\n");
    displayList(A);
    return A;
}

void displayList(LIST P)
{
    printf("\n-----\nLinked list: ");
    while(P!=NULL)
    {
        printf("%d ", P->data);
        P=P->link;
    }

    printf("\n\n");
}

void errorMsg()
{
    printf("\n\n\tInvalid input. Try again.\n\n");
}

LIST insertFunc(LIST A, int *n, int pos, int data)
{
    nodeType *newNode=(nodeType *)malloc(sizeof(nodeType));
    newNode->data=data;
    newNode->link=NULL;

    if(pos==1)
    {
        newNode->link=A;
        A=newNode;
    }
    else if(pos==(*n)+12)
    {
        LIST temp = A;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newNode;
    }
    else
    {
        int i=1;
        LIST trav = A;
        while(i<pos-1)
        {
            trav = trav->link;
            i++;
        }

        newNode->link=trav->link;
        trav->link=newNode;
    }

    *n+=1;

    printf("\n\n\tINSERTION SUCCESSFUL\n");
    return A;
}

LIST deleteFunc(LIST B, int *n, int pos)
{
    LIST freeThisNode;

    if(pos==1)
    {
        freeThisNode = B;
        B=B->link;
    }
    else if(pos==*n)
    {
        LIST trav = B;
        while(trav->link->link!=NULL)  
        {
            trav=trav->link;
        }

        freeThisNode = trav->link;
        trav->link=NULL;
    }
    else
    {
        LIST current = B;
        LIST nextNode;
        int i=1;
        while(i<pos-1)
        {
            current=current->link;
            i++;
        }   
        nextNode=current->link;
        current->link=nextNode->link;
        freeThisNode=nextNode;
    }

    free(freeThisNode);
    *n-=1;

    printf("\n\n\tDELETION SUCCESSFUL\n");
    return B;
}

LIST reverseFunc(LIST C)
{
    LIST prev, current, nextNode;
    current=C;
    prev=NULL;

    while(current!=NULL)
    {
        nextNode=current->link;
        current->link=prev;
        prev=current;
        current=nextNode;
    }

    C=prev;

    printf("\n\n\tLink reversed.\n\n");
    return C;
}