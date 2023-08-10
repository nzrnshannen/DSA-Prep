//sll: (2) insert at beginning: local head, double pointer, return type: void 

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

void Print(struct Node*);
void Insert(struct Node**, int x);

int main()
{
	int n, i, x;
	//n = number of nodes
	//x = data to be put in the node
	
	struct Node *head;
	head=NULL; //list is empty	
	
enterN:
	printf("How many numbers would you like for your list? ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nCannot create a list. Input a different one.\n\n");
		goto enterN;
	}
	
	for(i=0; i<n; i++)
	{
		printf("Enter data: ");
		scanf("%d", &x);
		
		Insert(&head, x);
		Print(head);
	}
	
	return 0;
}

void Insert(struct Node **pointerToHead, int x)
{
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node)); //temp is used for creating data
	temp->data=x;
	temp->link=*pointerToHead; //pointerToHead at first is NULL, so the first node will always have a NULL value at the link part
	//temp is referencing to the previous node 
	
	*pointerToHead=temp; //pointerToHead now pointing to the new node inserted (head is now pointing to the new node)
}

void Print(struct Node *print_ptr)
{
	printf("---\nList is: ");
	while(print_ptr!=NULL)
	{
		printf("%d ", print_ptr->data);
		print_ptr=print_ptr->link;
	}
	
	printf("\n\n");
}