//without typedef

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*head;

void InsertAtHead(int); //insert at beginning
void InsertAtTail(int); //insert at end
void Print();
void ReversePrint();
struct Node* GetNewNode(int x);

int main()
{
    head=NULL;
    InsertAtHead(2);
    Print();
    ReversePrint(); 
    printf("\n*****\n");
    InsertAtHead(4);
    Print();
    ReversePrint(); 
    printf("\n*****\n");
    InsertAtHead(6);
    Print();
    ReversePrint(); 
    printf("\n*****\n");
    InsertAtTail(99);
    Print();
    ReversePrint();
    return 0;
}

struct Node *GetNewNode(int x) 
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->prev=newNode->next=NULL;

    return newNode;
}

void InsertAtHead(int x)
{
    struct Node *newNode = GetNewNode(x);
    if(head==NULL)
    {
        head=newNode;
        return;
    }

    newNode->next=head;
    head->prev=newNode; 
    head=newNode; 

    //the previous head node will now be the second node
    //the new node will now be the first node
    //head->prev must have the address of the new node
}

void InsertAtTail(int x)
{
    struct Node *newNode=GetNewNode(x);
    if(head==NULL) //empty list
    {
        return;
    }
    struct Node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev=temp;

}

void Print()
{
    struct Node *temp = head;
    printf("Forward: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }

    printf("\n");
}

void ReversePrint()
{
    struct Node *temp=head;
    if(temp==NULL) //list is empty == exit
        return;

    //traversing until temp is at the last node
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    //at this point, temp is now pointing at the last node

    printf("Reverse: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->prev; ///going backwards
    }

    printf("\n");
}