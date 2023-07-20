/*
	Name: Shannen T. Nazareno
	Program: An SLL Program that removes elements with odd indices (1st version)
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *clear, *freeNode;

void createList(int);
void displayList(struct node*);
void clearFunc();

int n;
int main()
{
	head=NULL;	
	printf("===== REMOVE ELEMENTS WITH ODD INDICES =====\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);

	createList(1);
	printf("=====\nLinked list: ");
	displayList(head);
}

void createList(int i)
{
	int data;
	
	if(i>n)
	{
		printf("\n\n\tList created.\n\n");
	}
	else
	{
		printf("Data %d: ", i);
		scanf("%d", &data);
		if(i%2==0)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=data;
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
		
		}
		
		return createList(i+1);
	}
}

void displayList(struct node* print)
{
	if(print==NULL)
	{
		clearFunc();
	}
	else
	{
		printf("%d ", print->data);
		
		return displayList(print->next);
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
	
	head=temp=newNode=freeNode=clear=NULL;
}
