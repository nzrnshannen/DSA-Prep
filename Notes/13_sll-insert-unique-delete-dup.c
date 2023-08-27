//insert unique elem
//delete occurrences

/*

Delete all occurrences
[TEST CASES]

a) A A A A A = list is empty /
b) A B A C C = B / 
c) A B A B A = list is empty /
d) A B C D E = "no occurrences in the list" /
e) B A A A A /
f) B A A C E /

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    char data;
    struct Node *link;
}nodeType, *LIST;

void errorMsg();
void Print(LIST P);

void InsertUniqueElem(char data, LIST *B);
void clearList(LIST *C);
void DeleteOccurrences(LIST *D);
void DeleteSpecificElem(char elem, LIST *E);

int main()
{
    LIST L = NULL; //empty list
    int n;
inputN:
    printf("Input the number of nodes for your linked list: ");
    scanf("%d", &n);
    if(n<=0)
    {
        errorMsg();
        goto inputN;
    }

    printf("\n****\nEnter data (character type) for your %d nodes \n", n);
    int i;
    char ch;
    for(i=0; i<n; i++)
    {
        printf("Data %d: ", i+1);
        scanf(" %c", &ch);

        LIST newNode = (LIST)malloc(sizeof(nodeType));
        newNode->data=ch;
        newNode->link=NULL;

        if(L==NULL)
        {
            L=newNode;
        }
        else
        {
            LIST temp = L;
            while(temp->link!=NULL) temp=temp->link;
            temp->link=newNode;
        }
    }

    printf("\n\n\tSuccessfully created a list.\n\n");
    int choice=1;
    do{
    inputChoice: 
        printf("\n===============================\n");
        printf("[1] Insert Unique Element\n");
        printf("[2] Delete Occurences\n");
        printf("[3] Delete Specific Element\n");
        printf("[4] Display List\n");
        printf("[5] Create New List");
        printf("\n\n[0] EXIT");
        printf("\n---\nChoice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
            char newElem;
            printf("\n -- INSERT UNIQUE ELEMENT --\n");
            printf("Enter an element to be inserted at the end of the list: ");
            scanf(" %c", &newElem);
            
            InsertUniqueElem(newElem, &L);
            break;

            case 2: 
            if(L==NULL)
                printf("\n\n\tCreate a list first!\n\n");
            else
                DeleteOccurrences(&L);
            break;

            case 3: 

            if(L==NULL)
                printf("\n\n\tCreate a list first!\n\n");
            else
            {
                char specificElem;
                printf("\n -- DELETE SPECIFIC ELEMENT --\n");
                printf("Enter an element to search: ");
                scanf(" %c", &specificElem);

                DeleteSpecificElem(specificElem, &L);
            }

            break;
            case 4:
            if(L==NULL)
                printf("\n\n\tCreate a list first!\n\n");
            else
                Print(L);
            break;

            case 5: 
            int confirm;
        inputConfirmation:
            printf("\n\nCreating a new list requires deleting the existing list.\nDo you wish to continue?\n");
            printf("[1] Yes\n[2] No\n---\nChoice: ");
            scanf("%d", &confirm);

            switch(confirm)
            {
                case 1: clearList(&L); goto inputN; break;
                case 2: printf("\n\n\tDecided not to delete the entire list.\n\n"); break;
                default: errorMsg(); goto inputConfirmation; break;
            }
            break;
            case 0: choice = 0; break;
            default: errorMsg(); goto inputChoice; break;
        }
    }while(choice);

    clearList(&L);

    printf("\n********************************\n\tPROGRAM TERMINATED\n");

    return 0;
}

void errorMsg()
{
    printf("\n\n\tInvalid input. Try again.\n\n");
}

void Print(LIST P)
{
    printf("\n=====\nLinked List: ");
    LIST trav = P;
    while(trav!=NULL)
    {
        printf("%c ", trav->data);
        trav=trav->link;
    }

    printf("\n");
}

void InsertUniqueElem(char elem, LIST *A)
{
    for(LIST trav = *A; trav!=NULL; trav=trav->link)
    {
        if(trav->data == elem)
        {
            break;
        }
            
        if(trav->link==NULL)
        {
            LIST newNode = (LIST)malloc(sizeof(nodeType));
            newNode->data=elem;
            newNode->link = NULL;
            trav->link=newNode;
        }
         printf("\n\n\tElement inserted.\n\n");
     }
}

void DeleteOccurrences(LIST *D)
{
    int flag;
    int checkOccPresent=0;
    LIST key = *D;
    while(key!=NULL) 
    {
        flag=0;
        LIST curr=key;
        LIST next = key->link;
        while(next!=NULL)
        {
            if(next->data==key->data)
            {
                checkOccPresent=1;
                flag=1;
                LIST freeNode=next;
                curr->link=next->link;
                next=next->link;
                free(freeNode);
            }
            else
            {
                curr=next;
                next=next->link;
            }
        }

        if(flag==1)
        {
            //delete node at the beginning
            if(key == *D) //if key is at the first node and first node needs to be deleted
            {
                LIST freeNode=key;
                (*D) = (*D)->link;
                key = *D;
                free(freeNode);
            }
            else
            {
                //delete node at the nth, delete node at the end
                LIST trav;
                for(trav=*D; trav->link!=key; trav=trav->link){}

                trav->link=key->link; //build link because we are deleting the node that's pointing to next to the (key) node
                free(key);
                key=trav->link; //maintain reference (will be used in the next iteration: checking if new key has occurrences)
            }

        }
        else
            key=key->link; //move to the next node if no occurrences found
    }


    if(checkOccPresent==0)
        printf("\n\n\tNo occurrences found on the list.\n");
    else
        if(*D==NULL)
            printf("\n\n\t>> List is now empty. <<\n");   
        else
            printf("\n\n\tDeleted occurrences.\n\n");
}

void DeleteSpecificElem(char elem, LIST *E)
{
    int flag=0;
    LIST curr, prev;
    curr = *E;
    LIST freeNode;

    while(curr!=NULL)
    {
        if(curr->data!=elem)
        {
            curr=curr->link;
        }
        else
        {
            flag=1;
            if(curr==(*E))
            {
                freeNode=curr;
                *E = (*E)->link;
                curr=*E;

                if(curr->link==NULL)
                {
                    printf("\n\n\t>> List is now empty <<\n\n");
                }

                free(freeNode);
            }
            else
            {
                for(prev=*E; prev->link!=curr; prev=prev->link){}
                freeNode=curr;
                prev->link=curr->link;
                curr=curr->link;
                free(freeNode);
            }
        }
    }

    if(flag==1)
    {
        printf("\n-----\nElement deleted.\n");
    }
    else
    {
        printf("\n-----\nElement is not on the list.\n");
    }
}

void clearList(LIST *C)
{
    while(*C!=NULL)
    {
        LIST temp = *C;
        *C = (*C)->link;
        free(temp);
        temp=NULL;
    }

    printf("\n\n\t >> LIST CLEARED <<\n\n");
}