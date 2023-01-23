#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *traverse, *newNode, *insert;

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
	
inputPos:
	printf("\nInput a position (starting from 2): ");
	scanf("%d", &pos);
	
	if(pos==1)
	{
		printf("\n\nInput is not applicable for this program. Try a different one.\n\n");
		goto inputPos;
	}
		
	printf("\n\nEnter new data to be inserted at position [%d]: ", pos);
	scanf("%d", &new_data);
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->next_ptr = newNode->prev_ptr = NULL;
	newNode->data = new_data;
	
	printf("\n\nInserting data at the given position...\nPress any key to continue- ");
	getch();
	
	printf("\n\nBefore insertion: ");
	displayList();
	
	i=1;
	insert=head;
	while(i<pos-1)
	{
		insert=insert->next_ptr;
		i++;
	}
	
	newNode->prev_ptr = insert;
	newNode->next_ptr = insert->next_ptr;
	insert->next_ptr = newNode;
	insert->next_ptr->prev_ptr = newNode;
	
	printf("\nAfter insertion: ");
	displayList();
	
	//will add a function that will release all nodes
	
	free(head);
	free(tail);
	free(traverse);
	free(newNode);

	head=tail=traverse=insert=newNode=NULL;
	
	return 0;
	
}