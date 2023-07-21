/*
	Name: Shannen T. Nazareno
	Program: SLL Program that removes duplicates in the list 
	
	Note: code needs revision
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *freeNode, *temp, *newNode;


void createList(int);
void displayList(struct node*);
void removeDuplicates(struct node*, struct node*, struct node*);
void removeFunc(struct node*, struct node*, struct node*);
void clearFunc(struct node*);

int n;

int main()
{
	head=NULL;
	printf("=== REMOVE DUPLICATES ===\n");

enterNo:
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInvalid input. Try again.\n\n");
		goto enterNo;
	}
	
	printf("Enter data for your %d nodes\n", n);
	createList(1);
	
	printf("-------\nLinked list beforing removing duplicates: ");
	displayList(head);
	removeDuplicates(head, head, head->next);
	
	printf("\nLinked list after removing duplicates: ");
	displayList(head);
	clearFunc(head);
	
	return 0;
}

void createList(int i)
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
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		return createList(i+1);
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


void removeDuplicates(struct node *temp, struct node *prevNode, struct node *currentNode)
{
	if(temp->next==NULL)
	{
		return;
	}
	else
	{
		prevNode=temp;
		currentNode=temp->next;
		
		//acts like an inner loop so 'return' keyword should be eliminated here
		removeFunc(temp, prevNode, currentNode);
		
		if(temp->next==NULL) //acts like a break statement
			displayList(head);
			
		return removeDuplicates(temp->next, prevNode, currentNode);
	}
}

void removeFunc(struct node*temp, struct node *prevNode, struct node *currentNode)
{
	if(currentNode==NULL)
	{
		return;
	}
	else
	{
		if(temp->data==currentNode->data)
		{
			prevNode->next=currentNode->next;
			freeNode=currentNode;
			currentNode=currentNode->next;
			free(freeNode);
		}
		else
		{
			prevNode=currentNode;
			currentNode=currentNode->next;
		}
			
		return removeFunc(temp, prevNode, currentNode);
		
	}
}

void clearFunc(struct node* clear)
{
	if(clear==NULL)
	{
		head=temp=newNode=clear=freeNode=NULL;
		printf("\n");
		return;
	}
	else
	{
		freeNode=clear;
		clearFunc(clear->next);
		free(freeNode);
	}
}
/*

Similar code (iterative):

void removeDuplicates(struct node* temp, struct node *prevNode, struct node *currentNode)
{
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		prevNode=temp;
		currentNode=temp->next;
		
		while(currentNode!=NULL)
		{
			if(temp->data == currentNode->data)
			{
				prevNode->next=currentNode->next;
				freeNode=currentNode;
				currentNode=currentNode->next;
				free(freeNode);
			}
			else
			{
				prevNode=currentNode;
				currentNode=currentNode->next;
			}
		}
		
		if(temp->next==NULL)
		{
			break;
		}
	}
}

*/

