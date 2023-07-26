/*
	Name: Shannen T. Nazareno
	Program: SLL program to create and reorder a (singly) list placing all 
				even-numbered nodes ahead of all odd-numbered nodes
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *freeNode;

void createList(int, int);
void displayList(struct node*);
void clearFunc(struct node*);
void separateFunc(struct node*, int, struct node*, struct node*, struct node*, struct node*);


int main()
{
	int n;
	head=NULL;
	printf("=== PLACING EVEN-NUMBERED NODES AHEAD OF ODD-NUMBERED NODES ===\n");
	printf("Enter number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter data for your %d nodes\n", n);
	createList(1, n);
	
	printf("\n***\nLinked list: ");
	displayList(head);
	separateFunc(head, 1, NULL, NULL, NULL, NULL);
	
	printf("\n==========\nLinked list: ");
	displayList(head);
	
	clearFunc(head);
	
	return 0;
}

void createList(int i, int n)
{
	if(i>n)
	{
		printf("\n\n\tList created.\n\n");
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(temp==NULL)
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

void separateFunc(struct node *temp, int i, struct node* h1, struct node *h2, struct node *t1, struct node *t2)
{
	if(temp==NULL)
	{
		t2->next=h1;
		head=h2;
		printf("\n\n\tList reordered.\n\n");
		temp=t1=t2=h1=h2=NULL;
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=temp->data;
		newNode->next=NULL;
		
		if(i%2==1) //odd
		{
			if(h1==NULL)
			{
				h1=t1=newNode;
			}
			else
			{
				t1->next=newNode;
				t1=newNode;
			}
		}
		else //even
		{
			if(h2==NULL)
			{
				h2=t2=newNode;
			}
			else
			{
				t2->next=newNode;
				t2=newNode;
			}
		}
		
		return separateFunc(temp->next, i+1, h1, h2, t1, t2);
	}
}

void clearFunc(struct node *clear)
{
	if(clear==NULL)
	{
		head=temp=newNode=clear=freeNode=NULL;
		return;
	}
	else
	{
		freeNode=clear;
		return clearFunc(clear->next);
		
		free(freeNode);
	}
}
