#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev_ptr;
	struct node *next_ptr;
}*head, *temp, *newNode, *traverse, *tail;

void displayList();
int findMaximum();

int main()
{
	head=NULL;
	int i=1, n;
	
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
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
	
	printf("\nLinked list: ");
	displayList();
	
	int result=findMaximum();
	
	printf("Maximum data found in the DLL is: %d", result);
	
	free(head);
	free(temp);
	free(traverse);
	free(newNode);
	free(tail);
	
	head=temp=traverse=newNode=tail=NULL;
	
	return 0;
}

void displayList()
{
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
	printf("\n\n");
}

int findMaximum()
{
	int max=-9999;
	
	for(temp=head; temp!=NULL; temp=temp->next_ptr)
	{
		if(temp->data > max)
			max=temp->data;
	}
	
	return max;
}