#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *traverse, *newNode, *freeThisNode, *delete_ptr;

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
	
	int i=1, n, pos;
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

enterPos:
	printf("\n\nEnter position (starting from 2): ");
	scanf("%d", &pos);
	
	if(pos<=1)
	{
		printf("\n\nInput not applicable for this program. Try a different one.\n\n");
		goto enterPos;
	}
	
	printf("\n\nDeleting node at the given position [%d]...\nPress any key to continue- ", pos);
	getch();
	
	printf("\n\nBefore deletion: ");
	displayList();
	
	i=1;
	delete_ptr=head;
	
	while(i<pos)
	{
		delete_ptr=delete_ptr->next_ptr;
		i++;
	}
	
	freeThisNode=delete_ptr;
	delete_ptr->next_ptr->prev_ptr = delete_ptr->prev_ptr;
	delete_ptr->prev_ptr->next_ptr = delete_ptr->next_ptr;
	free(freeThisNode);
	
	printf("\nAfter deletion: ");
	displayList();
	
	//will add a function that would delete all nodes
	
	free(head);
	free(tail);
	free(newNode);
	free(delete_ptr);
	free(traverse);
	head=tail=newNode=delete_ptr=traverse=NULL;
	return 0;
	
}