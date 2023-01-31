#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* prev_ptr;
	struct node* next_ptr;
}*head, *current, *newNode, *nextNode, *tail, *traverse, *swap, *clear, *freeThisNode;

void printList();
void reverseList();
void free_mem();

int main()
{
	head=tail=NULL;
	
	int n, i=1;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter %d data:\n", n);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
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
	
	printf("\n\nList before reversing: ");
	printList();
	reverseList();
	printf("List after reversing: ");
	printList();
	
	free_mem();
	
	free(head);
	free(traverse);
	free(newNode);
	free(nextNode);
	free(current);
	free(tail);
	free(swap);
	
	head=tail=newNode=nextNode=current=traverse=swap=NULL;
	
	return 0;
}

void printList()
{
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
	printf("\n");
}

void reverseList()
{
	current=head;
	while(current!=NULL)
	{
		nextNode=current->next_ptr;
		current->next_ptr=current->prev_ptr;
		current->prev_ptr=nextNode;
		current=nextNode;
	}
	
	swap=head;
	head=tail;
	tail=swap;
	
}

void free_mem()
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