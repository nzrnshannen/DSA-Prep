//singly linked list implementation: create, display, insert at end

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
}*A, *temp;

int main()
{
	A=NULL; //list is empty
	temp=(struct Node*)malloc(sizeof(struct Node)); //creating a node
	temp->data=2;
	temp->link=NULL;
	A=temp; //temp pointing to the first node now
	
	//adding second node
	temp=(struct Node*)malloc(sizeof(struct Node)); //creating the second node
	
	//pointer A was pointing to the first node so we'll not worry about that
	
	temp->data=4;
	temp->link=NULL;
	
	struct Node *temp1 = A; //temp1 for traversal and inserting node at the end
	
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	
	temp1->link=temp; //linking the first and second node
	
	//inserting the third node
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=6;
	temp->link=NULL;
	
	temp1=A;
	while(temp1->link!=NULL)
	{
		temp1=temp1->link;
	}
	temp1->link=temp; //temp1 is pointing at the 2nd node and the temp at the 3rd node
	
	//printing the list
	
	temp1=A;
	
	while(temp1!=NULL)
	{
		printf("%d ", temp1->data);
		temp1=temp1->link;
	}
	
	while(A!=NULL)
	{
		temp1=A;
		A=A->link;
		free(temp1);
	}
	
	return 0;
	
}

