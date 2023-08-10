//sll: delete node at nth pos (given by user)

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

/*
1. Fix the links
2. Free the space
*/

struct Node *head; //stores the first node

void Insert(int data); //insert data at the end of the list
void Print();
void Delete(int n); //delete node at position n
void clearFunc();

int main()
{
	head=NULL; //empty list
	
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5); //List: 2, 4, 6, 5
	Print();
	
	int n;
	printf("Enter a position: ");
	scanf("%d", &n);
	
	Delete(n);
	Print();
	
	clearFunc();
	
	return 0;
}

void Delete(int n)
{
	struct Node *temp1=head; //for traversal
	
	//if() statement for deleting node at the beginning
	if(n==1) //remember, temp1 is pointing at head 
	{
		head=temp1->link; //head is now pointing to the second node
		free(temp1);
		return; //for loop below if() statement won't be executed
	}
	
	for(int i=0; i<n-2; i++) //or for(int i=0; i<n-1; i++)
	{
		temp1=temp1->link; //will stop at nth-1
	}
	
	struct Node *temp2 = temp1->link; //nth node
	//temp2 will point to the node next to temp1
	//the node that's been pointed to temp2 will be deleted
	temp1->link=temp2->link;
	free(temp2);
}

void Insert(int x) //insert at end
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->link=NULL;
	
	if(head==NULL)
	{
		head=temp;
		return;
	}
	
	struct Node *temp1=head;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp;
}

void Print()
{
	struct Node *print_ptr=head;
	printf("---\nList: ");
	while(print_ptr!=NULL)
	{
		printf("%d ", print_ptr->data);
		print_ptr=print_ptr->link;
	}
	
	printf("\n\n");
}

void clearFunc() //freeing memory
{
	struct Node *temp1;
	while(head!=NULL)
	{
		temp1=head;
		head=head->link;
		free(temp1);	
	}
}