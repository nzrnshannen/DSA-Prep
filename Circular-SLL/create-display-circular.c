//program bound to change

#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_addr;
}*head, *newNode, *temp, *freeNode, *clear;

void create_list(int, int);
void display_list(struct node*);
//void free_mem();

int main()
{
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	create_list(1, n);
	printf("\n\n---\nLinked list: ");
	display_list(head);
	
//	free_mem();
	return 0;
	
}

void display_list(struct node *print_ptr)
{
	if(print_ptr->next_addr==head)
	{
		printf("%d ", print_ptr->data);
		return;
	}
	else
	{
		printf("%d ", print_ptr->data);
		return display_list(print_ptr->next_addr);
	}
}

void create_list(int i, int n)
{
	if(i>n)
	{
		temp->next_addr=head;
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
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
		
		return create_list(i+1, n);
	}
}