#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
};

struct node *head, *tail, *newNode, *freeThisNode, *clear;

void createList(int);
void displayList(struct node*);
void release_mem();

int main()
{
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	createList(n);
	
	printf("Linked list: ");
	displayList(head);
	
	free(head);
	free(tail);
	free(newNode);
	
	head=tail=newNode=NULL;

	release_mem();
	
	return 0;
}

void createList(int n)
{
	head=NULL;
	int i;
	printf("Input data for your %d nodes:\n", n);
	for(i=1; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_ptr=newNode->prev_ptr=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next_ptr=newNode;
			newNode->prev_ptr=tail;
			tail=newNode;
		}
	}
	
	printf("\n");
}

void displayList(struct node *print)
{
	
	if(print==NULL)
	{
		free(print);
		print=NULL; //?
		return;
	}
	else
	{
		printf("%d ", print->data);
		print=print->next_ptr;
		displayList(print);
	}
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}

	return;
}