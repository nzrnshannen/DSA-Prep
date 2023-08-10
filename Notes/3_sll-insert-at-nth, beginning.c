//sll: insert node at the nth position

#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node* head; //global variable

void Insert(int data, int n); //int n -> pos
void Print();

int main()
{
	head=NULL; //list is empty
	Insert(2, 1); //list: 2 (single node)
	Insert(3, 2); //List: 2, 3 (insert at nth)
	Insert(4, 1); //List: 4, 2, 3 (insert at beginning)
	Insert(5, 2); //List: 4, 5, 2, 3 (insert at nth)
	Print();
	
	return 0;
}

void Insert(int data, int n)
{
	struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node)); //creating a new node
	temp1->data=data;
	temp1->next=NULL;
	
	//insert node at the beginning
	if(n==1)
	{
		temp1->next=head;
		head=temp1; 
		return; //will return once done (insert at nth function which is located below of this if statement won't be executed)
	}
	
	//insert at nth
	struct Node* temp2=head; //pointer for traversal up until n-1 (position-1)
	
	for(int i=0; i<n-2; i++) //or -->  for(int i=1; i<n-1; i++)
	{
		temp2=temp2->next; //will stop once it reaches n-2 
	}
	
	temp1->next=temp2->next; //new node's link part will be referencing to the link part of temp2 (IMPORTANT!!)
	temp2->next=temp1; //temp2 will be referencing to the new node
	
	/*
		NOTES:
	1. Make a link first using the new node. Always start at the right (new node)
	2. Make a link using the pointer for traversal (temp2)
	
	This is done in order to NOT lose the reference of the nodes at the right of the existing node at the list that's currently been pointed by temp2!
	
	*/
}

void Print()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
}