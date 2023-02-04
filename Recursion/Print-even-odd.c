#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prv_addr;
	struct node *nxt_addr;
};

struct node *head, *tail, *newNode, *freeThisNode, *clear;
void fill_gaps(int, int, int);
void create_list(int);
void display_list(struct node*);
void display_even(struct node*);
void display_odd(struct node*);
void release_mem();

int main()
{
	head=tail=NULL;
	
	int input_starting, input_ending;
	printf("Enter a starting point: ");
	scanf("%d", &input_starting);
	printf("Enter an ending point: ");
	scanf("%d", &input_ending);
	
	if(input_ending<input_starting)
	{
		printf("\nSwapping two values for this program...\n");
		int swap;
		swap=input_ending;
		input_ending=input_starting;
		input_starting=swap;
	}
	
	int diff=input_ending-input_starting;
	
	if(diff>1)
	{
		fill_gaps(input_starting, 1, diff);
	}
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->nxt_addr=newNode->prv_addr=NULL;
	newNode->data=input_starting;
	
	head->prv_addr=newNode;
	newNode->nxt_addr=head;
	head=newNode;
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->nxt_addr=newNode->prv_addr=NULL;
	newNode->data=input_ending;
	
	tail->nxt_addr=newNode;
	newNode->prv_addr=tail;
	tail=newNode;
	
	printf("\nLinked list: ");
	display_list(head);
	
	printf("\n\n---\nEven: ");
	display_even(head);
	
	release_mem();
	return 0;
}

void fill_gaps(int next, int j, int diff)
{
	int result;
	
	if(j>=diff)
	{
		return;	
	}
	else
	{
		result=next+j;
		create_list(result);
		return fill_gaps(next, j+1, diff);
	}
}

void create_list(int data_result)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->prv_addr=newNode->nxt_addr=NULL;
	newNode->data=data_result;
	
	if(head==NULL)
	{
		head=tail=newNode;
	}
	else
	{
		tail->nxt_addr=newNode;
		newNode->prv_addr=tail;
		tail=newNode;
	}
}

void display_list(struct node *traverse)
{
	if(traverse==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", traverse->data);
		return display_list(traverse=traverse->nxt_addr);
	}
}

void display_even(struct node *print_even)
{
	if(print_even==NULL)
	{
		printf("\nOdd: ");
		return display_odd(head);
	}
	else
	{
		if(print_even->data%2==0)
		{
			printf("%d ", print_even->data);
		}
		
		return display_even(print_even=print_even->nxt_addr);
	}
}

void display_odd(struct node *print_odd)
{
	if(print_odd==NULL)
	{
		return;
	}
	else
	{
		if(print_odd->data%2==1)
		{
			printf("%d ",print_odd->data);
		}
		
		return display_odd(print_odd=print_odd->nxt_addr);
	}
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->nxt_addr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
	
	return;
}