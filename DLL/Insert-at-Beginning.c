#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *prev_ptr;
	struct node *next_ptr;
}*head, *tail, *newNode, *temp, *clearNode, *freeNode;

int n;

void release_mem();
void displayList();

int main()
{
	int new_data;
	
	head=tail=NULL;
	printf("Enter number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data for each %d nodes:\n", n);
	for(int i=1; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_ptr = newNode->prev_ptr = NULL;
		
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
	
	displayList();
	
	printf("\n\nEnter data to be inserted at the beginning: ");
	scanf("%d", &new_data);
	
	printf("\n\nInserting node at the beginning...\nPress any key to continue- ");
	getch();
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=new_data;
	newNode->next_ptr=newNode->prev_ptr=NULL;
	
	printf("\n\nBefore insertion: ");
	displayList();
	
	newNode->next_ptr=head;
	head->prev_ptr=newNode;
	head=newNode;
	
	printf("\nAfter insertion: ");
	displayList();
	
	free(head);
	free(temp);
	free(tail);
	free(newNode);

	head=temp=tail=newNode=NULL;
	
	release_mem();
	
	return 0;
}

void displayList()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next_ptr;
	}
}

void release_mem()
{
	clearNode=head;
	while(clearNode!=NULL)
	{
		freeNode=clearNode;
		clearNode=clearNode->next_ptr;
		free(freeNode);
		freeNode=NULL;
	}

	return;
}