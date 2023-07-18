/*
	Name: Shannen T. Nazareno
	Program: an SLL program for converting (SLL) list into an array 
*/

#include<stdio.h>
#include<stdlib.h>

struct arrList{
	int data;
	struct arrList* next_addr;
}*head, *temp, *newNode, *clear, *freeNode;

void createList(int, int);
void displayList(struct arrList*);
int* traverseFunc(int[]);
void clearFunc();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter data for your %d nodes\n", n);
	createList(1, n);
	
	printf("\n===\nLinked list: ");
	displayList(head);
	
	int arr[n];
	int *ptr = traverseFunc(arr);
	
	
	printf("---\nArray: ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", *(ptr)+i);
	}
	
	clearFunc();
	
	return 0;
}

void createList(int i, int n)
{
	if(i>n)
	{
		printf("\n\n\tList created.\n\n");
	}
	else
	{
		newNode=(struct arrList*)malloc(sizeof(struct arrList));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_addr=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next_addr=newNode;
			temp=newNode;
		}

		return createList(i+1, n);
	}
}

void displayList(struct arrList *print)
{
	if(print==NULL)
	{
		printf("\n");
	}
	else
	{
		printf("%d ", print->data);
		
		return displayList(print->next_addr);
	}
}

//iterative
int *traverseFunc(int arr[])
{
	int i=0;
	
	struct arrList* traverse_ptr=head;
	
	while(traverse_ptr!=NULL)
	{
		arr[i]=traverse_ptr->data;
		i++;
		traverse_ptr=traverse_ptr->next_addr;
	}
	return arr;
}

void clearFunc()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
	
	head=temp=newNode=clear=freeNode=NULL;
}