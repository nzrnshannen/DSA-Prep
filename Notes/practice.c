//pointer to pointer to node
//pointer to node
//void return type

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node *link;
}nodeType, *LIST;

void displayList(LIST);
void createList(int, LIST*);
void insertData(char, int, int*, LIST*);
void deleteData(int, int*, LIST*);
void reverseList(LIST*);

void reverseList(LIST* C)
{
    LIST prev, current, next;
    prev=NULL;
    current=*C;

    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;
        prev=current;
        current=next;
    }

    *C=prev;

    printf("\n\n\tLIST REVERSED\n\n");
}

void deleteData(int pos, int *n, LIST* B)
{
    LIST freeThisNode=*B; 
    int i=1;
    if(pos==1)
    {
        freeThisNode=*B;
        *B=(*B)->link; //use (*B) instead of *B as -> has higher precedence
    }
    else if(pos==*n)
    {
        LIST temp=*B;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }

        freeThisNode=temp->link->link;
        temp->link=NULL;
    }
    else
    {
        LIST current=*B;
        LIST nextNode;
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

    printf("\n\n\t\tDELETION SUCCESSFUL\n\n");
}

void insertData(char data, int pos, int *n, LIST *A)
{
    nodeType *newNode=(nodeType *)malloc(sizeof(nodeType));
    newNode->data=data;
    newNode->link=NULL;

    if(pos==1)
    {
        newNode->link= *A;
        *A=newNode;
    }
    else if(pos==(*n)+1)
    {
        LIST temp = *A;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=newNode;
    }
    else
    {
        LIST trav=*A;
        int i=1;
        while(i<pos-1)
        {
            trav=trav->link;
            i++;
        }

        newNode->link=trav->link;
        trav->link=newNode;
    }

    *n+=1;

    printf("\n\n\tINSERTION SUCCESSFUL\n\n");
}

void displayList(LIST print) //pointer to node
{
    printf("\n----\nLinked list: ");
    while(print!=NULL)
    {
        printf("%c ", print->data);
        print=print->link;
    }
    printf("\n");
}

void createList(int n, LIST *A)//LIST *A for pointer to pointer to node
{
    char ch;
    int i=1;
    while(i<=n)
    {
        printf("Data %d: ", i++);
        scanf(" %c", &ch);

        nodeType *newNode=(nodeType*)malloc(sizeof(nodeType));
        newNode->data=ch;
        newNode->link=NULL;

        if(*A==NULL)
        {
            *A=newNode; //pointer to pointer to node
        }
        else
        {
            LIST temp = *A; //pointer to node
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newNode;
        }
    }

    printf("\n\tData inserted.\n\n");

}

int main()
{
    LIST L=NULL; //L is the head pointer
    int n;
enterN:
    printf("Enter the number of nodes for your linked list: ");
    scanf("%d", &n);
    if(n<=0)
    {
        printf("Invalid input. Try again.\n\n");
        goto enterN;
    }

    printf("Enter data for your %d nodes\n", n);

    createList(n, &L);
    displayList(L);
    int choice;
    int menu=1;
    int pos;
    char data;

    do{
         printf("\n********************************\n[1] Display\n[2] Insert\n[3] Delete\n[4] Reverse\n\n[0] EXIT\n---\nChoice: ");
        scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("\n\t\tDISPLAY LIST\n");
        displayList(L);
        break;

        case 2: 
        printf("\n\t\tINSERT DATA\n");
        printf("-----\nEnter data to be inserted: ");
        scanf(" %c", &data);
    enterInsertPos:
        printf("\nEnter position: ");
        scanf("%d", &pos);

        if(pos<1 || pos>n+1)
        {
            printf("\n\nInvalid position. Try again.\n\n");
            goto enterInsertPos;
        }

        insertData(data, pos, &n, &L);
        break;
        case 3: 
        printf("\n\t\tDELETE DATA\n");
    enterDeletePos:
        printf("-----\nEnter position: ");
        scanf("%d", &pos);
        if(pos<1 || pos>n)
        {
            printf("\n\nInvalid position. Try again.\n\n");
            goto enterDeletePos;
        }

        deleteData(pos, &n, &L);
        break;

        case 4: 
        reverseList(&L);
        break;

        case 0: 
        menu=0;
        break;

        default: printf("\n\nInvalid choice. Try again.\n\n");
    }

    }while(menu==1);

    printf("\n================================================================\n");
    printf("\t\tPROGRAM TERMINATED\n");
    
    //free memory

    LIST temp;
    while(L!=NULL)
    {
        temp=L;
        L=L->link;
        free(temp);
    }

    return 0;
}


