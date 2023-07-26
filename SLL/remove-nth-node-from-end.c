/*
    Name: Shannen T. Nazareno
    Program: SLL program to remove the (nth) node from the end of the list.
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *freeNode;

void createList(int, int);
void displayList(struct node*);
void deleteNode(struct node*, int, int, int);
void clearFunc(struct node*);

int main()
{
	head=NULL;
	int n, i, pos;	
	printf("=== REMOVE NTH NODE FROM THE END OF LIST ===\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter data for your %d nodes\n", n);
	createList(1, n);
	printf("\n=====\nLinked list: ");
	displayList(head);
	printf("\n\n---\n");
enterPos:	
	printf("Enter position: ");
	scanf("%d", &pos);
	if(pos<0 || pos>n)
	{
		printf("\n\nInvalid input. Try again.\n\n");
		goto enterPos;
	}
	else if(pos==n)
	{
		freeNode=head;
		head=head->next;
		free(freeNode);
	}
	else
	{
		deleteNode(head, 1, n, pos);
	}
	
	printf("\n=====\nLinked list: ");
	displayList(head);
	
	clearFunc(head);
	
	return 0;
	
}

void displayList(struct node *print_ptr)
{
	if(print_ptr==NULL)
	{
		printf("\n");
	}
	else
	{
		printf("%d ", print_ptr->data);
		return displayList(print_ptr->next);
	}
}

void createList(int i, int n)
{
	if(i>n)
	{
		printf("\n\n\tList created.\n\n");
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		return createList(i+1, n);
	}
}

void deleteNode(struct node *temp, int i, int n, int pos)
{
	if(i==(n-pos))
	{
		freeNode=temp->next;
		temp->next=temp->next->next;
		free(freeNode);
		printf("\n");
	}
	else
	{
		return deleteNode(temp->next, i+1, n, pos);
	}
}

void clearFunc(struct node *clear)
{
	if(clear==NULL)
	{
		head=temp=newNode=freeNode=clear=NULL;
		return;
	}
	else
	{
		freeNode=clear;
		return clearFunc(clear->next);
		free(freeNode);
	}
}
