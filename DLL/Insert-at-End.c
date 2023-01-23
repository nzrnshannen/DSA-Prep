#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *traverse, *newNode;

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
	
	int i=1, n, new_data;
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
	
	printf("\n\nEnter new data to be inserted at the end: ");
	scanf("%d", &new_data);
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=new_data;
	newNode->next_ptr = newNode->prev_ptr=NULL;
	
	printf("\n\nInserting data at the end...\nPress any key to continue- ");
	getch();
	
	printf("\n\nBefore insertion: ");
	displayList();
	
	newNode->prev_ptr=tail;
	tail->next_ptr=newNode;
	tail=newNode;
	
	printf("\nAfter insertion: ");
	displayList();
	
	//will add a function that will release all nodes
	
	free(head);
	free(tail);
	free(traverse);
	free(newNode);

	head=tail=traverse=newNode=NULL;
	
	return 0;
	
}