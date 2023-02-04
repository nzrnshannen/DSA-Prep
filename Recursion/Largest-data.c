#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *temp, *freeThisNode, *newNode;

void create_list(int, int);
void free_mem(struct node*);
void display_list(struct node*);
int largest_num(int, struct node*);

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	printf("Input data for your %d nodes:\n", n);
	create_list(1, n);
	
	printf("\nLinked list: ");
	display_list(head);
	struct node *largest_result=NULL;
	printf("Largest data of the list: %d", largest_num(-9999, head));
	free_mem(head);
	
	return 0;
}

void create_list(int i, int n)
{
	if(i>n)
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
		
		create_list(i+1, n);
	}
}

void free_mem(struct node *clear)
{
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}

void display_list(struct node* print_data)
{
	if(print_data==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		display_list(print_data=print_data->next_ptr);
	}
}

int largest_num(int maximum, struct node *find_largest)
{
	if(find_largest==NULL)
	{
		printf("\n");
		return maximum;
	}
	else
	{
		if(find_largest->data > maximum)
		{
			maximum=find_largest->data;
		}
	}
	
	return largest_num(maximum, find_largest=find_largest->next_ptr);
}