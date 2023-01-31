#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
};

struct node *head, *tail, *newNode, *clear, *freeThisNode;

void release_mem();
void create_nodes(int, int);
void display_list(struct node*);
int sum_of_nodes(struct node*, int);

int main()
{
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	printf("Input data for your %d nodes:\n", n);
	create_nodes(1, n);
	printf("\nLinked list: ");
	display_list(head);
	
	printf("\nSum of all nodes: %d", sum_of_nodes(head, 0));
	
	release_mem();
	
	return 0;
}

void create_nodes(int i, int num_of_nodes)
{
	if(i>num_of_nodes)
	{
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->prev_ptr=newNode->next_ptr=NULL;
		
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
	
	create_nodes(i+1, num_of_nodes);
}

void display_list(struct node *temp)
{
	if(temp==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", temp->data);
		display_list(temp=temp->next_ptr);
	}
}

int sum_of_nodes(struct node *add, int sum)
{
	if(add==NULL)
	{
		return sum;
	}
	else
	{
		sum+=add->data;
		sum_of_nodes(add=add->next_ptr, sum);
	}
}

void release_mem()
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