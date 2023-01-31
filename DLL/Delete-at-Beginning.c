#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *traverse, *newNode, *freeThisNode, *clear;

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
}
void displayList()
{
	traverse=head;
	
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
}

int main()
{
	head=NULL;
	
	int i=1, n, new_data, pos;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("\nEnter %d data: \n", n);
	
	for(i; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_ptr = newNode->prev_ptr = NULL;
		
		if(head==NULL)
			head=tail=newNode;
		else
		{
			tail->next_ptr=newNode;
			newNode->prev_ptr=tail;
			tail=newNode;
		}
	}
	
	printf("\nLinked list: ");
	displayList();
	
	
	printf("\n\nDeleting node at the beginning...\nPress any key to continue- ");
	getch();
	
	printf("\n\nBefore deletion: ");
	displayList();
	
	freeThisNode=head;
	head=head->next_ptr;
	free(freeThisNode);
	
	printf("\nAfter deletion: ");
	displayList();
	
	release_mem();
	//code would be redundant:
	free(head);
	free(tail);
	free(newNode);
	free(traverse);

	head=tail=newNode=traverse=NULL;
	
	return 0;
	
}