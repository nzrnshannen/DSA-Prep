/*
	Name: Shannen T. Nazareno
	Program: SLL Program to remove elements in odd indices (2nd version)
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
}*head, *temp, *newNode, *clear, *freeNode;

void createList(int i);
void displayList(struct node*);
void removeFunc(int, struct node*, struct node*);
void clearFunc();

int n;
int main()
{
	head=NULL;
	printf("===== REMOVE ELEMENTS WITH ODD INDICES =====\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInvalid input. Try again.\n\n");
		
	}
	printf("\n***\nEnter data for your %d nodes\n", n);
	createList(1);
	printf("\n---\nLinked list before removing elements: ");
	displayList(head);
	removeFunc(1, head, head->next);
	printf("\nLinked list after removing elements: ");
	displayList(head);
	clearFunc();
	
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
		newNode->next=NULL;
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		
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

void removeFunc(int i, struct node* current, struct node *nextNode)
{
	if(nextNode==NULL)
	{
		current=nextNode=NULL;
		return;
	}
	else
	{
		if(i%2==0)
		{
			current->next=nextNode->next;
			return removeFunc(i+1, nextNode, nextNode->next);
		
		}
		else
		{
			freeNode=current;
			current=nextNode;
			nextNode=nextNode->next;
			free(freeNode);
			
			if(i==1)
			{
				head=current;
			}
			return removeFunc(i+1, current, nextNode);
			
		}
	}
}

void clearFunc()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next;
		free(freeNode);
	}
	
	head=temp=newNode=clear=freeNode=NULL;
}